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

int CountSmaller(PNODE first,int iNo)
{
    PNODE temp = NULL;

    int iCount = 0;
    
    temp = (first);

    while(temp != NULL)
    {
        if((temp->data) < iNo)
        {
            iCount++;;
        }

        temp =  temp->next;
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
    InsertFirst(&head,6);
    InsertFirst(&head,28);
    InsertFirst(&head,17);
    InsertFirst(&head,21);
    InsertFirst(&head,11);
    
    Display(head);

    printf("Enter the element:\n");
    scanf("%d", &iValue);


    iRet = CountSmaller(head,iValue);

    printf("%d Elements are Smaller than given number which is : %d\n",iRet,iValue);

    return 0;
}