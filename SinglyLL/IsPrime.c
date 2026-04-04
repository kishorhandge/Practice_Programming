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
            return false;
        }
    }

    return true;
}

bool IsPrime(PNODE first)
{
    PNODE temp = NULL;

    bool bFlag = false;
    
    temp = (first);

    int iCount = 0;

    while(temp != NULL)
    {
        if(CheckPrime(temp->data))
        {
           return true;
        } 
        temp = temp->next;
    }

    return false;
}


int main()
{
    PNODE head = NULL;
    bool bRet = false;

    InsertFirst(&head,51);
    InsertFirst(&head,41);
    InsertFirst(&head,31);
    InsertFirst(&head,6);
    
    Display(head);

    bRet = IsPrime(head);

    if(bRet == true)
    {
        printf("contains prime elements \n");
    }
    else
    {
        printf("No any prime element \n");
    }

    return 0;
}