#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
int a[1000100], b[100001], N;
int main()
{
	scanf_s("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		scanf_s("%d", &a[i]);
	}
	for(int i = 1; i <= N; i++)
		for (int j = i; j >= 1; j--)
		{
			if (a[j] < a[i])
				b[i]++;
		}
	for (int i = 1; i <= N; i++) cout << b[i] << " ";
	return 0;
}