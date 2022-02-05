#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

struct Ga
{
	char Name[20];
	int price = 0;
};

void swap(char*ele1, char*ele2, int lon)
{
	int i = 0;
	for (i = 0; i < lon; i++)
{
		*ele1 ^= *ele2;
		*ele2 ^= *ele1;
		*ele1 ^= *ele2;
		ele1++;
		ele2++;
	}
}

int arr_int(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}

int arr_sturct(const void* e1, const void* e2)
{
	return ((struct Ga*)e1)->price - ((struct Ga*)e2)->price;
}

int arr_float(const void* e1, const void* e2)
{
	if (*(float*)e1 == *(float*)e2)
		return 0;
	else if ((*(float*)e1 - *(float*)e2)>0)
		return 1;
	else
		return -1;
}


void my_qq(void*base, int sz, int lon, int(*fc)(const void* e1, const void* e2))
{
	int i = 0;
	for (i = 0; i < sz - 1; i++)
	{
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (fc((char*)base + j*lon, (char*)base + (j + 1)*lon) > 0)
			{
				swap((char*)base + j*lon, (char*)base + (j + 1)*lon, lon);
			}
		}
	}
}



int main()
{
	int arr1[] = { 2, 1, 4, 5, 8, 7 };
	int sz;
	sz = sizeof(arr1) / sizeof(arr1[0]);
	my_qq(arr1,sz,sizeof(arr1[0]),arr_int);
	//qsort(arr1, sz, sizeof(arr1[0]), arr_int);
	int i;
	for (i = 0; i < sz; i++)
	{
		printf("%d ",arr1[i]);
	}
	return 0;
}
