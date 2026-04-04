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

int DisplayLastOcc(PNODE first,int iNo)
{
    PNODE temp = NULL;
    int iCnt = 0;

    temp = first;

    int iPos = 1;
    int LastPos = 0;

    while (temp != NULL)
    {
        if((temp->data) == iNo)
        {
            LastPos = iPos;
        }
        
        temp = temp->next;
        iPos++;
    }

    return LastPos;
}

int main()
{
    PNODE head = NULL;
    int iRet = 0;
    int iValue = 0;

    InsertFirst(&head, 89);
    InsertFirst(&head, 41);
    InsertFirst(&head, 89);
    InsertFirst(&head, 6);
    InsertFirst(&head, 60);
    InsertFirst(&head, 21);
    InsertFirst(&head, 11);

    Display(head);

    printf("Enter the element:\n");
    scanf("%d", &iValue);

    iRet = DisplayLastOcc(head,iValue);

    if(iRet == -1)
    {
        printf("Element is not present:\n");
    }
    else
    {
        printf("Last Occurance of element at position: %d\n", iRet);
    }

    

    return 0;
}