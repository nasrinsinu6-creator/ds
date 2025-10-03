#include <stdio.h>
#include<stdlib.h>
#define SIZE 10
int queue [SIZE];

int front=1,rear=1;
void main()
{
void insert(int);
int delete(),opt,item,ans;
int search();
void display();
while(1){
printf("\n1. insert\n2. delete\n3. display\n4. search\n5. exit\n");
printf("\nenter your option: ");
scanf("%d",&opt);
switch(opt)
{
case 1:printf("\nitem to insert: ");
       scanf("%d",&item);
       insert(item);
       break;
case 2:item=delete();
       printf("\n%d is deleted:\n",item);
       break;
case 3:display();
       break;
case 4:printf("\nitem to search:");
       scanf("%d",&item);
       ans=search(item);
       if(ans==1)
         printf("\nfound\n");
       else
         printf("\nnot found");
         break;
case 5:exit(0);
}
}
}
//function to insert
void insert(int data)
{
int r1;
r1=(rear+1)%SIZE;
if(r1==front)
printf("queue is full");
else
{
rear=r1;
queue[rear]=data;
}
return;
}
//function to delete
int delete()
{
if(front==rear)
{
 printf("queue is empty");
  exit(1);
}
else{
 front=(front+1)%SIZE;
 return queue[front];
 }
 }
 
//function to display
void display()
{
int f=front,r=rear;
while(f!=r)
{
f=(f+1)%SIZE;
  printf("%d,",queue[f]);
}
return;
}
//functin to search
int search(int item)
{
int f=front,r=rear;
while(f!=r)
{
f=(f+1)%SIZE;
if(queue[f]==item)
return 1;
}
return 0;
}
