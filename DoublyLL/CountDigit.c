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

int CountDigit(PNODE first)
{
    PNODE temp = NULL;

    temp = first;

    int iDigit = 0;
    int iCount = 0;

    while(temp != NULL)
    {
        while((temp->data) != 0)
        {
            iDigit = (temp->data) % 10;
            iCount++;
            temp->data = (temp->data) /10;
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
    InsertFirst(&head,28);
    InsertFirst(&head,21);
    InsertFirst(&head,11);
    InsertFirst(&head,6);

    Display(head);

    iRet = CountDigit(head);

    printf("Number of digit is : %d\n",iRet);

    return 0;
}