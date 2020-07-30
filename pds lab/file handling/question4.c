/*
Name-Dibyendu Biswas
Roll no-19EC10022
Problem no-3
sec-4
*/

#include <stdio.h>
#include <stdlib.h>
#include<string.h>


char grade(float n){
  if(n<=100&&n>90)
  return 'A';
  else if(n<=90&&n>80)
  return 'B';
  else if(n<=80&&n>70)
  return 'C';
  else if(n<=70&&n>60)
  return 'D';
  else if(n<=60&&n>50)
  return 'E';
  else if(n<=50&&n>30)
  return 'P';
  else
  return 'F';
}

typedef struct
	{
    int  roll;
		char name[10];
		char surname[10];
		float marks1,marks2,marks3;
  //  float total,avg;
	}stu;
  void merge(stu arr[], int l, int m, int r);
  void mergeSort(stu arr[], int l, int r)
  {
      if (l<r){
          int m = (l+r)/2;
          mergeSort(arr,l,m);
          mergeSort(arr,m+1,r);
          merge(arr,l,m,r);
      }
  }

  void merge(stu arr[], int l, int m, int r)
  {
      int i,j,k;
      int n1 = m - l + 1;
      int n2 = r - m;
      stu L[n1], R[n2];
      for (i = 0; i < n1; i++)
          L[i] = arr[l + i];
      for (j = 0; j < n2; j++)
          R[j]= arr[m + 1 + j];

      i = 0;j = 0;k = l;
      while (i < n1 && j < n2) {
          if (L[i].roll <= R[j].roll) {
              arr[k++]= L[i++];
          }
          else {
              arr[k++]= R[j++];
          }
      }
      /* Copy the remaining elements of L[], if there are any */
      while (i<n1) {
          arr[k++] = L[i++];
      }
      /* Copy the remaining elements of R[], if there are any */
      while (j<n2) {
          arr[k++] = R[j++];
      }
  }
int binarysearch(stu a[],int n,int x){
  int beg=0,mid;
  int end=n;
  while(end>=beg){
     mid=(beg+end)/2;
     if(a[mid].roll==x){
    printf("Position:%d\n",mid+1);
    return mid;
    break;
     }
  if(x<a[mid].roll)
    end=mid-1;
  if(x>a[mid].roll)
    beg=mid+1;
  }
}
void insert(stu a[],int n){
  int  roll;
  char name[10];
  char surname[10];
  float marks1,marks2,marks3;
  printf("Enter roll number:");
  scanf("%d",&roll);
  printf("Enter name:");
  scanf("%s",name);
  printf("Enter surname:");
  scanf("%s",surname);
  printf("Enter marks:");
  scanf("%f%f%f",&marks1,&marks2,&marks3);

  FILE *f1;
  f1=fopen("student.txt","a");
    fprintf(f1,"%d %s %s %f %f %f\n",roll,name,surname,marks1,marks2,marks3);
    fclose(f1);
}
void display(stu a[],int n){
  FILE *f1;
  f1=fopen("student.txt","r");
  char temp2[100];
  while((fgets(temp2,100,f1)!=NULL)){
    printf("%s",temp2);
  }
  fclose(f1);
}
void delete(stu a[],int n) {
  int roll;
  int j;
  printf("Enter the roll number:");
  scanf("%d",&roll);
  FILE *f1;

  int t=binarysearch(a,n,roll); 
  for(j=0;j<n;j++){
    if(j==t){
      while(j<n){
	a[j]=a[j+1];
	j++;
      }
      n--;
    }
  }
  f1=fopen("student.txt","w");
  for(int i=0;i<n;i++){
    fprintf(f1,"%d %s %s %f %f %f\n",a[i].roll,a[i].name,a[i].surname,a[i].marks1,a[i].marks2,a[i].marks3);
  }
  fclose(f1);
}

int main()
{
	int n=0;
	FILE *f1,*f2;
	f1=fopen("student.txt","r");
  if(f1==NULL)
    exit(-1);
  char temp[100];
  while((fgets(temp,100,f1)!=NULL)){
    n++;
  }

  stu *a=(stu*)malloc(sizeof(stu)*n);
  fclose(f1);


  printf("Sorted accorging to Roll\n\n");
  f2=fopen("student.txt","r");
  for(int i=0;i<n;i++){
    fscanf(f2,"%d%s%s%f%f%f",&a[i].roll,&a[i].name,&a[i].surname,&a[i].marks1,&a[i].marks2,&a[i].marks3);
  }
  mergeSort(a,0,n-1);
  fclose(f2);
  f2=fopen("student.txt","w");
  for(int i=0;i<n;i++){
    fprintf(f2,"%d %s %s %f %f %f\n",a[i].roll,a[i].name,a[i].surname,a[i].marks1,a[i].marks2,a[i].marks3);
  }
  fclose(f2);
    f2=fopen("student.txt","r");
  char t[100];
  while((fgets(t,100,f2)!=NULL)){
    printf("%s",t);
  }
  fclose(f2);


  printf("\n\nEnter 1 2 3 4 for search,insertion,deletion and view\n");
  int c,x;
  scanf("%d",&c);
  switch(c){
    case 1:
    //int x;
    printf("Enter roll number:");
    scanf("%d",&x);
    binarysearch(a,n,x);
    break;
    case 2:
   insert(a,n);
    break;
    case 3:
   delete(a,n);
    break;
    case 4:
    display(a,n);
    break;
    default:
    break;
  }

	return 0;
}
