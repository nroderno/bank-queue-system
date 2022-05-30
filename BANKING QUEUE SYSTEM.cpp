//stack implementation
#include<stdio.h>
#define MAX 100 //to define capacity of stack

int QUEUE[MAX],front=-1,rear=-1, customer_num=100;

void enqueue(int QUEUE[],int customer_num) //add to queue
{
    if(rear==-1) //for enqueuing first element
    {
        front=rear=0;
        QUEUE[rear]=customer_num;
    }
    else if(rear==MAX-1) //if queue is full
    {
        printf("\nWaiting List is full.\n");
        return;
    }
    else //if adding an element to a queue that already contains an element
    {
        rear++;
        QUEUE[rear]=customer_num;
    }
    printf("Please wait until your number is called. Thank you.");
    printf("\n\n");
}

void generate_customer_num() //generate a number and add to queue
{
	customer_num = customer_num+1;
	printf("\nYou are customer number: %i",customer_num);
	printf("\n");
	enqueue(QUEUE,customer_num);
}

void view(int QUEUE[]) //to traverse or view the queue
{    
    if(rear==-1) //the queue is empty
	{
		printf("\nWaiting Line is Empty.");
		printf("\n\n");
		return; 
	}
	
	//if the queue contains an element
	printf("\nWaiting Line:\n");
    for(int i=front;i<=rear;i++)
    { 
		printf("%i\n",QUEUE[i]);
	}
	printf("\n");
 
}

void update(int QUEUE[]) //to remove topmost element
{
    //if the queue is empty
    if(front==-1)
    {
        printf("\nWaiting Line is Empty.");
        printf("\n\n");
        return;
    }
    else if(front==rear) //if removing the topmost element before the queue gets empty
    {
        customer_num=QUEUE[front];
        front=rear=-1;
    }
    else //to remove the topmost element and adjust the queue
    {
        customer_num=QUEUE[front];
        front++;
    }
    printf("\nNow Serving Customer Number: %i.",customer_num);
    printf("\n\n");
}


int main()
{
	/*	the 'customer' is just to generate a number that will be enqueued
		the 'admin' is for the user to view and remove elements from the queue */
	start:
	int choice_admin, choice_customer, start;
	printf("*****welcome to the bank*****\n\n");
	printf("Are you a Customer (1) or an Admin (0)? : ");
	scanf("%i",&start);
 	
	 //customer
	 if (start==1)
 	{
 		printf("\n****Good day, Customer!*****");
		
		//genreate a number and automatically adds it to the queue
		generate_customer_num();
		printf("\n\n");
		
		goto start;	
	}
	
	//admin account
	else if (start==0)	
	{
		printf("\n****Good day, Admin!*****\n");
		while(1)
		{
			printf("1.View Waiting Line\n2.Update 'Now Serving' number\n3.Quit\n\n");
			printf("what would you like to do? : ");	scanf("%i",&choice_admin);
		
			switch(choice_admin)
			{
				case 1:
				{
					//view the elements on the queue
					view(QUEUE);
					break;
				}
				case 2:
				{
					//remove the topmost element on the queue
					update(QUEUE);
					view(QUEUE);
					break;
				}
				case 3:
				{
					//to exit the 'admin' account
					printf("\n");
					goto start;
				}
				default:
				{
					printf("Invalid input.");
					printf("\n\n");
				}
			}
		}
	}
	else
	{
		printf("Invalid input. Plese Try again.");
		printf("\n\n");
		goto start;
	}
}
