/*
Name-Dibyendu Biswas
Roll no-19EC10022
Problem no-5
sec-4
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct
{
  int p,t;
}job;

struct node
{
  job number;
  struct node* next;
};

// function to insert at beginning
struct node* insert_begin(struct node *r,int x,int y){
  struct node *temp=(struct node*)malloc(sizeof(struct node));
  temp->number.p=x;
  temp->number.t=y;
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
               // printf("Element deleted:%d\n",p->number.p);
             }
             else  {
               q->next = p->next;
               // printf("Element deleted:%d\n",p->number.p);
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


//function to print all elements
void print(struct node *temp){
  printf("\nPrinted:");
  while(temp!=NULL){
    printf("(%d,%d) ",temp->number.p,temp->number.t);
    temp=temp->next;
  }
  printf("\n");
}

// function to swap
void swap(struct node *a, struct node *b){

    job temp = a->number;
    a->number = b->number;
    b->number = temp;
}

// function to perform bubblesort in non increasing order
struct node* bubblesort(struct node *r){
      int swapping, i;
      struct node *p;
      struct node *left= NULL;
      // Checking for empty list
      if (r == NULL)
          return r;
          // logic for bubblesort
      do
      {
          swapping= 0;
          p= r;

          while (p->next != left)
          {
          if (p->number.p < p->next->number.p)
              {
                  swap(p, p->next);
                  swapping++;
              }
              p = p->next;
          }
          left = p; // pointing left to the next pointer from the right end
      }
      while(swapping); // iterating until there is no swapping left,means the array is sorted
      return r;
}


int main(){
  struct node*head=NULL;
  int k,x,p,y,count=0;
  printf("Press 1 enque\n2 to deque\n0 to exit");
  while(1){
    printf("\nPress operation:");
    scanf("%d",&k);
    if(k==1){
    printf("Enter the job in format (p,t):");
    scanf("%d%d",&x,&y);
    head=insert_begin(head,x,y);
    count++;
       }

    else if(k==2){
       head=delete(head);
          }
    else if(k==0)
    break;
    else
      printf("Invalid operation\n");
  }
  head=bubblesort(head);
  print(head);

  // deleting all the elements from Q
  while(count--){
    head=delete(head);
  }

}
