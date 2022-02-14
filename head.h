#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#define max 40

struct infor
{
	char name[15];
	int age;
	char gender[6];
	char num[12];
};

struct list
{
	struct infor me[max];
	int size;
};



void Zero(struct list* ps);
void Add(struct list* ps);
void Show(struct list* ps);
void Del(struct list* ps);
void Modify(struct list* ps);
void Search(struct list* ps);