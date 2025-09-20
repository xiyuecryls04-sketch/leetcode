#include <iostream>

const int maxe = 100;
const int maxn = 100;


struct node{
    int to, next,w;
} edge[maxe];

int head[maxn];

int cnt = 0;
void add(int u, int v, int w){
    edge[cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    cnt++;
}


int main(){
    int u = 0;

    for(int i = head[u];i;i=edge[i].next){
    int v = edge[i].to;
    int w = edge[i].w;
}
    return 0;
}

