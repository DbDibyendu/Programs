/*
Name-Dibyendu Biswas
Roll no-19EC10022
Problem no-3
sec-4
Machine no-14
Question set - EVEN
Lab Test-2
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

typedef struct
	{
		char name1[20];
		char gender[20];
		float marks;
	}students;

int main()
{
	int n;
	FILE *f1,*f2;
	f1=fopen("t3e.txt","r");
	if(f1==NULL)
		exit(-1);

    fscanf(f1,"%d",&n); // reading n from first line
  	students *a=(students*)malloc(n*sizeof(students));
    // getting all the data
	for(int i=0;i<n;i++)
	fscanf(f1,"%s%s%f",&a[i].name1,&a[i].gender,&a[i].marks);
	fclose(f1);
  float max=0;
  int comp;
  // logic for finding the topper girl student
  for(int i=0;i<n;i++){
    comp=strcmp(a[i].gender,"girl");
    if(a[i].marks>max && comp==0)
      max=a[i].marks;
  }

  f2=fopen("t3e.txt","r");
  char temp[100];

  // printing all the data
  while((fgets(temp,100,f2)!=NULL)){
    printf("%s",temp);
  }

  // printing the topper girl
  for(int i=0;i<n;i++){
  if(max==a[i].marks)
    printf("\nBest girl student: %s.\n",a[i].name1);
  }
	fclose(f2);
	free(a);
	return 0;
}
