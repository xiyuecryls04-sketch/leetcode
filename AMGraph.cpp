#include <iostream>

using namespace std;

/********************邻接矩阵******************88*/
#define MaxVnum 100
typedef char VexType;
typedef int EdgeType;

typedef struct{
    VexType Vex[MaxVnum];
    EdgeType Edge[MaxVnum][MaxVnum];
    int vexnum, edgenum;
} AMGraph;


int locate(AMGraph G, VexType u){
    for(int i=0;i<G.vexnum;i++){
        if(G.Vex[i]==u){
            return i;
        }
    }
    return -1;
}

void createAMGraph(AMGraph &G){
    int i, j;
    VexType u,v;
    cin >> G.vexnum;
    cin >> G.edgenum;
    for(int i=0;i<G.vexnum;i++){
        cin >> G.Vex[i];
    }
    for(int i=0;i<G.vexnum;i++){
        for(int j=0;j<G.vexnum;j++){
            G.Edge[i][j]=0;
        }
        
    }
    while(G.edgenum--){
        cin >> u >> v;
        i = locate(G, u);
        j = locate(G, v);
        if(i!=-1 && j!=-1){
            G.Edge[i][j] = G.Edge[j][i]=1;
        }
    }
}

/***********边集************ */

const int N = 100;

struct Edge{
    int u;
    int v;
    int w;
} e[N*N];


/***************深度优先搜索*****************8 */

bool visted[MaxVnum];

void DFS_AM(AMGraph G, int v){
    cout << G.Vex[v] << " ";
    visted[v] = true;
    for(int i=0;i<G.vexnum;i++){
        if(G.Edge[v][i]&&!visted[i]){
            DFS_AM(G,i);
        }
    }
}


/*****************广度优先搜索******************************** */
#include <queue>

void BFS_AM(AMGraph G, int v){
    queue<int> q;
    cout << G.Vex[v] << " ";
    q.push(v);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i=0;i<G.vexnum;i++){
            if(G.Edge[u][i]&&!visted[i]){
                cout << G.Vex[i] << " ";
                visted[i] = true;
                q.push(i);
            }
        }
    }
}



