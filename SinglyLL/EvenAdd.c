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

// int CheckEven(int iNo)
// {
//     int iCnt = 0;
    

//     for(iCnt = 0;iCnt <= (iNo);iCnt++)
//     {
//         if(iNo % 2 == 0)
//         {
//             iSum = iSum + iCnt;
//         }
//     }
//     return iSum;

// }
int EvenAdd(PNODE first)
{
    PNODE temp = NULL;

    int iSum = 0;
    
    temp = (first);

    while(temp != NULL)
    {
        if((temp->data) % 2 == 0)
        {
            iSum = iSum + temp->data;
        }

        temp =  temp->next;
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
    InsertFirst(&head,6);
    InsertFirst(&head,28);
    InsertFirst(&head,17);
    InsertFirst(&head,21);
    InsertFirst(&head,11);
    
    Display(head);

    iRet = EvenAdd(head);

    printf("Addition of Even element is : %d\n",iRet);

    return 0;
}