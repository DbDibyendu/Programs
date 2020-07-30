/*M.Bhavani Patel
Section-9
Roll Number-19BT10015
Place-Hyderabad*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char *name;
    int no;
} tele;

typedef struct _node {
    tele data;
    struct _node *next;
}node;

node *h2;

node *createlist(tele list[])
{
  int i;
  node *p,*head;
  for(i=0;i<50;i++)
  {
      if(i==0)
      {
          head= (node *)malloc(sizeof(node));
          p=head;
      }
      else
      {
          p->next=(node *)malloc(sizeof(node));
          p=p->next;
      }
      p->data=list[i];
  }
  //p->next=NULL;
  return(head);
}

void insertion( node *h)
{
    if(h== NULL || h->next == NULL)
    {
       return;
    }
    node *t1 = h;
    tele temp;
    //int found = 0;
    node *t2 = t1;
    h=h->next;
    while(h!= NULL)
    {
        t2=t1;
        while(t2 != h)
        {
            if(t2->data.no > h->data.no)
            {
                temp = h->data;
                h->data = t2->data;
                t2->data=temp;
            }
            /*else
            {
                if(found == 1) {
                    tele temp1 = temp;
                    temp = t2->data;
                    t2->data = temp1;
                }
                //t2 = t2->next;
            }*/
            t2=t2->next;
       }
       h = h->next;
    }
}

node *splitList(node *head)
{
    node *p;
    p=head->next;
    node *pivot=head;
    node *x=pivot,*y=NULL;
    while(p!=NULL)
    {
        if(strcmp(pivot->data.name,p->data.name)>=0)
        {
            x->next=p;
            x=x->next;
        }
        else
        {
            if(y==NULL)
            {
                h2=p;
                y=h2;
            }
        else
           {
                y->next=p;
                y=y->next;
           }
        }
        p=p->next;
    }
    x->next=NULL;
    y->next=NULL;
}

node *joinList(node *p1,node *p2)
{
    node *p,*x;
    p=p1;
    if(p1!=NULL)
    {
        if(p2==NULL)
        {
            return p1;
        }
        else
        {
            while(p->next!=NULL)
            {
                p=p->next;
            }
            p->next=p2;
            return p1;
        }
    }
    else
    {
        if(p2!=NULL)
        {
            return p2;
        }
        else return NULL;
    }
}

void display(node *head)
{
 int count=1;
 node *p;
 p=head;
 while(p!=NULL)
 {
     printf("\nNode %d: %d %s",count,p->data.no,p->data.name);
     count++;
     p=p->next;
 }
 printf("\n");
}

int main()
{
    FILE *fp;
    node *h1,*h3;
    tele *list;
    char x[50];
    int i,c;
    fp=fopen("directory.txt","r");
    if(fp==NULL)
    {
        printf("NO");
        exit(-1);
    }

    if((list=(tele *)malloc(50*sizeof(tele)))==NULL)
    {
         printf("NO");
         exit(-1);
    }
    for(i=0;i<50;i++)
    {
        fscanf(fp,"%d%*c%s",&list[i].no,x);
        c=strlen(x);
        c++;
        if((list[i].name= (char *)malloc((c)*sizeof(char)))==NULL)
        {
             printf("NO");
             exit(-1);
        }
        strcpy(list[i].name,x);
    }
    printf("List sorted as per the numbers:");
    h1= createlist(list);
    insertion(h1);
    display(h1);
    printf("List consisting the pivot element:");
    splitList(h1);
    display(h1);
    printf("List not consisting the pivot element:");
    display(h2);
    printf("List after joining the two lists:");
    h3=joinList(h1,h2);
    display(h3);
    fclose(fp);
    return 0;

}
