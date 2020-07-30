#include<stdio.h>
#include<stdlib.h>
struct Node{
  int data;
  struct Node* next;
};
struct Node* head; //global variable
void insert(int x){
   struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
   temp->data=x;
   temp->next=NULL;
   if(head!=NULL) temp->next=head;
   head=temp;
}
void print(){
  struct Node*temp=head;
  printf("\nThe list is:");
  while(temp!=NULL){
    printf("%d ", temp->data);
    temp=temp->next;
  }
}

int main()
{
    head = NULL;
  printf("How many numbers");
  int n,i,x;
  scanf("%d",&n);
  for(i=0;i<n;i++){
      printf("\nEnter the number ");
      scanf("%d", &x);
      insert(x);
      print();
  }
  return 0;
}
