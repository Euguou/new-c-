#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
struct note{
    string s;
    int y, m, d, num;
}f[100];
bool cmp ( note a, note b ){
    if ( a.y == b.y ){
        if ( a.m == b.m ){
            if ( a.d == b.d ) return a.num > b.num;
            else return a.d < b.d;
        }
        else return a.m < b.m;
    }
    else return a.y < b.y;
}
int n;
int main(){
    scanf ( "%d", &n );
    for ( int i = 1; i <= n; i++ )
    cin >> f[i].s >> f[i].y >> f[i].m >> f[i].d, f[i].num = i;
    sort ( f+1, f+n+1, cmp );
    for ( int i = 1; i <= n; i++ )
    cout << f[i].s << endl;
    return 0;
}
