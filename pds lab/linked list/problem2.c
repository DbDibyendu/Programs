/*
Name-Dibyendu Biswas
Roll no-19EC10022
Problem no-2
sec-4
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
  int number;
  struct node* next;
};

// function to insert at beginning
struct node* insert_begin(struct node *r,int x){
  struct node *temp=(struct node*)malloc(sizeof(struct node));
  temp->number=x;
  temp->next=NULL;
  if(r!=NULL) temp->next=r;
  r=temp;
  return r;
}

// function to delete number from top
struct node* delete(struct node *r){
  struct node *p, *q;
    p=r;
    if(p==NULL){
      printf("Stack Underflow\n");
    }
    else{
      r=p->next;
      printf("The number deleted is:%d\n",p->number);
      p->next=NULL;
      return r;
    }
}

// function to display the top element
void top(struct node *temp){

    printf("top element:%d\n",temp->number);
}


int main(){
  struct node*head=NULL;
  int k,x,p;
  printf("Press 1 Push\n2 to Pop\n3 to display top element\n0 to exit\n");
  while(1){
    printf("Press operation:");
    scanf("%d",&k);
    if(k==1){
    printf("Enter the number:");
    scanf("%d",&x);
    head=insert_begin(head,x);
       }

    else if(k==2){
       head=delete(head);
          }
    else if(k==3){
    top(head);
      }
    else if(k==0){
      break;
    }
    else
      printf("Invalid operation\n");
  }

}
