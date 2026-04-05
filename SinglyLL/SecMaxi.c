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

int SecMaximum(PNODE first)
{
    PNODE temp = NULL;
    
    temp = (first);

    int iMax = 0;
    int SecMaxi = iMax;

    while(temp != NULL)
    {
        if((temp->data) > iMax)
        {   
            SecMaxi = iMax;
            iMax = temp->data;
        }
        else if( SecMaxi < temp->data && temp->data != iMax)
        {
            SecMaxi = temp->data;
        }
        
        temp =  temp->next;
    }

    return SecMaxi;
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

    iRet = SecMaximum(head);

    printf("Second Maximum element from list is : %d\n",iRet);

    return 0;
}