#include<stdio.h>
#include<stdlib.h>
struct node
{
int value;
struct rep * repptr;//pointer to head node of the list
struct node * next;
};
//represent header node of linked representation
struct rep{
struct node * head;
struct node * tail;
};
//struct to sroe key and obj node pointer 
struct nodaddr
{
int key;
struct node *obj_node_ptr;
struct nodaddr * next;
};
struct nodaddr * ndr=0;


//function to create a set
void makeset(int a)
{
struct nodaddr * t=(struct nodaddr *)malloc(sizeof(struct nodaddr));
//new set
struct rep * newset=(struct rep *)malloc(sizeof(struct rep));
struct node *n=(struct node *)malloc(sizeof(struct node));
//find values
n->value=a;
n->repptr=newset;
n->next=0;

//initialise head and tail
newset->head=newset->tail=n;

//to store object node pointer and key
t->obj_node_ptr=n;
t->key=a;
t->next=ndr;
ndr=t;
}
//function to return pointer of representative of the set 
//containingx
struct rep * find(int x)
{
struct nodaddr * t=ndr;
while(t!=0&&t->key!=x)
t=t->next;
return t->obj_node_ptr->repptr;
}


//union of set
void unionset(int key1,int key2)
{
struct rep * set1,*set2;
struct node * t1;
set1=find(key1);
set2=find(key2);
if(set1==set2)
printf("\n %d &%d belongs to same set",key1,key2);
else{
//changing header points of obgcts of set2 to set1
t1=set2->head;
while(t1 != 0)
{
t1->repptr=set1;
t1=t1->next;
}
set1->tail->next=set2->head;
set1->tail=set2->tail;//tail exchange
free(set2);
}
}

//functio to display

void display_set(int a){
struct rep *r;
struct node * t;
r=find(a);
t=r->head;
printf("\nset members containing %d:",a);
while(t != 0)
{
printf("%d",t->value);
t=t->next;
}
}



void main()
{
makeset(2);
makeset(3);
makeset(4);
makeset(5);
makeset(6);
printf("\nfind(2)=%X\n",find(2));
printf("\nfind(3)=%X\n",find(3));
printf("\nfind(4)=%X\n",find(4));
printf("\nfind(5)=%X\n",find(5));
printf("\nfind(6)=%X\n",find(6));
unionset(2,3);
printf("\nafter union of 2&3 find(3)=%X",find(3));
unionset(4,5);
printf("\nafter union of 4&5 find(5)=%X",find(5));
unionset(3,5);
printf("\nafter union of 3&5 find(5)=%X",find(5));
display_set(5);
}
