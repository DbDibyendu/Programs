#include<stdio.h>
#include<stdlib.h>

/*
struct node{
  int x;
  int y;
  struct node *nextx;
  struct node *nexty;
};

struct node* insert_begin(struct node* r,int x){
  struct node *temp=(struct node*)malloc(sizeof(struct node));
  temp->number=x;
  temp->next=NULL;
  if(r!=NULL) temp->next=r;
  r=temp;
  return r;
}
*/

int main(){
  FILE *f1;
  int a[100],b[100];
  f1=fopen("points.txt","r");
	if(f1==NULL)
		exit(-1);
  for(int i=0;i<50;i++)
	fscanf(f1,"%d%d",&a[i],&b[i]);
  fclose(f1);
  printf("%d", a[0]);
  for(int i=0;i<50;i++)
  printf("%d %d\n",a[i],b[i]);
}
