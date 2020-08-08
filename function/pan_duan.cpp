/*
此部分函数用于判断程序是否结束，判断： 
1.触雷-->结束
2.全排除-->继续
3.非触雷且非全排除-->继续 
*/ 
//游戏胜利 
void game_win(void)
{
	printf("You win ! \n"); 
}

//游戏结束 
int game_over(void)
{
	char again='n';
	printf("Sorry,you lost \n");
	printf("Do you want to play again ?(y/n)\n");
	scanf("%d",&again);
	if(again == 'y' ) return 1;
	else return 0;
}
 
 
 
 //判断三种情况 
void ji_xu(int biaozhi)
{
	if(biaozhi == 1)
	game_over();
	else if(biaozhi == 0)
	{
		if(notdig == 10)
		game_win();
		else
		;
	}
}

 
