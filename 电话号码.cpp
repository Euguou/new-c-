#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using std::map;
const int N = 100000+100;
int n;
int ha[(int)'Z'+10];
map<int,int>s;
void init(){
	ha['A']=ha['B']=ha['C']=2;
	ha['D']=ha['E']=ha['F']=3;
	ha['G']=ha['H']=ha['I']=4;
	ha['J']=ha['K']=ha['L']=5;
	ha['M']=ha['N']=ha['O']=6;
	ha['P']=ha['R']=ha['S']=7;
	ha['T']=ha['U']=ha['V']=8;
	ha['W']=ha['X']=ha['Y']=9;
}
inline int rd1(){
	char t=getchar();
	while(!(('0'<=t&&t<='9') || ('A'<=t&&t<='Z'))) t=getchar();
	if('0'<=t&&t<='9') return t-'0';
	return ha[(int)t];
}
inline int rd(){
	int x=0;
	for(int i=1;i<=7;i++) x=x*10+rd1();
	return x;
}
int main(){
	init();
	scanf("%d",&n);
	for(int i=1;i<=n;i++) ++s[rd()];
	bool fir=true;
	for(map<int,int>::iterator it=s.begin();it!=s.end();++it){
		if(it->second==1) continue;
		printf("%03d-%04d %d\n",it->first/10000,it->first%10000,it->second);
		fir=false;
	}
	if(fir) puts("No duplicates.");
	return 0;
}
