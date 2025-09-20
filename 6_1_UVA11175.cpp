#include <iostream>

using namespace std;

#define REP(i,b,e) for(int i=(b);i<(e);i++)

const int maxn = 100;

int g[maxn][maxn];

bool solve(){
    int n;
    cin >> n;
    REP(i,0,n){
        REP(j,0,n){
            bool flag1 = false, flag2 = false;
            REP(k,0,n){
                if(g[i][k]&&g[k][j]){
                    flag1 = true;
                }
                if(g[i][k]^ g[k][j]){
                    flag2 = true;
                }
            }
            if(flag1 && flag2){
                return false;
            }
        }
    }
    return true;
       
}