/*
Name-Dibyendu Biswas
Roll no-19EC10022
Problem no-3
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
      p =r;
      q = p;
      while(p!=NULL) {
         if (p->next== NULL){
             if (p==r){
               r = p->next;
               printf("Element deleted:%d\n",p->number);
             }
             else  {
               q->next = p->next;
               printf("Element deleted:%d\n",p->number);
             }
              p->next = NULL;
             free(p);
              return r;
          }
        else { q = p;
                p = p->next;
        }
     }
     printf("Stack Overflow(No data)\n");
     return r;
  }


// function to display the front element
void front(struct node *temp){
  printf("Front element:%d\n",temp->number);
}

// function to display the last element
void last(struct node *temp){
  while(temp->next!=NULL){
    temp=temp->next;
  }
  printf("Last element:%d\n",temp->number);
}

int main(){
  struct node*head=NULL;
  int k,x,p;
  printf("Press 1 enque\n2 to deque\n3 to display front element\n4 to display front element\n0 to exit");
  while(1){
    printf("\nPress operation:");
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
    front(head);
      }
    else if(k==4)
    last(head);
    else if(k==0)
    break;
    else
      printf("Invalid operation\n");
  }

}
