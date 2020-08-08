/*
此部分函数用于初始化布局，包括三部分功能：
1.初始化原数组为无雷 Mine_init
2.实现随机分布的雷区(限制个数) Mine_random
3.遍历记录数组元素数值(用于记录是否有雷) Mine_show
4.界面显示雷区  Figure_show  
*/ 

//初始化一个10*10的雷区数组
#include<stdio.h> 
#include<stdlib.h> 
#include<time.h> 
#define ismine 11
int notdig=0;
short int Minefield[10][10];
void Mine_init(void)
{
	//初始化雷区为0
	int m,n;
	srand(time(NULL));
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			Minefield[i][j] = 0 ; 
		}
	}
	//开始布置地雷 
	for(int i=0; i<10; i++)
	{
		m=rand()%10;		//产生 0 ~ 9之间的随机数 m,n  
		n=rand()%10;
		Minefield[m][n]=ismine;
	}
	for(int i=0; i<10; i++)
	{
		for(int j=0; j<10; j++)
		{
			if(Minefield[i][j] < ismine)  //如果此元素不是地雷
			{
				if(Minefield[i-1][j-1] == ismine )
					Minefield[i][j]++;
				if(Minefield[i-1][j] == ismine )
					Minefield[i][j]++;
				if(Minefield[i-1][j+1] == ismine )
					Minefield[i][j]++;
				if(Minefield[i][j-1] == ismine )
					Minefield[i][j]++;
				if(Minefield[i][j+1] == ismine )
					Minefield[i][j]++;
				if(Minefield[i+1][j-1] == ismine )
					Minefield[i][j]++;
				if(Minefield[i+1][j] == ismine )
					Minefield[i][j]++;
				if(Minefield[i+1][j+1] == ismine )
					Minefield[i][j]++;
			}
		}
}

 
//记录数组元素数值  
/*void Mine_count (void)
{
	//Mine_random();
	for(int i=0; i<10; i++)
	{
		for(int j=0; j<10; j++)
		{
			if(Minefield[i][j] < ismine)  //如果此元素不是地雷
			{
				if(Minefield[i-1][j-1] == ismine )
					Minefield[i][j]++;
				if(Minefield[i-1][j] == ismine )
					Minefield[i][j]++;
				if(Minefield[i-1][j+1] == ismine )
					Minefield[i][j]++;
				if(Minefield[i][j-1] == ismine )
					Minefield[i][j]++;
				if(Minefield[i][j+1] == ismine )
					Minefield[i][j]++;
				if(Minefield[i+1][j-1] == ismine )
					Minefield[i][j]++;
				if(Minefield[i+1][j] == ismine )
					Minefield[i][j]++;
				if(Minefield[i+1][j+1] == ismine )
					Minefield[i][j]++;
			}
		}
	}
	*/ 
	/*for(int i=0; i<10; i++)
	{
		for(int j=0; j<10; j++)
		{
			if(Minefield[i][j] >= ismine) 
			{
				Minefield[i][j] = ismine;
			}
		}
	}*/
	
	/*for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			printf("%d ",Minefield[i][j]);
			if(j == 9) printf("\n"); 
		}
	}*/
}

//显示当前雷区状态  
void Figure_show (void)
{
	for(int i=0; i<10; i++)
	{
		for(int j=0; j<10; j++)
		{
			if(Minefield[i][j] >= 50) //被挖到过  
			{
				if(Minefield[i][j] - 50 == ismine )
					printf(" X "); 
				else if(Minefield[i][j] == 50)
					printf("   ");
				else
					printf(" %d ",Minefield[i][j] - 50 );
			}
			else
			{
				printf(" * ");
			}
		}
		printf(" \n");
	}
}

//最初界面的显示 
void init_show ()
{
	printf("************************************************\n");
	printf("*                                              *\n");
	printf("*          Welcome  to  this  game             *\n");
	printf("*                                              *\n");
	printf("************************************************\n");
}


/**************************************************************************/
/*
此部分函数用于判断程序是否结束，判断： 
1.触雷-->结束
2.全排除-->继续
3.非触雷且非全排除-->继续 
*/ 
//游戏胜利 
/*void game_win(void)
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
*/
 
 
 
 //判断三种情况 
int pan_duan(void)
{
	int result=0;
	for(int i=0;i < 10 ;i ++)
	{
		for(int j; j <= 10 ; j ++)
		{
			if(Minefield[i][j] != ismine )
			{
				if(Minefield[i][j] == ismine+50 )
					return 1;
				if(Minefield[i][j] < 50 )
					result = 2;
			}
		}
	}
	return result;
}

 

//对用户所挖的元素进行处理 
void Mine_dig (int hang,int lie)
{
	if(hang>=0&&hang<=9&&lie>=0&&lie<=9)
		if(Minefield[hang][lie] <= 50 )		//如果没有被挖过
		{
			Minefield[hang][lie] += 50 ; 	//标记该元素被挖了			
			if(Minefield[hang][lie] == 50 )
			{
				if(Minefield[hang-1][lie] < 50 )
					Mine_dig (hang-1,lie);
				if(Minefield[hang+1][lie] < 50 )
					Mine_dig (hang+1,lie);
				if(Minefield[hang][lie-1] < 50 )
					Mine_dig (hang,lie-1);
				if(Minefield[hang][lie+1] < 50 )
					Mine_dig (hang,lie+1);
			}
		}
}

int main()
{
	int hang=0,lie=0,i=0;
	Mine_init();
	//Mine_count ();
	init_show ();
	Figure_show ();
	while(1)
	{
		printf("please input hang and lie(1~10) ：");
		scanf("%d %d",&hang,&lie);
		//fflush(stdout);
		Mine_dig (hang-1,lie-1);
		Figure_show ();
		i=pan_duan(); 
		if(i == 1 )
		{
			printf("\n~~~~gameover!~~~~~\n"); 
			break; 
		}
		if(i == 0 )
		{
			printf("\n~~~~gamewin!~~~~~\n"); 
			break; 
		}
	}
	return 0;
}
 
