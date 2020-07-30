#include<stdio.h>
#include<stdlib.h>

// defining structure for coordinates
struct node{
  int x;
  int y;
  struct node *nextx;
  struct node *nexty;
};

// function to insert x
struct node* insert_x(struct node* r,int a){
  struct node *temp=(struct node*)malloc(sizeof(struct node));
  temp->x=a;
  temp->nextx=NULL;
  if(r!=NULL) temp->nextx=r;
  r=temp;
  return r;
}

// function to insert y
struct node* insert_y(struct node* r,int b){
  struct node *temp=(struct node*)malloc(sizeof(struct node));
  temp->y=b;
  temp->nexty=NULL;
  if(r!=NULL) temp->nexty=r;
  r=temp;
  return r;
}

// function to print the coordinates..
void printList(struct node *temp1,struct node *temp2,int flag){
  if(flag==0){
    printf("Printing as per X-coordinates: ");
    while(temp1!=NULL){
      printf("%d ",temp1->x);
      temp1=temp1->nextx;
    }
    printf("\n");
  }
  else{
    printf("Printing as per Y-coordinates: ");
    while(temp2!=NULL){
      printf("%d ",temp2->y);
      temp2=temp2->nexty;
    }
    printf("\n");
  }

}

// function to swap next pointers of coordinate x....
struct node* swap_x(struct node* a, struct node* b)
{
    struct node* tmp = b->nextx;
    b->nextx = a;
    a->nextx = tmp;
    return b;
}
// function to swap next pointers of coordinate y....
struct node* swap_y(struct node* a, struct node* b)
{
    struct node* tmp = b->nexty;
    b->nexty = a;
    a->nexty = tmp;
    return b;
}

// Function to sort the list of x coordinate
int bubblesort_x(struct node** head, int n)
{
   struct node** h;
   int i, j, swapped;

   for (i=0;i<=n;i++) {

       h = head;
       swapped = 0;

       for (j=0;j<n-i-1;j++) {

           struct node* p1 = *h;
           struct node* p2 = p1->nextx;

           if (p1->x > p2->x) {

               // swapping the nodes.....coordinates remains the same
               *h = swap_x(p1, p2);
               swapped = 1;
           }

           h = &(*h)->nextx;
       }

       // break if there is no more unswapped element left
       if (swapped==0)
           break;
   }
}

 // Function to sort the list of y coordinate
int bubblesort_y(struct node** head, int n)
{
    struct node** h;
    int i, j, swapped;

    for (i=0;i<=n;i++) {

        h = head;
        swapped = 0;

        for (j=0;j<n-i-1;j++) {

            struct node* p1 = *h;
            struct node* p2 = p1->nexty;

            if (p1->y > p2->y) {

                // swapping the nodes.....coordinates remains the same
                *h = swap_y(p1, p2);
                swapped = 1;
            }

            h = &(*h)->nexty;
        }

        // break if there is no more unswapped element left
        if (swapped==0)
            break;
    }
}

int main(){
  FILE *f1;
  struct node*head_x=NULL;
  struct node*head_y=NULL;
  int a[100],b[100];
  f1=fopen("points.txt","r");
	if(f1==NULL)
		exit(-1);
  for(int i=0;i<50;i++)
	fscanf(f1,"%d%d",&a[i],&b[i]); // storing the elements in an array......
  fclose(f1);

  // Now inserting all the coordinates into the linked list
  for(int i=0;i<50;i++){
  head_x=insert_x(head_x,a[i]);
  head_y=insert_y(head_y,b[i]);
  }

  printList(head_x,head_y,0); // prints x
  printList(head_x,head_y,1); // prints y
  printf("\nAfter sorting: \n");
  bubblesort_x(&head_x,50);
  printList(head_x,head_y,0);
  printf("\n");
  bubblesort_y(&head_y,50);
  printList(head_x,head_y,1);
}
