/*
Name-Dibyendu Biswas
Roll no-19EC10022
Problem no-4
sec-4
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
  char data;
  struct node* next;
};

// Function to insert char at the beginning
struct node* stackPush(struct node *q,char x){
  struct node *temp=(struct node *)malloc(sizeof(struct node));
  temp->data=x;
  temp->next=NULL;
  if(q!=NULL) temp->next=q;
  q=temp;
  return q;
}

// function to Pop the front char
struct node* stackPop(struct node *r){
  struct node *p, *q;
    p=r;
    if(p==NULL){
      	printf("stack underflow");
    }
    else{
      r=p->next;
      p->next=NULL;
      return r;
    }
}


int empty(struct node *head)
{
    if(head==NULL)
		return 1;
	else
		return 0;
}

// logic for getting the correct sequence of brackets
int checking(char s[],struct node *head){
	int i=0;
	while(s[i]!='$'){
		if(s[i]=='(')
		head=stackPush(head,'(');


		if(s[i]==')' && empty(head))
			return 0;
	   else if(s[i]==')') // stackPopping the last opening bracket if ")" is found
	    	head=stackPop(head);
	  	i++;
	}


	if(head==NULL)
		return 1;
	 else
	 	return 0;
    
}

int main(){
  struct node*head=NULL;
  char string[100];
  printf("enter the string ending with ($): ");
  scanf("%s",string);
  int n;
  n=strlen(string);
  if(string[n-1]=='$'){
  if(checking(string,head))
  	printf("Balanced");
  else
  	printf("Unbalanced");
  }
  else
   printf("Enter a valid string(ending with $)");
return 0;
}
