/*主函数,开始和结束游戏*/
short int Minefield[10][10]={0};
#include "init.cpp"
#include "xuan_ze.cpp"
#include "pan_duan.cpp"

int main()
{
	int m,n;
	init_show ();
	Mine_random ();
	Mine_show ();
	Figure_show ();
	scanf("%d %d",&m,&n);
	Mine_dig (m,n);
	return 0;
}
