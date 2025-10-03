#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *left,*right;
};
void main(){
 struct node * start = (struct node *)0;
 struct node * insert(struct node * ,int);
 struct node * search(struct node *,int);
 struct node * delete(struct node * ,int);
 void display(struct node *);
 int item,op;
 while(1){
 printf("\n1. insert\n 2.delete\n 3.search\n 4.display\n 5.exit\n");
 printf("enter your option: ");
 scanf("%d",&op);
 switch(op){
   case 1:printf("\nitem to insert:\n ");
       scanf("%d",&item);
       start=insert(start,item);
       break;
   case 2:printf("\nitem to delete:\n");
        scanf("%d",&item);
        start=delete(start,item);
       break;
  
  case 3:printf("\nitem to search");
        scanf("%d",&item);
       if(search(start,item)==(struct node *)0)
       printf("\nnot found");
       else
       printf("\nfound");
        break;
 case 4:display(start);
       break;
       
  case 5:exit(0);
  }
  }
  }
  //function to insert a nodde
struct node * insert(struct node * s,int data)
{
struct node * t;
t=(struct node *)malloc(sizeof(struct  node));
t->data=data;
t->left=(struct node * )0;
t->right=s;
if(s!=0)
s->left=t;
return t;
}
//function to display
void display(struct node * s)
{
while(s!=0)
{
printf("%d,",s->data);
s=s->right;
}
return;
}
//function to search data

struct node * search(struct node * s, int data)
{
while(s!=0 && data != s->data)
s=s->right;
return s;
}
//function to delete 
struct node * delete(struct node * s,int data)
{
struct node *t;
t=search(s,data);
if(t==0)
printf("\nnot found\n");
else
if(t->left ==0)
{
s=s->right;
if(t->right !=0)
s->left=0;
free(t);
}
else
{
t->left->right=t->right;
if(t->right != 0)
t->right->left=t->left;
free(t);
}
return s;
}


















