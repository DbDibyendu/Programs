/*
Name-Dibyendu Biswas
Roll no-19EC10022
Problem no-4
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

// function to swap
struct node* swap(struct node* a, struct node* b)
{
    struct node* tmp = b->next;
    b->next = a;
    a->next = tmp;

}

// function to perform double sort
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
          if (p->number > p->next->number)
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
  int n,x;
  while(1){
      printf("Enter elements:\n");
      scanf("%d",&x);
      if(x==0){
        printf("List ends.\n");
        break;
      }
      head=insert_begin(head,x);
      printf("List contains:");
      display(head);
  }
  printf("List contains:");
  display(head);
  printf("After sorting\n");
  head=bubblesort(head);
  printf("List contains:");
  display(head);

}
