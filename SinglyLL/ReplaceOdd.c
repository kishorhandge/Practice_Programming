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

void ReplaceOdd(PNODE first)
{
    PNODE temp = NULL;
    
    temp = (first);

    bool bFlag = true;

    while(temp != NULL)
    {
        if((temp->data) % 2 == 1)
        {
            temp->data = 1;
        }
 
        temp =  temp->next;
    }

}


int main()
{
    PNODE head = NULL;
    bool bRet = false;

    InsertFirst(&head,51);
    InsertFirst(&head,40);
    InsertFirst(&head,31);
    InsertFirst(&head,21);
    InsertFirst(&head,11);
    InsertFirst(&head,18);
    InsertFirst(&head,8);
    
    Display(head);

    ReplaceOdd(head);

    Display(head);

    return 0;
}