#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
using namespace std;

const int N = 1010;

int n;
map<string,vector<int> >mp; 
int m;
int main(){
	ios::sync_with_stdio(false);
	string s;
	cin>>n;
	for(int i=1,l;i<=n;i++){
		cin>>l;
		while(l--){
			cin>>s;
			mp[s].push_back(i);
		}
	}
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>s;
		bool fir=true;
		for(int k=0;k<(int)mp[s].size();k++){
			if(k==0||mp[s][k]!=mp[s][k-1]){
				if(fir){
					cout<<mp[s][k];
					fir=false;
				}else cout<<" "<<mp[s][k];
			}
		}
		cout<<endl;
	}
	return 0;
}
