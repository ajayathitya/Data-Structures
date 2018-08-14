#include <stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}*ptr;

typedef ptr queue;

void enqueue(queue q, int x)
{
    ptr ref = q;
    ptr element=malloc(sizeof(struct node));
    element->data=x;
    element->next=NULL;
    while(ref->next!=NULL)
    {
        ref = ref->next;
    }
    ref->next=element;
}

void display(queue l)
{
    ptr ref=l->next;
    printf("\n\nFRONT-->");
    while(ref!=NULL)
    {
        printf("%d-->",ref->data);
        ref=ref->next;
    }
    printf("REAR\n\n");
}

void dequeue(queue q, int x)
{
    ptr ref = q;
    if(ref->next == NULL)
    {
        printf("Queue Underflow\n");
        return;
    }
    int del = ref->next->data;
    ptr delnode = ref->next;
    ref->next = delnode->next;
    free(delnode);
    printf("Dequeued Successfully!\n");
}

void deletequeue(queue q)
{
    ptr ref=NULL;
    ptr cur = q;
    while(cur!=NULL)
    {
        ref = cur->next;
        free(cur);
        cur = ref;
    }
    printf("\n\nQueue Deleted!\n\n");
}

int main()
{
    int ch,x,i;

    queue q = malloc(sizeof(struct node));
    q->data=0;// head node
    q->next=NULL;

    printf("Main Menu : \n\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display Queue\n");
    printf("4. Delete Queue\n");
    printf("0. Exit\n\n");

    do
    {
        printf("Enter the Choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: printf("Enter the Data : ");
                    scanf("%d",&x);
                    enqueue(q,x);
                    printf("Operation Completed !\n");
                    display(q);
                    break;

            case 2: dequeue(q,x);
                    printf("Operation Completed !\n");
                    display(q);
                    break;

            case 3: display(q);
                    break;

            case 4: deletequeue(q);
                    break;

            case 0: printf("\nProgram Terminated!\n");
                    exit(0);

              default: printf("Invalid Choice !\n");
                break;
        }

    }while(ch!=0);

    return 0;
}

