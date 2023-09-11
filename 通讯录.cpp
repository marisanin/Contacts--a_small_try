#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_NUM 10
struct Element
{
	char name[10];
	char phone_num[12];
	int age;
	char address[50];
};
struct Contact
{
	struct Element *ptr_array;
	int size;
};
void Init_contact(struct Contact *array)
{
	array->ptr_array = (struct Element*)malloc(sizeof(struct Element)*MAX_NUM);
	array->size = 0;
}
void Insert(struct Contact* P)
{
	if(P->size == MAX_NUM)
	{
		printf("FULL!\n");
		return;
	}
	int postion = P->size;
	////////////
	if(postion >= MAX_NUM||postion < 0)
	{
		printf("ERROR\n");
		return;
	}
	////////////
	printf("//INPUT YOUR ELEMENT'S:\n");
	printf("//NAME:\n");
	scanf("%s",P->ptr_array[postion].name);
	printf("//PHONE NUM:\n");
	scanf("%s",P->ptr_array[postion].phone_num);
	printf("//AGE:\n");
	scanf("%d",&P->ptr_array[postion].age);
	printf("//ADDRESS:\n");
	scanf("%s",P->ptr_array[postion].address);
	P->size++;
}
void Find(struct Contact* P)
{
	char name[10];
	int size = P->size;
	printf("INPUT HIS NAME:");
	scanf("%s",name);
	for(int i = 0;i < size;i++)
	{
		if(0 == strcmp(P->ptr_array[i].name, name))
		{
			int judge = 0;
			printf("FIND! \n");
			printf("NAME:%s\n",P->ptr_array[i].name);
			printf("AGE:%d\n",P->ptr_array[i].age);
			printf("PHONE NUMBER:%s\n",P->ptr_array[i].phone_num);
			printf("ADRESS:%s\n",P->ptr_array[i].address);
			printf("WOULD YOU LIKE TO MAKE A CHANGE TO THIS PAGE? ture(1) OR false(0):  ");
			scanf("%d",&judge);
			if(judge)
			{
				printf("THIS IS UNCOMPLETE YET.\n");
			}
			return;
		}
	}
	printf("DON'T FAND!\n");
}
void Delete(struct Contact* P)
{
	char name[10];
	int size = P->size;
	printf("INPUT HIS NAME:");
	scanf("%s",name);
	for(int i = 0;i < size;i++)
	{
		if(0 == strcmp(P->ptr_array[i].name, name))
		{
			printf("FAND!\n");
			printf("WHENEVER YOU MAKE CHOICE, THINK CAREFULLY.\n");
			P->ptr_array[i] = P->ptr_array[i+1];
			P->size--;
			printf("COMPLETE!\n");
			return;
		}
	}
	printf("NOT FIND!\n");
}
void show_menu()
{
	printf("//////////////////////////////////\n");
	printf("// wellcome to our contact!     //\n");
	printf("// here are some details        //\n");
	printf("// 1 we will create             //\n");
	printf("// 2 we will show you           //\n");
	printf("// 3 we will delete             //\n");
	printf("// 0 we will exit               //\n");
	printf("//////////////////////////////////\n");
}
int main()
{
	struct Contact Unit;
	struct Contact *Ptr_unit;
	int judge = 1;
	//
	Init_contact(&Unit);
	Ptr_unit = &Unit;
	//
	do
	{
		int a = 0;
		show_menu();
		printf("MAKE YOUR CHOICE:\n");
		scanf("%d",&a);
		switch (a) {
		case 1:
			Insert(Ptr_unit);
			break;
		case 2:
			Find(Ptr_unit);
			break;
		case 3:
			Delete(Ptr_unit);
			break;
		case 0:
			judge = 0;
			break;
		default:
			printf("NO EFFECT\n");
			break;
		}
	}while(judge);
	
	return 0;
}
