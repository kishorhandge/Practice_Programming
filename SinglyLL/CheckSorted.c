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

bool CheckSorted(PNODE first)
{
    PNODE temp = NULL;
    
    temp = (first);

    bool bFlag = true;

    while(temp != NULL && temp->next != NULL)
    {
        if((temp->data) > temp->next->data)
        {
            bFlag = false;
            break;
        }
 
        temp =  temp->next;
    }

    return bFlag;

}


int main()
{
    PNODE head = NULL;
    bool bRet = false;

    InsertFirst(&head,51);
    InsertFirst(&head,41);
    InsertFirst(&head,31);
    InsertFirst(&head,21);
    InsertFirst(&head,11);
    
    
    Display(head);

    bRet = CheckSorted(head);

    if(bRet == true)
    {
        printf("Elements are sorted :\n");
    }
    else
    {
        printf("Elements are not sorted:\n");
    }

    return 0;
}