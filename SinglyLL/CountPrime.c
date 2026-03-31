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

bool CheckPrime(int iNo)
{
    int iCnt = 0;
    int iCount = 0;
    
    if(iNo <= 1)
    {
        return false;
    }

    for(iCnt = 2;iCnt<=iNo/2;iCnt++)
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

bool CountPrime(PNODE first)
{
    PNODE temp = NULL;
    int iCount = 0;
    
    temp = (first);

    while(temp != NULL)
    {
        if(CheckPrime(temp->data))
        {
           iCount++;
        } 
        temp = temp->next;
    }

    return iCount;
}


int main()
{
    PNODE head = NULL;
    int iRet = 0;

    InsertFirst(&head,51);
    InsertFirst(&head,41);
    InsertFirst(&head,31);
    InsertFirst(&head,6);
    
    Display(head);

    iRet = CountPrime(head);

    printf("Frequency of prime number is : %d\n",iRet);

    return 0;
}