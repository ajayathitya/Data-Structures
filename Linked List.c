#include <stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}*ptr;

typedef ptr head;

void createnode(head l, int x)
{
    ptr ref = l;
    ptr element=malloc(sizeof(struct node));
    element->data=x;
    element->next=NULL;
    while(ref->next!=NULL)
    {
        ref = ref->next;
    }
    ref->next=element;
    printf("Node Added!\n");
}

void display(head l)
{
    ptr ref=l->next;
    printf("\n\nHEAD-->");
    while(ref!=NULL)
    {
        printf("%d-->",ref->data);
        ref=ref->next;
    }
    printf("NULL\n\n");
}

void deletenode(head l, int x)
{
    ptr ref = l;
    while(ref->next->data!=x)
    {
        ref = ref->next;
    }
    if(ref == NULL)
    {
        printf("Element Not Found!\n");
        return;
    }
    int del = ref->next->data;
    ptr delnode = ref->next;
    ref->next = delnode->next;
    free(delnode);
    printf("Deleted Successfully!\n");
}

void deletelist(head l)
{
    ptr ref=NULL;
    ptr cur = l;
    while(cur!=NULL)
    {
        ref = cur->next;
        free(cur);
        cur = ref;
    }
    printf("\n\nList Deleted!\n\n");
}

int main()
{
    int ch,x,i;
    
    head l = malloc(sizeof(struct node));
    l->data=0;// head node
    l->next=NULL;
    
    printf("Main Menu : \n\n");
    printf("1. Add Node\n");
    printf("2. Delete Node\n");
    printf("3. Display List\n");
    printf("4. Delete List\n");
    printf("0. Exit\n\n");
    
    do
    {
        printf("Enter the Choice : ");
        scanf("%d",&ch);
    
        switch(ch)
        {
            case 1: printf("Enter the Data : ");
                    scanf("%d",&x);
                    createnode(l,x);
                    printf("Operation Completed !\n");
                    display(l);
                    break;
                
            case 2: printf("Enter the Data to be Deleted : ");
                    scanf("%d",&x);
                    deletenode(l,x);
                    printf("Operation Completed !\n");
                    display(l);
                    break;
                    
            case 3: display(l);
                    break;
                
            case 4: deletelist(l);
                    break;
                    
            case 0: printf("\nProgram Terminated!\n");
                    exit(0);
                
              default: printf("Invalid Choice !\n");
                break;
        }
        
    }while(ch!=0);
    
    return 0;
}
