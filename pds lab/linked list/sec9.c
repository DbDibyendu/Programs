#include<string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
	{
		char name[20];
		int roll;
	}tele;

struct node{
  tele data;
  struct node *next;
};

struct node* insert_begin(struct node *r,tele x){
  struct node *temp=(struct node*)malloc(sizeof(struct node));
  temp->data=x;
  temp->next=NULL;
  if(r!=NULL) temp->next=r;
  r=temp;
  return r;
}

void print(struct node *temp){
  while(temp!=NULL){
    printf("%d %s\n",temp->data.roll,temp->data.name);
    temp=temp->next;
  }
  printf("\n");
}

void sortedInsert(struct node**, struct node*);

void insertionSort(struct node **head_ref)
{

    struct node *sorted = NULL;
    struct node *current = *head_ref;
    while (current != NULL)
    {
        struct node *next = current->next;
        sortedInsert(&sorted, current);
        current = next;
    }
    *head_ref = sorted;
}

void sortedInsert(struct node** head_ref, struct node* new_node)
{
    struct node* current;
    if (*head_ref == NULL || (*head_ref)->data.roll >= new_node->data.roll)
    {
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
    else
    {
        current = *head_ref;
        while (current->next!=NULL && current->next->data.roll < new_node->data.roll)
        {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

void swap(struct node *a, struct node *b)
{
    char *name=malloc(20*sizeof(char));
    strcpy(name,a->data.name);
    strcpy(a->data.name,b->data.name);
    strcpy(b->data.name,name);
}

void sortList(struct node *head)
{
    int swapped;
    struct node *p;
    struct node *lp=NULL;
    do
    {
        swapped=0;
        p=head->next;
        while(p->next!=lp)
        {
            if(strcmp(p->data.name,p->next->data.name)>0)
            {
                swap(p,p->next);
                swapped=1;
            }
            p=p->next;
        }
        lp=p;
    }while(swapped);
}

struct node *splitList(struct node **head)
{
    struct node *pivot;
    pivot=*head;
    sortList(pivot);
    struct node *q;
    struct node *head2;
    q=pivot->next;
    pivot->next=NULL;
    head2=q;
    return(head2);
}

void joinList(struct node *head1, struct node *head2)
{
    struct node *p;
    struct node *q;
    p=head1;
    while(p->next!=NULL)
    {
        q=p;
        p=p->next;
    }
    if(p->next==NULL)
    {
        p->next=head2;
    }

}



int main()
{
  struct node*list=NULL;
	struct node*head2=NULL;
	int n;
	FILE *f1,*f2;
	f1=fopen("directory.txt","r");
	if(f1==NULL)
		exit(-1);
  n=50;
	tele *a=(tele*)malloc(n*sizeof(tele));
	for(int i=0;i<n;i++)
	fscanf(f1,"%d%s",&a[i].roll,&a[i].name);
  fclose(f1);
  for(int i=0;i<n;i++)
     list=insert_begin(list,a[i]);
  insertionSort(&list);
	print(list);
  head2=splitList(&list);
	printf("splitList is:\n");
	print(head2);
	joinList(list,head2);
	printf("joint lis is:\n");
	print(list);

}
