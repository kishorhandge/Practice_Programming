#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void InsertFirst(PPNODE first, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if (*first == NULL)
    {
        (*first) = newn;
    }
    else
    {
        newn->next = (*first);
        (*first) = newn;
    }
}

void Display(PNODE first)
{
    while (first != NULL)
    {
        printf("| %d |->", first->data);
        first = first->next;
    }
    printf("NULL\n");
}

float FindAverage(int iNo)
{
    int iSum = 0;
    int iCnt = 0;
    int iCount = 0;

    float fAvg = 0.0f;

    for (iCnt = 1; iCnt <= iNo; iCnt++)
    {
        iSum = iSum + iNo;
        iCount++;
    }

    fAvg = (iSum / iCount);

    return fAvg;
}

void DisplayGreaterThanAvg(PNODE first)
{   
    PNODE temp = NULL;

    int iSum = 0;
    int iCount = 0;

    float fAvg = 0.0f;

    temp = first;

    while (temp != NULL)
    {
        iSum = iSum + temp->data;
        iCount++;

        temp = temp->next;
    }

    if(iCount == 0)
    {
        return;
    }

    fAvg = (float)(iSum) / iCount;

        temp = first;

        while (temp != NULL)
        {
            if ((temp->data) > fAvg)
            {
                printf("| %d |->",temp->data);
            }
            temp = temp->next;
        }

        printf("NULL\n");
}

int main()
{
    PNODE head = NULL;

    InsertFirst(&head, 51);
    InsertFirst(&head, 41);
    InsertFirst(&head, 31);
    InsertFirst(&head, 21);
    InsertFirst(&head, 11);

    Display(head);

    DisplayGreaterThanAvg(head);

    return 0;
}