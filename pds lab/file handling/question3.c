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
    float total,avg;
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
          if (L[i].total <= R[j].total) {
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

int main()
{
	int n=0;
	FILE *f1,*f2;
	f1=fopen("student.txt","r");
  if(f1==NULL)
    exit(-1);
  char temp[100];
  while((fgets(temp,100,f1)!=NULL)){
    printf("%s",temp);
    n++;
  }

  stu *a=(stu*)malloc(sizeof(stu)*n);
  fclose(f1);
  f1=fopen("student.txt","r");

  for(int i=0;i<n;i++){
    fscanf(f1,"%d%s%s%f%f%f",&a[i].roll,&a[i].name,&a[i].surname,&a[i].marks1,&a[i].marks2,&a[i].marks3);
    a[i].total=0;
    a[i].total=a[i].marks1+a[i].marks2+a[i].marks3;
    a[i].avg=a[i].total/3;
  //  printf("%f\n",a[i].avg);
  }
  mergeSort(a,0,n-1);
  f2=fopen("grade.txt","w");
  for(int i=0;i<n;i++){
    fprintf(f2,"%d %s %s %f %c\n",a[i].roll,a[i].name,a[i].surname,a[i].total,grade(a[i].avg));
  }
  fclose(f2);
  f2=fopen("grade.txt","r");
  // printing the file contents of grade.txt
  printf("\n\n*****After sorting*****\n\n");
  char temp2[100];
  while((fgets(temp2,100,f2)!=NULL)){
    printf("%s",temp2);
  }
	return 0;
}
