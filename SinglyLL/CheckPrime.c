#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;


void InsertFirst(PPNODE first,int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if(*first == NULL)
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
    while(first != NULL)
    {
        printf("| %d |->",first->data);
        first = first->next;
    }
    printf("NULL\n");
}

int CheckPrime(int iNo)
{
    int iCnt = 0;
    int iCount = 0;

    for(iCnt = 2;iCnt <= (iNo/2);iCnt++)
    {
        if(iNo % iCnt == 0)
        {
            iCount++;
        }
    }

    if(iCount == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void DisplayPrime(PNODE first)
{
    PNODE temp = NULL;
    
    temp = (first);

    printf("Prime Elements are:\n ");

    while(temp != NULL)
    {
        if(CheckPrime(temp->data))
        {
            printf("| %d |->",temp->data);
        }

        temp =  temp->next;
    }

    printf("\n");
}

 

int main()
{
    PNODE head = NULL;
    int iRet = 0;

    InsertFirst(&head,51);
    InsertFirst(&head,41);
    InsertFirst(&head,31);
    InsertFirst(&head,6);
    InsertFirst(&head,28);
    InsertFirst(&head,17);
    InsertFirst(&head,21);
    InsertFirst(&head,11);
    
    Display(head);

    DisplayPrime(head);

    return 0;
}