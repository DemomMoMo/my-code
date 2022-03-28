#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<string.h>


typedef struct tleaves{
	int tl, tr; //左右结点
	int X;//当前序号
	char date;//内容
}tleaves;

typedef struct tree{
	tleaves* psf;
	int leaf_num;
}tree;

void init_tree(tree* ps, FILE* pf,int n)
{
	int i;
	ps->leaf_num = n;
	ps->psf = (tleaves*)malloc(n*sizeof(tleaves));
	for (i = 0; i < n; i++)
	{
		ps->psf[i].date = fgetc(pf);
		fgetc(pf);
		ps->psf[i].tl = fgetc(pf);
		fgetc(pf);
		ps->psf[i].tr = fgetc(pf);
		fgetc(pf);
	}
}

int main()
{
	printf("请输入文件名已导入二叉树\n");
	FILE* pf = NULL;
	char pfc[20];
	scanf("%c", &pfc);
	pf = fopen(pfc, "wr");
	while (pf == NULL)
	{
		printf("未能成功打开,请重新输入文件名 \n");
		scanf("%c",pfc);
		pf = fopen(pfc, "wr");
	}
	printf("请输入二叉树的项数\n");
	int tn = 0;
	scanf("%d",&tn);
	tree ps;
	init_tree(&ps, pf,tn);

	return 0;
}
