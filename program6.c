#include<stdio.h>
struct bit{unsigned char x:1;};
int uset[]={1,2,3,4,5,6,7,8,9},size=9;
void main(){
void readset(struct bit[],int n);
void printset(struct bit[]);
void unionset(struct bit[],struct bit[],struct bit[]);
void intersectionset(struct bit[],struct bit[],struct bit[]);
void differenceset(struct bit[],struct bit[],struct bit[]);
struct bit a[10]={0},b[10]={0},c[10]={0};
int n;
printf("no of elements in set A : ");
scanf("%d",&n);
readset(a,n);
printf("no of elemnets in set B : ");
scanf("%d",&n);
readset(b,n);
printf("Set A:"),printset(a);
printf("Set B:"),printset(b);
unionset(a,b,c);
printf("A U B :"),printset(c);
intersectionset(a,b,c);
printf("A intersction B="),printset(c);
differenceset(a,b,c);
printf("A-B="),printset(c);
}

//function to read and store as bit
void readset(struct bit a[],int n){
int i,x,k;
printf("enter %d elements : ",n);
for(i=0;i<n;++i){
scanf("%d",&x);
for(k=0;k<size;++k)
if(uset[k]==x) //if x is a nuber of universal set
{
a[k].x=1;
break;
}
}
return;
}
//function to print a set from bit string representation
void printset(struct bit a[]){
int k;
printf("{");
for(k=0;k<size;++k)
if(a[k].x==1)
printf("%d ,",uset[k]);
printf("}\n");
return;
}

//function for union
void unionset(struct bit a[],struct bit b[], struct bit c[])
{
int k;
for(k=0;k<size;++k)
c[k].x=a[k].x | b[k].x;
return;
}
//intersection

void intersectionset(struct bit a[],struct bit b[], struct bit c[])
{
int k;
for(k=0;k<size;++k)
c[k].x=a[k].x & b[k].x;
return;
}
//difference function
void differenceset(struct bit a[],struct bit b[], struct bit c[])
{
int k;
for(k=0;k<size;++k)
if(a[k].x==1)
c[k].x=a[k].x^b[k].x;
return;
}
