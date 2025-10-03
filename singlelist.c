#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    };
void main()
{
int op,ans,item;
 struct node * start=(struct node *)0;
 struct node * push(struct node * ,int);
 struct node * pop(struct node *);
 void display(struct node *);
 int search(struct node*,int);
 while(1){
    printf("\n1. push\n2. pop\n3. display\n4. search\n5. exit\n");
    printf("your option : ");
    scanf("%d",&op);
    switch(op)
    {
    case 1:printf("\nitem to insert: ");
       scanf("%d",&item);
       start=push(start,item);
       break;
   case 2:start=pop(start);
      
       break;
   case 3:display(start);
       break;
  case 4:printf("\niten to search:\n");
        scanf("%d",&item);
        ans=search(start,item);
        if(ans==1)
        printf("\nfound");
       else
        printf("\nnot found");
        break;
  case 5:exit(0);
  }
  }
  }
//function to insert
struct node * push(struct node * list,int data)
{
struct node*t;
t=(struct node *) malloc(sizeof(struct node));
t->data=data;
t->next=list;
list=t;
return list;
}
//function to dleet 
struct node * pop(struct node * list)
{
struct node * t=list;
if(list != (struct node * )0)
{
printf("delerted item:%d",list->data);
list=list->next;
free(t);
}
else
printf("\nlist is empty");
return list;
}
//function to dispaly
void display(struct node * list)
{
while(list !=NULL)
{
printf("%d ,",list->data);
list=list->next;
}
printf("\n");
}
//functin to search
int search(struct node * list ,int item)
{
while(list != NULL)
{

if (list->data==item)
   return 1;
   list=list->next;
}
   return 0;

}
