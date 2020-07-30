/*
Name-Dibyendu Biswas
Roll no-19EC10022
Problem no-1
sec-4
*/

#include <stdio.h>
#include <stdlib.h>

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
    printf("%d\n",n);
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
	fclose(f2);
	free(a);
	return 0;
}
