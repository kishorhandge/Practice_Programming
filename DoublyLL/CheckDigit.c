#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
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
    newn->prev = NULL;

    if(*first == NULL)
    {
        (*first) = newn;
    }
    else
    {
        newn->next = (*first);
        (*first)->prev = newn;
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

bool CheckDigit(int iNo)
{
    int iDigit = 0;
    int iSum = 0;

    while(iNo != 0)
    {
        iDigit = iNo % 10;
        iSum = iSum + iDigit;
        iNo = iNo / 10;
    }

    return iSum;

}

int SumDigit(PNODE first)
{
    PNODE temp = NULL;

    temp = first;

    int iSum = 0;

    while(temp != NULL)
    {
        if(CheckDigit(temp->data))
        {
            iSum = iSum + temp->data;
        }
        temp = temp->next;
    }

    return iSum;
}
 

int main()
{
    PNODE head = NULL;
    int iRet = 0;

    InsertFirst(&head,51);
    InsertFirst(&head,41);
    InsertFirst(&head,31);
    InsertFirst(&head,28);
    InsertFirst(&head,21);
    InsertFirst(&head,11);
    InsertFirst(&head,6);

    Display(head);

    iRet = SumDigit(head);

    printf("Addition of digit is  : %d\n",iRet);

    return 0;
}