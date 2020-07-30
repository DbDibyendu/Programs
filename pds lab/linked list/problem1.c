/*
Name-Dibyendu Biswas
Roll no-19EC10022
Problem no-1
sec-4
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
  int number;
  struct node* next;
};
// function to insert at the end
struct node* insert_end(struct node *r,int x){
  struct node *temp=(struct node*)malloc(sizeof(struct node));
  struct node *q;
  temp->number=x;
  temp->next=NULL;
  if(r==NULL) return temp;
  q=r;
  while(q->next!=NULL){
    q=q->next;
  }
  q->next=temp;
  return r;
}

// function to insert at beginning
struct node* insert_begin(struct node *r,int x){
  struct node *temp=(struct node*)malloc(sizeof(struct node));
  temp->number=x;
  temp->next=NULL;
  if(r!=NULL) temp->next=r;
  r=temp;
  return r;
}

// function to insert at nth postion
struct node* insert_nth_postion(struct node *r,int x,int n){
  struct node *temp=(struct node*)malloc(sizeof(struct node));
  struct node *q;
  temp->number=x;
  temp->next=NULL;
  if(n==1){
    temp->next=r;
    r=temp;
    return r;
  }
  q=r;
  for(int i=1;i<n-1;i++){
    q=q->next;
  }
  temp->next=q->next;
  q->next=temp;
  return r;
}

// function to find a number and delete it
struct node* delete(struct node *r, int value){
  struct node *p, *q;
    p=r;
    q=p;
    while(p!=NULL) {
       if (p->number == value){
           if (p==r) r = p->next;
         else  q->next = p->next;
           p->next = NULL;
           free(p);
           return r;
        }
      else { q = p;
             p = p->next;
      }
    }
    printf("The number is not found\n");
   return r;
}

// function to search a number and print it's index
int search(struct node *r,int value){
  struct node *p;
  int i=1;
  p=r;
  while(p!=NULL){
    if(p->number==value){
      printf("The number is present in position:%d\n",i);
      return i;
    }
    else{
      i++;
      p=p->next;
    }
  }
  printf("The number is not present in the linked list\n");
}

// function to display the linked list
void display(struct node *temp){
  while(temp!=NULL){
    printf("%d ",temp->number);
    temp=temp->next;
  }
  printf("\n");
}

int main(){
  struct node*head=NULL;
  int k,x,p;
  printf("Press 1 to add a number in beginning\n2 to add from end\n3 to add at nth postion\n4 to delete a number\n5 to search a number\n6 to display a number\n0 to exit\n");
  while(1){
    printf("Press operation:");
    scanf("%d",&k);
    if(k==1){
    printf("Enter the number:");
    scanf("%d",&x);
    head=insert_begin(head,x);
       }
    else if(k==2){
       printf("Enter the number:");
       scanf("%d",&x);
       head=insert_end(head,x);
          }
    else if(k==3){
      printf("Enter the number and positon:");
      scanf("%d%d",&x,&p);
     head=insert_nth_postion(head,x,p);
      }
    else if(k==4){
      printf("Enter the number:");
      scanf("%d",&x);
      head=delete(head,x);
    }
    else if(k==5){
      printf("Enter the number:");
      scanf("%d",&x);
      search(head,x);
    }
    else if(k==6){
      display(head);
    }
    else
      break;

  }

}
