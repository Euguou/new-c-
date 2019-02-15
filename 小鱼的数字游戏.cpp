#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
int main()
{
	int i = 0;
	int A[105];
	do {
		++i;
		scanf_s("%d", &A[i]);
	} while (A[i] != 0);
	for (int j = i - 1; j >= 1; j--) printf("%d ", A[j]);
	return 0;
}