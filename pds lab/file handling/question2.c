/*
Name-Dibyendu Biswas
Roll no-19EC10022
Problem no-2
sec-4
*/

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct
	{
		char name1[20];
		char name2[20];
		float price;
	}menu;

int main()
{
	int n;
	FILE *f1,*f2;
	f1=fopen("menu.txt","r");
	if(f1==NULL)
		exit(-1);

    fscanf(f1,"%d",&n);
  	menu *a=(menu*)malloc(n*sizeof(menu));

	for(int i=0;i<n;i++)
	fscanf(f1,"%s%s%f",&a[i].name1,&a[i].name2,&a[i].price);
	fclose(f1);
	f2=fopen("menu_tax.txt","w");
	if(f2==NULL)
		exit(-1);

	for(int i=0;i<n;i++)
		fprintf(f2,"%s %s %f\n",a[i].name1,a[i].name2,a[i].price*1.15);

    fclose(f2);
  	f2=fopen("menu_tax.txt","r");
  char temp[100];
  while((fgets(temp,100,f2)!=NULL)){
    printf("%s",temp);
  }
  char name[100];
	printf("Enter a name:");
  scanf("%s",name);


  int len=strlen(name),t=0;
  for(int i=0;i<n;i++){
  fscanf(f2,"%s%s%f",&a[i].name1,&a[i].name2,&a[i].price);
  for(int j=0;name[j]!='\0';j++){
    if(name[j]==a[i].name1[j]){
        t++;
    }
  }
  if(t==len) printf("%d ",i+1);
  t=0;
 }


 int t2=0;
 for(int i=0;i<n;i++){
 fscanf(f2,"%s%s%f",&a[i].name1,&a[i].name2,&a[i].price);
 for(int j=0;name[j]!='\0';j++){
   if(name[j]==a[i].name2[j]){
       t2++;
   }
 }
 if(t2==len) printf("%d ",i+1);
 t2=0;
}

 printf("\nNow put no of order and order according to serial number:");
 int m,b;
 float total=0.00;
 scanf("%d",&m);
 printf("%f\n", a[2].price);
 for(int i=0;i<m;i++){
    scanf("%d",&b);
    total+=a[b-1].price*1.15;
  }
    printf("Total price: %f \n",total);
	return 0;
}
