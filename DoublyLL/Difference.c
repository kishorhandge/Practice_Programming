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


int Difference(PNODE first)
{
    PNODE temp = NULL;

    temp = first;
    int iMax = temp->data;
    int iMin = temp->data;

    while(temp != NULL)
    {
        if((temp->data) > iMax)
        {
            iMax = temp->data;
        }

        if(temp->data < iMin)
        {
            iMin = temp->data;
        }
        temp = temp->next;
    }

   int Diff =  iMax - iMin;
}

int main()
{
    PNODE head = NULL;

    int iRet = 0;

    InsertFirst(&head,51);
    InsertFirst(&head,41);
    InsertFirst(&head,31);
    InsertFirst(&head,30);
    InsertFirst(&head,40);
    InsertFirst(&head,21);
    InsertFirst(&head,11);
    InsertFirst(&head,6);

    Display(head);

    iRet = Difference(head);

    printf("Difference is : %d\n",iRet);

    return 0;
}