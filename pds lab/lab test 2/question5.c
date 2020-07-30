/*
Name-Dibyendu Biswas
Roll no-19EC10022
Problem no-5
sec-4
Machine no-14
Question set - EVEN
Lab Test-2
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node
{
  int number;
  int freq;
  struct node* next;
};

// function to insert at beginning
struct node* insert_begin(struct node *r,int x){
  struct node *temp=(struct node*)malloc(sizeof(struct node));
  struct node *temp2=(struct node*)malloc(sizeof(struct node));
  temp->number=x;
  temp->freq=1; // first initialising each elements frequency as 1
  temp->next=NULL;
  if(r!=NULL) temp->next=r;
  r=temp;
  return r;
}

// function to swap to nodes...
struct node* swap(struct node* a, struct node* b)
{
    struct node* tmp = b->next;
    b->next = a;
    a->next = tmp;
    return b;
}

// function for bubblesort
int bubblesort(struct node** head, int n)
{
   struct node** h;
   int i, j, swapped;

   for (i=0;i<=n;i++) {

       h = head;
       swapped = 0;

       for (j=0;j<n-i-1;j++) {

           struct node* p1 = *h;
           struct node* p2 = p1->next;

           if (p1->number > p2->number) {

               // swapping the nodes.....coordinates remains the same
               *h = swap(p1, p2);
               swapped = 1;
           }

           h = &(*h)->next;
       }

       // break if there is no more unswapped element left
       if (swapped==0)
           break;
   }
}

// function to search a number and just increase the frequency
int search(struct node *r,int value){
  struct node *p;
  int i=1;
  p=r;
  while(p!=NULL){
    if(p->number==value){
      // if the number is already present just increment the frequency
      p->freq++;
      return 0;
    }
    else{
      i++;
      p=p->next;
    }
  }
  return 1;
}

// fucntion to just display the list
void display(struct node *temp){
  while(temp!=NULL){
    printf("%d-%d  ",temp->number,temp->freq);
    temp=temp->next;
  }
  printf("\n");
}

int main()
{
  struct node*head=NULL;
  int n,f=0,x;
  do{
    printf("Enter positive integers: ");
    scanf("%d",&x);
    if(x==0) break;
    if(search(head,x)==1){
    head=insert_begin(head,x);
    f++; // increamenting counter for total number of unique elements added for bubblesort
    }
  }while(1);
  // sorting in increasing order
  bubblesort(&head,f);
  display(head);

  return 0;

}
