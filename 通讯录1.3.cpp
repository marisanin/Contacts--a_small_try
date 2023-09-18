#include "test.h"
void ADD_MORE_PHONE(struct Contact* P, int postion)//大写的P
{
	//录入的结尾以0输入为截止 
	printf("PHONE NUMBER2：\n");
	scanf("%s", P->ptr_array[postion].phone_num[1]);
}
void Init_contact(struct Contact *array)
{
	array->ptr_array = (struct Element*)malloc(sizeof(struct Element)*MAX_NUM);
	array->size = 0;
	for(int i=0;i<MAX_NUM;i++){
		for(int j=0;j<MAX_PHONE;j++){
			array->ptr_array[i].phone_num[j][0]='\0';
		}
	}
}
void DivdedGruop(struct Element* P)
{
	char *name = (char*)malloc(sizeof(char)*12);
	
	printf("WHICH GROUP HE WILL DIVIDED? IMPUT HIS GROUP\n");
	scanf("%s",name);
	name[11] = '\0';
	P->Group = name;
	printf("COMPLETE!\n");
}
void Insert(struct Contact* P)
{
	int MorePhoneNum = 0;
	int Judge = 0;
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
	//
	printf("//PHONE NUM:\n");
	scanf("%s",P->ptr_array[postion].phone_num[0]);//新增加
	printf("//WOULD YOU LIKE TO INPUT MORE PHONE NUM? RETURN yes(1) OR no(0):\n");
	scanf("%d",&MorePhoneNum);
	if (MorePhoneNum)
	{
		ADD_MORE_PHONE(P,postion);
		//.....需新增
	}
	//
	printf("//AGE:\n");
	scanf("%d",&P->ptr_array[postion].age);
	//
	printf("//ADDRESS:\n");
	scanf("%s",P->ptr_array[postion].address);
	//
	printf("//DIVIDED INTO GROUPS? RETURN yes(1) OR no(0):\n");
	scanf("%d",&Judge);
	if(Judge)
		DivdedGruop(&(P->ptr_array[postion]));
	else
		P->ptr_array[postion].Group = NULL;
	P->size++;
}
void Show(struct Contact* P,int i)
{
	printf("NAME:%s\n",P->ptr_array[i].name);
	printf("AGE:%d\n",P->ptr_array[i].age);
	for (int j = 0; j < MAX_PHONE; j++) 
	{
		if (/*P->ptr_array[i].phone_num[j]!= nullptr && */P->ptr_array[i].phone_num[j][0] != '\0') 
		{
			printf("PHONE NUMBER%d:%s\n", j + 1, P->ptr_array[i].phone_num[j]);
		}
	}
	printf("ADRESS:%s \n",P->ptr_array[i].address);
	printf("GROUP: %s\n",P->ptr_array[i].Group);//error//
	printf("\n");
	
}
void FindSingle(struct Contact* P)
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
			Show(P,i);
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
void FindGroup(struct Contact* P)
{
	char name[MAX_GROUP_NAME];
	int Judge = P->size;
	printf("IMPUT GROUP:\n");
	scanf("%s",name);
	for(int i=0;i < Judge;i++){
		if(strcmp(P->ptr_array[i].Group,name))
			Show(P,i);
	}
}
void Find(struct Contact* P)
{
	int Judge = 0;
	printf("FIND GROUP OF SINGLE? RETURN 0(GROUP) OR 1(SINGLE):\n");
	scanf("%d",&Judge);
	if(Judge)
		FindSingle(P);
	else
		FindGroup(P);
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
