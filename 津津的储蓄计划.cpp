#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
int money = 0, cost, flag = 1, monthdeath,piese;
int main()
{
	for (int i = 1; i <= 12; i++)
	{
		money += 300;
		scanf_s("%d", cost);
		money -= cost;
		if (money < 0)
		{
			flag = 0;
			monthdeath = i;
			break;
		}
		piese += money / 100;
		money %= 100;
	}
	if (flag == 1)     
	{
		money += piese * 120;    
		printf("%d", money);
	}
	else
	{
		printf("%d", -monthdeath);
	}
	return 0;
}