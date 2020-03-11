#include<stdio.h>
#include<stdlib.h>
void push();
void pop();
void display();
struct node
{
    int data;
    struct node *next;
}*head,*top,*temp;
int main()
{
	int choice;
	while(1)
	{
	    printf("***** Stack *****\n");
		printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
			default:
				printf("\nInvalid choice try again.");
		}
	}
	return 0;
}
void push()
{
	int element;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter element to push:");
	scanf("%d",&element);
    temp->data=element;
    if(head==NULL)
	{
        head=temp;
        top=head;
	}
	else
	{
        top->next=temp;
        top=temp;
	}
    printf("\n%d is pushed.\n",element);
}
void pop()
{
    if(head==NULL || top==NULL)
    {
        printf("\nStack is empty.");
    }
    else if(head==top)
    {
        printf("\n%d is popped.\n",top->data);
        head=NULL;
        top=NULL;
    }
    else
    {
        temp=head;
        while(temp->next!=top)
        {
            temp=temp->next;
        }
        printf("\n%d is popped.\n",top->data);
        free(top);
        top=temp;
    }
}
void display()
{
    if(top==NULL)
    {
        printf("\nStack is empty.\n");
    }
    else
    {
        printf("%d is at top of stack.\n",top->data);
    }
}
