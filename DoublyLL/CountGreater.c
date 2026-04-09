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

int CountGreater(PNODE first,int iNo)
{
    PNODE temp = NULL;

    temp = first;

    int iCount = 0;
     
    while(temp != NULL)
    {
        if((temp->data) > iNo)
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
    int iValue = 0;

    InsertFirst(&head,51);
    InsertFirst(&head,41);
    InsertFirst(&head,31);
    InsertFirst(&head,21);
    InsertFirst(&head,11);
    InsertFirst(&head,41);
    InsertFirst(&head,6);

    Display(head);

    printf("Enter the element :\n");
    scanf("%d",&iValue);

    iRet = CountGreater(head,iValue);

    printf("Count of greater than of given number is : %d\n",iRet);
    
    return 0;
}