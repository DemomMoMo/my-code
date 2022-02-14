#define _CRT_SECURE_NO_WARNINGS 1
#include"head.h"

void begin()
{
	printf("#########################################################\n");
	printf("#########      ①add           ②del         ############\n");
	printf("#########      ③search        ④modify      ############\n");
	printf("#########      ⑤show          ⑥sort        ############\n");
	printf("#########      〇exit                        ############\n");
	printf("#########################################################\n");
}

enum
{
	exit,
	add,
	del,
	search,
	modify,
	show,
	sort,
};

int main()
{
	struct list ps;
	Zero(&ps);
	begin();
	int cos = 1;
	while (cos!=0){
		printf("请输入你想要服务的数字编号\n");
		scanf("%d", &cos);
		switch (cos){
		case add:
			Add(&ps);
			break;
		case del:
			Del(&ps);
			break;
		case search:
			Search(&ps);
			break;
		case modify:
			Modify(&ps);
			break;
		case show:
			Show(&ps);
			break;
		case exit:
			break;
		default:
			printf("未能识别请重新输入\n");
		}
	}
	return 0;

}