void begin()
{
	int x;
	do{
		printf("##################################################\n");
		printf("########    扣①开始游戏   扣②退出游戏   ########\n");
		printf("##################################################\n");
		printf("你的选择是->");
		scanf("%d", &x);
		switch (x){
		case 1:
			Game();
			x = 0;
			break;
		case 2:
			x = 1;
			break;
		default:
			x = 0;
			printf("输入错误，请重新输入\n");
		}

	} while (x == 0);
}
int main()
{
	begin();
	return 0;
}
