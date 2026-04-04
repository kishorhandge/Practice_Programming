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

void MakeAbsolute(PNODE first)
{
    PNODE temp = NULL;
    
    temp = (first);

    while(temp != NULL)
    {
        if((temp->data) < 0 )
        {
            temp->data = -(temp->data);
             
        }
 
        temp =  temp->next;
    }

}


int main()
{
    PNODE head = NULL;
    int iRet = 0;

    InsertFirst(&head,51);
    InsertFirst(&head,40);
    InsertFirst(&head,31);
    InsertFirst(&head,6);
    InsertFirst(&head,-28);
    InsertFirst(&head,20);
    InsertFirst(&head,-21);
    InsertFirst(&head,11);
    
    Display(head);

    MakeAbsolute(head);

    Display(head);

    return 0;
}