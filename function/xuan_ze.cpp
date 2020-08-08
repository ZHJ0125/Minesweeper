/*
此部分函数用于用户选择元素，包括三部分： 
1.对用户第一次选择的处理(期望做到无雷化)
2.对用户所选择的元素进行处理   Mine_dig 
3.显示当前元素及周围元素的数值 
4.刷新界面 
*/ 
int bomb=0;
//标记被挖的元素 
void have_dig(int hang,int lie) 
{
	Minefield[hang-1][lie-1] += 20;
}

//对用户所挖的元素进行处理 
void Mine_dig (int hang,int lie)
{
	have_dig(hang,lie);
	if(Minefield[hang-1][lie-1] == ismine) //触雷,标记bomb为 1
	bomb = 1;	
	else if(Minefield[hang-1][lie-1] == 0) //周围八块全都没有地雷,就挖周围的所有八块  
	{
		Mine_dig (hang-1,lie-1);	
		Mine_dig (hang-1,lie);
		Mine_dig (hang-1,lie+1);
		Mine_dig (hang,lie-1);
		Mine_dig (hang,lie+1);
		Mine_dig (hang+1,lie-1);
		Mine_dig (hang+1,lie);
		Mine_dig (hang+1,lie+1);
	}
	else;
}



