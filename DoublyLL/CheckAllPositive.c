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


int CheckAllPositive(PNODE first)
{
    PNODE temp = NULL;

    temp = first;

    bool bFlag = true;

    while(temp != NULL)
    {
        if((temp->data) < 0)
        {
            bFlag = false;
        }

        temp = temp->next;
    }

    return bFlag;
   
}

int main()
{
    PNODE head = NULL;

   bool bRet = 0;

    InsertFirst(&head,51);
    InsertFirst(&head,-41);
    InsertFirst(&head,31);
    InsertFirst(&head,30);
    InsertFirst(&head,40);
    InsertFirst(&head,21);
    InsertFirst(&head,11);
    InsertFirst(&head,6);

    Display(head);

    bRet = CheckAllPositive(head);

    if(bRet == true)
    {
        printf("All Element is positive:\n");
    }
    else
    {
        printf("All Element is not positive:\n");
    }

    return 0;
}