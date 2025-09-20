#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 100005;

struct Edge{
    int to, next;
}e[maxn];

int head[maxn];


int cnt=0;
void add(int u, int v){
    e[++cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

int maxx[maxn];

void dfs(int u,int v){
    if(maxx[v]){
        return;
    }
    maxx[v] = u;
    for(int i= head[v];~i;i=e[i].next){
        int v1 = e[i].to;
        dfs(u,v1);
    }
}

int main(){
    int n, m,x,y;
    cin >> n >> m;
    memset(head,-1,sizeof(head));
    memset(maxx,0,sizeof(maxx));
    for(int i =0;i<m;i++){
        cin >> x >> y;
        add(y,x);
    }
    for(int i=n;i;i--){
        dfs(i,i);
    }
    for(int i=1;i<=n;i++){
        if(i!=1){
            cout << " ";
        }
        cout << maxx[i];
    }
    return 0;
}