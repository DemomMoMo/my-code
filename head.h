#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>
#define Def 3


typedef struct infor
{
	char name[13];
	int age;
	char gender[6];
	char num[12];
}infor;

typedef struct list
{
	 infor *me;
	int size;
	int space;
}list;


void Add(list* ps);
void Show(list* ps);
void Del(list* ps);
void Modify(list* ps);
void Search(list* ps);
void Sort(list* ps);
void Fir(list* ps);
void Save(list*ps);
infor* Sec(list* ps, int n);
void Ed(list*ps);
void Read(list*ps);
