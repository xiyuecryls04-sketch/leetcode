#include <iostream>
#include <algorithm>
using namespace std;

struct Edge{
    int to;
    int next;
};


 const int M =3;

const int N =3;

Edge e[M+1];
int edge_count = 0;
int head[N+1];

void add(int u, int v){
    edge_count++;
    e[edge_count].to = v;
    e[edge_count].next = head[u];
    head[u]=edge_count;
}


int num =1;
int dfn[N];
int low[N];
void tarjan(int u, int fa){
    dfn[u]=low[u]=num++;
    for(int i=head[u];i;i=e[i].next){
        int v=e[i].to;
        if(v==fa){
            continue;
        }
        if(!dfn[v]){
            tarjan(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>dfn[u]){
                cout << u << "--" << v << "is a bridge" << endl;
            }

        }
        else{
            low[u]=min(low[u],dfn[v]);
        }
    }

}

int num = 0;
void tarjan1(int u,int fa){
    dfn[u] = low[u] = ++num;
    for(int i = head[u];i;i=e[i].next){
        int v = e[i].to;
        if(!dfn[v]){
            tarjan1(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>dfn[u]){
                cout << u << "--" << v << " is a bridge"<<endl;
            }

        }
        else{
            low[u] = min(low[u],dfn[v]);
        }
    }
}

int main(){
    
   

    for(int i=1;i<=N;i++){
        head[i]=0;
    }

    add(1,2);
    add(2,3);
    add(1,3);

    
    
}
