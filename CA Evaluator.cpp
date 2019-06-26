#include<stdio.h>
#include<conio.h>
#include<string.h>
void create_record(char*,char*,long int,int,int,int,int,int);
void search_record(char*,char*,int,int,int,int,int,int);
void modify_record(char*,char*,int,int,int,int,int,int);
int main()
{
	FILE *fp;
	char name[50],str[20];
	int ca1,ca2,ca3,ca4,i,j=0,n,k,x,r;
	long int regno;
	printf("\n enter file name");
	scanf("%s",str);
	printf("How Many Records :");
	scanf("%d",&n);
	create_record(name,str,regno,ca1,ca2,ca3,ca4,n);
	printf("\n press 1 to search the record press 2 to continue to next step");
	scanf("%d",&x);
	switch(x)
	{
		case 1:
		search_record(name,str,regno,n,ca1,ca2,ca3,ca4);
		break;
		case 2:	
		break;
		default:
		printf("\n enter a valid option");	
		}
		printf("\n enter 1 to modify 2 to continue");
		scanf("%d",&r);
		switch(r)
		{
			case 1:
			modify_record(name,str,regno,n,ca1,ca2,ca3,ca4);
			break;
			case 2:
			break;	
				}		
	
}
void create_record(char name[50],char str[20],long int regno,int ca1,int ca2,int ca3,int ca4,int n)	
	{
		struct
	{
		char name[50];
		int ca1,ca2,ca3,ca4;
		long int regno;
	}stud[77];
	int i,j=0;
	FILE *fp;
	fp=fopen(str,"w");
		for (i=0;i<n;i++)
		{
			printf("Name :");
			scanf("%s",&stud[i].name);
			printf("\n reg no :");
			scanf("%ld",&stud[i].regno);
			printf("enter ca1,ca2,ca3,ca4 marks");
			scanf("%d %d %d %d",&stud[i].ca1,&stud[i].ca2,&stud[i].ca3,&stud[i].ca4);
		}
		while(j<n)
		{
			fwrite(&stud,sizeof(stud),1,fp);
			j++;
		}
		
	fclose(fp);
}
void search_record(char name[50],char str[20],int regno,int n,int ca1,int ca2,int ca3,int ca4)
{
	struct
	{
		char name[50];
		int ca1,ca2,ca3,ca4;
		long int regno;
	}stud[77];
	printf("\n %s %d",str,n);
	FILE *fp;
	fp=fopen(str,"r+");
	int i;
	long int k;
	printf("\n enter registration number");
	scanf("%ld",&k);
	for (i=0;i<n;i++)
	{
		if (k==stud[i].regno)
		{
			fscanf(fp,"%s",stud[i].name);
			printf("\n name is");
			puts(stud[i].name);
			fscanf(fp,"%ld",stud[i].regno);
			printf("\n regno is :%d",stud[i].regno);
			fscanf(fp,"%d",stud[i].ca1);
			printf("\n ca1 marks are %d",stud[i].ca1);
			fscanf(fp,"%d",stud[i].ca2);
			printf("\n ca2 marks are %d",stud[i].ca2);
			fscanf(fp,"%d",stud[i].ca3);
			printf("\n ca3 marks are %d",stud[i].ca3);
			fscanf(fp,"%d",stud[i].ca4);
			printf("\n ca4 marks are %d",stud[i].ca4);
		}
	}
	fclose(fp);
}
void modify_record(char name[50],char str[20],int regno,int n,int ca1,int ca2,int ca3,int ca4)
{
	struct
	{
		char name[50];
		int ca1,ca2,ca3,ca4;
		long int regno;
	}stud[77];
	printf("\n %s %d",str,n);
	FILE *fp;
	fp=fopen(str,"w+");
	long int k,t;
	char newname[50];
	int i,y,temp;
	printf("\n enter the registration number to be modified");
	scanf("%d",&k);
	for (i=0;i<=n;i++)
	{
		fscanf(fp,"%ld",stud[i].regno);
		printf("\n %ld",stud[i].regno);
		if (k==stud[i].regno)
		{
			printf("\n press 1 to modify name press 2 to modify regno press 3 to modify ca1 marks press 4 to modify ca2 marks press 5 to modify ca3 marks press6 to modify ca4 marks ");
			scanf("%d",&y);
			switch (y)
			{
				case 1:
					printf("enter new name :");
					gets(newname);
					strcpy(stud[i].name,newname);
					fputs(stud[i].name,fp);
					break;
				case 2:
				printf("\n enter new registration number");
				scanf("%d",&k);
				t=stud[i].regno;
				fprintf(fp,"%ld",stud[i].regno);
				break;
				case 3:
				printf("\n enter new ca1 marks");
				scanf("%d",&temp);
				temp=stud[i].ca1;
				fprintf(fp,"%ld",stud[i].ca1);
				break;
				case 4:
				printf("\n enter new ca2 marks");
				scanf("%d",&temp);
				temp=stud[i].ca2;
				fprintf(fp,"%ld",stud[i].ca2);
				break;
				case 5:
				printf("\n enter new ca3 marks");
				scanf("%d",&temp);
				temp=stud[i].ca3;
				fprintf(fp,"%ld",stud[i].ca3);
				case 6:
				printf("\n enter new ca4 marks");
				scanf("%d",&temp);
				temp=stud[i].ca4;
				fprintf(fp,"%ld",stud[i].ca4);
				case 7:
				break;
				default :
				printf("\n as valid option is not entered proceeding to next step");	
			}
		}
	}
	fclose(fp);
}
