// UNFINISHED (NEEDS TESTING AND DEBUGGING)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_SIZE 100
#define PALETTE_SIZE 64

typedef struct Color
{
    char colorName[NAME_SIZE];
    int RGBval[3];
} Color;

typedef struct Node
{
    Color col;
    struct Node *next;
} Node, *NodePtr;

typedef struct Dictionary
{
    NodePtr head;
} Dict;

void initDict(Dict dict[]);
int constrainedRGB(Color col);
void insertColor(Dict *dict, Color insColor);
void deleteColor(Dict *dict, Color delColor);

int main()
{
    Dict dict[PALETTE_SIZE];
    Color insColor1;

    // Init the color to be inserted
    strcpy(insColor1.colorName, "TestColor");
    insColor1.RGBval[0] = 32;
    insColor1.RGBval[1] = 56;
    insColor1.RGBval[2] = 5;

    initDict(dict);
    insertColor(dict, insColor1);
    deleteColor(dict, insColor1);

    return 0;
}

void initDict(Dict dict[])
{
    for (int i = 0; i < PALETTE_SIZE; i++)
    {
        dict[i].head = NULL;
    }
}

void insertColor(Dict *dict, Color insColor)
{
    int idx = constrainedRGB(insColor);
    NodePtr temp = (NodePtr)malloc(sizeof(Node));

    if (temp == NULL)
    {
        printf("\nMemory Allocation Failed!\n");
    }
    else
    {
        strcpy(temp->col.colorName, insColor.colorName);
        for (int i = 0; i < 3; i++)
        {
            temp->col.RGBval[i] = insColor.RGBval[i];
        }

        temp->next = NULL;

        if (dict[idx].head == NULL)
        {
            dict[idx].head = temp;
        }
        else
        {
            NodePtr trav;
            for (trav = dict[idx].head; trav->next != NULL; trav = trav->next)
            {
            }
            trav->next = temp;
        }
    }
}

void deleteColor(Dict *dict, Color delColor)
{
    int idx = constrainedRGB(delColor);
    NodePtr trav = dict[idx].head, prev = NULL;

    if (trav == NULL)
    {
        printf("\nColor not found!\n");
    }
    else
    {
        while (strcmp(trav->col.colorName, delColor.colorName) != 0)
        {
            prev = trav;
            trav = trav->next;
        }

        if (trav->next == NULL)
        { // First in the linked list
            free(trav);
            dict[idx].head = NULL;
        }
        else
        {
            prev->next = trav->next;
            free(trav);
        }
    }
}

void searchColor(Dict *dict, Color searchColor)
{
    int idx = constrainedRGB(searchColor), i = 0;
    NodePtr trav = dict[idx].head;

    if (trav == NULL)
    {
        printf("\nColor not found\n");
    }
    else
    {
        while (trav != NULL && strcmp(trav->col.colorName, searchColor.colorName) != 0)
        {
            trav = trav->next;
            i++;
        }

        if (trav != NULL)
        {
            printf("\nColor found at index %d\n", i);
        }
        else
        {
            printf("\nColor not found\n");
        }
    }
}

int constrainedRGB(Color col)
{
    return (col.RGBval[0] * col.RGBval[1] * col.RGBval[2] % 64);
}