#ifndef TEST_H
#define TEST_H
//进行定义 TEST_H是因为要确保该头文件没有被二次使用所进行的“标记”。当然，标记用什么字母都可以（最好大写）
//如果缺少了ifndef 与define，在将头文件嵌入的时候会右二次定义报错的风险，所以要在ifndef 与endif之间写头文件代码
//当然，直接写的应该是函数
//嘛，也是要先写系统自带的头文件来之后再编写自己的函数，而一旦你在这里面写出了头文件，cpp文件里就不用重复写了
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_NUM 10
#define MAX_PHONE 5
#define MAX_GROUP_NAME 10
struct Element
{
	char name[10];
	char phone_num[MAX_PHONE][12];
	int age;
	char address[50];
	char* Group;
};
struct Contact
{
	struct Element *ptr_array;
	int size;
};
//以上是我从咱的cpp文件里抄录下来的，如果直接将该文件定义到咱的cpp里面，会报错，尝试把以上重复内容从咱的cpp里删去试试
//还有一点，记得先从咱的cpp文件里把想写的函数写一遍再移植到这个文件中（比如说下面那个函数）
//不然可能调试起来会有点麻烦（当然你也可以试试直接写在该文件里然后从咱的.cpp里调用）
#endif
