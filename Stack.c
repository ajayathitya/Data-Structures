#include <stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}*ptr;

typedef ptr stack;

void push(stack s, int x)
{
    ptr ref = s->next;
    ptr element=malloc(sizeof(struct node));
    element->data=x;
    if(s->next==NULL)
    {
        element->next=NULL;
        s->next=element;
    }
    else
    {
        element->next = ref;
        s->next = element;
    }
        
    printf("Pushed %d!\n", x);
}

void display(stack s)
{
    ptr ref=s->next;
    printf("\n\nTOP-->");
    while(ref!=NULL)
    {
        printf("%d-->",ref->data);
        ref=ref->next;
    }
    printf("NULL\n\n");
}

int pop(stack s)
{
    ptr ref = s;
    if(ref->next == NULL)
    {
        printf("Stack Underflow!\n");
        return -1;
    }
    int del = ref->next->data;
    ptr delnode = ref->next;
    ref->next = delnode->next;
    free(delnode);
    printf("Popped Successfully!\n");
}

void deletestack(stack s)
{
    ptr ref=NULL;
    ptr cur = s;
    while(cur!=NULL)
    {
        ref = cur->next;
        free(cur);
        cur = ref;
    }
    printf("\n\nStack Deleted!\n\n");
}

int peep( stack s)
{
    if(s->next!=NULL)
    {
        return s->next->data;
    }
    else
    {
        printf("Stack Empty!");
    }
}

int main()
{
    int ch,x,i;
    
    stack s = malloc(sizeof(struct node));
    s->data=0;// top node
    s->next=NULL;
    
    printf("Main Menu : \n\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Display Stack\n");
    printf("4. Peep\n");// returns top
    printf("5. Delete Stack\n");
    printf("0. Exit\n\n");
    
    do
    {
        printf("Enter the Choice : ");
        scanf("%d",&ch);
    
        switch(ch)
        {
            case 1: printf("Enter the Data : ");
                    scanf("%d",&x);
                    push(s,x);
                    printf("Operation Completed !\n");
                    display(s);
                    break;
                
            case 2: i = pop(s);
                    printf(" %d popped Operation Completed !\n", i);
                    display(s);
                    break;
                    
            case 3: display(s);
                    break;

            case 4: i=peep(s);
                    printf("Top Element : %d\n", i);
                    break;
                
            case 5: deletestack(s);
                    break;
                    
            case 0: printf("\nProgram Terminated!\n");
                    exit(0);
                
              default: printf("Invalid Choice !\n");
                break;
        }
        
    }while(ch!=0);
    
    return 0;
}
