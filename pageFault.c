//os6 page fault

//os lab page replacement Algorithm

//https://github.com/18520339/operating-system-lab.git

//fifo.c

#include "PRA.c"

void StartFIFO(PRA *const self)
{
    for (int i = 0; i < self->total_pages; ++i)
    {
        self->CopyLastFrames(self, i);
        if (!self->IsPageExisted(self, i))
            self->UpdatePageFrame(self, i);
    }
}

PRA *new_FIFO(int num_frames, char str_pages[20])
{
    PRA *pra = new_PRA(num_frames, str_pages);
    pra->StartPaging = &StartFIFO;
    return pra;
}

//LRU.c

#include "PRA.c"

int PageIndexInPast(PRA *const self, int page_index, int mem_value)
{
    for (int i = page_index - 1; i >= 0; i--)
        if (self->list_pages[i] == mem_value)
            return i;
    return -1;
}

void StartLRU(PRA *const self)
{
    for (int i = 0; i < self->total_pages; ++i)
    {
        self->CopyLastFrames(self, i);
        if (!self->IsPageExisted(self, i))
        {
            int last_past_index = i;
            if (self->IsFramesFull(self, i))
            {
                for (int j = 0; j < self->total_frames; ++j)
                {
                    int last_mem_index = self->total_pages * j + i - 1;
                    int last_mem_value = self->page_table[last_mem_index];
                    int past_index = PageIndexInPast(self, i, last_mem_value);

                    if (past_index == -1)
                    {
                        self->frame_update = j;
                        break;
                    }
                    else if (past_index < last_past_index)
                    {
                        self->frame_update = j;
                        last_past_index = past_index;
                    }
                }
            }
            self->UpdatePageFrame(self, i);
        }
    }
}

PRA *new_LRU(int num_frames, char str_pages[20])
{
    PRA *pra = new_PRA(num_frames, str_pages);
    pra->StartPaging = &StartLRU;
    return pra;
}

//Optimal.c

#include "PRA.c"

int PageIndexInPast(PRA *const self, int page_index, int mem_value)
{
    for (int i = page_index - 1; i >= 0; i--)
        if (self->list_pages[i] == mem_value)
            return i;
    return -1;
}

void StartLRU(PRA *const self)
{
    for (int i = 0; i < self->total_pages; ++i)
    {
        self->CopyLastFrames(self, i);
        if (!self->IsPageExisted(self, i))
        {
            int last_past_index = i;
            if (self->IsFramesFull(self, i))
            {
                for (int j = 0; j < self->total_frames; ++j)
                {
                    int last_mem_index = self->total_pages * j + i - 1;
                    int last_mem_value = self->page_table[last_mem_index];
                    int past_index = PageIndexInPast(self, i, last_mem_value);

                    if (past_index == -1)
                    {
                        self->frame_update = j;
                        break;
                    }
                    else if (past_index < last_past_index)
                    {
                        self->frame_update = j;
                        last_past_index = past_index;
                    }
                }
            }
            self->UpdatePageFrame(self, i);
        }
    }
}

PRA *new_LRU(int num_frames, char str_pages[20])
{
    PRA *pra = new_PRA(num_frames, str_pages);
    pra->StartPaging = &StartLRU;
    return pra;
}

//PRA.c

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PRA.h"

bool IsPageExisted(PRA *const self, int page_index)
{
    int page_value = self->list_pages[page_index];
    for (int i = 0; i < self->total_frames; ++i)
    {
        int last_mem_index = self->total_pages * i + page_index - 1;
        if (self->page_table[last_mem_index] == page_value)
            return true;
    }
    return false;
}

bool IsFramesFull(PRA *const self, int page_index)
{
    for (int i = 0; i < self->total_frames; ++i)
    {
        int mem_index = self->total_pages * i + page_index;
        if (self->page_table[mem_index] == -1)
            return false;
    }
    return true;
}

void CopyLastFrames(PRA *const self, int page_index)
{
    for (int i = 0; i < self->total_frames; ++i)
    {
        int last_mem_index = self->total_pages * i + page_index - 1;
        int last_mem_value = self->page_table[last_mem_index];
        self->page_table[self->total_pages * i + page_index] = last_mem_value;
    }
}

void UpdatePageFrame(PRA *const self, int page_index)
{
    int mem_index = self->total_pages * self->frame_update + page_index;
    self->page_table[mem_index] = self->list_pages[page_index];
    self->page_faults[page_index] = '*';
    self->total_page_faults++;

    self->frame_update++;
    if (self->frame_update >= self->total_frames)
        self->frame_update = 0;
}

void StartPaging(PRA *const self) {}

void PrintRowBorder(int total_pages)
{
    printf("\n--------------");
    for (int i = 0; i < total_pages; ++i)
        printf("----");
}

void DisplayPages(PRA *const self)
{
    PrintRowBorder(self->total_pages);

    printf("\n|    Page    |");
    for (int i = 0; i < self->total_pages; ++i)
        printf(" %d |", self->list_pages[i]);

    PrintRowBorder(self->total_pages);
}

void DisplayPageTable(PRA *const self)
{
    for (int i = 0; i < self->total_frames; ++i)
    {
        printf("\n|  Frame 0%d  |", i + 1);
        for (int j = 0; j < self->total_pages; ++j)
        {
            int value = self->page_table[i * self->total_pages + j];
            if (value == -1) printf("   |");
            else printf(" %d |", value);
        }
    }
}

void DisplayPageFaults(PRA *const self)
{
    PrintRowBorder(self->total_pages);

    printf("\n| Page Fault |");
    for (int i = 0; i < self->total_pages; ++i)
        printf(" %c |", self->page_faults[i]);

    PrintRowBorder(self->total_pages);
    printf("\n=> Number of Page Faults: %d\n", self->total_page_faults);
}

void delete_PRA(PRA *self)
{
    free(self->list_pages);
    free(self->page_table);
    free(self->page_faults);
    self = NULL;
}

PRA *new_PRA(int total_frames, char str_processes[20])
{
    PRA *pra = NULL;
    pra = (PRA *)malloc(sizeof(PRA));
    if (pra == NULL)
        return NULL;

    pra->total_frames = total_frames;
    pra->total_pages = strlen(str_processes);
    pra->total_page_faults = 0;
    pra->frame_update = 0;

    pra->list_pages = (int *)malloc(pra->total_pages * sizeof(int));
    if (pra->list_pages == NULL)
        return NULL;

    pra->page_table = (int *)malloc(pra->total_frames * pra->total_pages * sizeof(int));
    if (pra->page_table == NULL)
        return NULL;

    pra->page_faults = (char *)malloc(pra->total_pages * sizeof(char));
    if (pra->page_faults == NULL)
        return NULL;

    for (int i = 0; i < pra->total_pages; ++i)
    {
        *(pra->list_pages + i) = str_processes[i] - '0';
        *(pra->page_faults + i) = ' ';
    }

    for (int i = 0; i < pra->total_frames; ++i)
        for (int j = 0; j < pra->total_pages; ++j)
            pra->page_table[i * pra->total_pages + j] = -1;

    pra->IsPageExisted = &IsPageExisted;
    pra->IsFramesFull = &IsFramesFull;
    pra->CopyLastFrames = &CopyLastFrames;
    pra->UpdatePageFrame = &UpdatePageFrame;

    pra->StartPaging = &StartPaging;
    pra->DisplayPages = &DisplayPages;
    pra->DisplayPageTable = &DisplayPageTable;
    pra->DisplayPageFaults = &DisplayPageFaults;

    return pra;
}

//PRA.h

#include <stdbool.h>

typedef struct _PRA /* Page Replacement Algorithm */
{
    int total_frames;
    int total_pages;
    int total_page_faults;
    int frame_update;

    int *list_pages;
    int *page_table;
    char *page_faults;

    /* Get the current position of the page being reviewed and check if the value 
    of this page already exists in the previous position in the paging table */
    bool (*IsPageExisted)(struct _PRA *, int);

    /* Get the current position of the page being reviewed and check at this 
    position if the Frames are full. Used in 2 algorithms LRU and OPT. Can be 
    used in FIFO but this does not seem necessary */
    bool (*IsFramesFull)(struct _PRA *, int);

    /* Get the current position of the page being reviewed and assign the value 
    of the frames at this position equal to the value of the previous position */
    void (*CopyLastFrames)(struct _PRA *, int);

    /* Receives the current position of the page being reviewed and assigns the 
    value of the ordered frame by frame_update at this position by its value in 
    the page list. Next, proceed to mark the page error at this position while 
    increasing the total number of page errors and frame_update to 1 */
    void (*UpdatePageFrame)(struct _PRA *, int);

    /* The main function called to start running the algorithm is also a 
    virtual method that will be defined individually for each algorithm */
    void (*StartPaging)(struct _PRA *);

    /* Displays a list of pages */
    void (*DisplayPages)(struct _PRA *);

    /* Displays details of the value of frames in memory */
    void (*DisplayPageTable)(struct _PRA *);

    /* Displays the error results of each page and total number of page errors*/
    void (*DisplayPageFaults)(struct _PRA *);
} PRA;

//source.c

#include "FIFO.c"
#include "OPT.c"
#include "LRU.c"

int main()
{
	int choice, num_frames;
	char str_pages[20];
	PRA *pra;

	printf("\n--- Page Replacement Algorithm ---\n");
	printf("1. Default referenced sequence\n");
	printf("2. Manual input sequence\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);

	switch (choice)
	{
	case 1:
		strcpy(str_pages, "18520339007");
		break;
	case 2:
		printf("Enter processes: ");
		scanf("%s", str_pages);
		break;
	default:
		return 1;
	}

	printf("\nSelect algorithm:\n");
	printf("1. FIFO algorithm\n");
	printf("2. OPT algorithm\n");
	printf("3. LRU algorithm\n");

	printf("Enter your choice: ");
	scanf("%d", &choice);
	printf("Input page frames: ");
	scanf("%d", &num_frames);

	switch (choice)
	{
	case 1:
		printf("\nFIFO algorithm:");
		pra = new_FIFO(num_frames, str_pages);
		break;
	case 2:
		printf("\nOPT algorithm:");
		pra = new_OPT(num_frames, str_pages);
		break;
	case 3:
		printf("\nLRU algorithm:");
		pra = new_LRU(num_frames, str_pages);
		break;
	default:
		return 1;
	}

	pra->StartPaging(pra);
	pra->DisplayPages(pra);
	pra->DisplayPageTable(pra);
	pra->DisplayPageFaults(pra);

	delete_PRA(pra);
	return 0;
}
