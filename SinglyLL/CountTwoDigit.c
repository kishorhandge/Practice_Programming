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

int CountDigit(int iNo)
{
    int iCount = 0;
    int iCountTwo = 0;

    while(iNo != 0)
    {   
        iNo = iNo / 10;
        iCount++;
    }

    if(iCount == 2)
    {
        iCountTwo++;
    }

    return iCountTwo;
}

int CountTwoDigit(PNODE first)
{
    PNODE temp = NULL;
    
    temp = (first);

    int iCount = 0;

    while(temp != NULL)
    {
        
        iCount = iCount + CountDigit(temp->data);
        temp = temp->next;
         
    }

    return iCount;
    
}


int main()
{
    PNODE head = NULL;
    int iRet = 0;

    InsertFirst(&head,511);
    InsertFirst(&head,41);
    InsertFirst(&head,311);
    InsertFirst(&head,61);
    InsertFirst(&head,71);
    InsertFirst(&head,91);
    
    Display(head);

    iRet = CountTwoDigit(head);

    printf("%d",iRet);

    return 0;
}