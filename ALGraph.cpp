#include <iostream>
using namespace std;
typedef char VexType;

const int MaxVnum = 100;

/************邻接表********* */
// 邻接点
typedef struct AdjNode{
    int v;
    int w;
    struct AdjNode *next;
} AdjNode;

// 节点
typedef struct VexNode{
    VexType data;
    AdjNode *first;
} VexNode;

// 邻接表
typedef struct{
    VexNode Vex[MaxVnum];
    int vexnum, edgenum;
} ALGraph;

int locate1(ALGraph &G, VexType u){
    for(int i=0;i<G.vexnum;i++){
        if(G.Vex[i].data == u){
            return i;
        }
    }
    return -1;
}

void insertedge(ALGraph &G, int i, int j){
    AdjNode *s;
    s = new AdjNode;
    s->v = j;
    s->next = G.Vex[i].first;
    G.Vex[i].first = s;
}


void CreateALGraph(ALGraph &G){
    VexType u,v;
    cin >> G.vexnum >> G.edgenum;
    for(int i=0;i<G.vexnum;i++){
        cin >> G.Vex[i].data;
    }
    for(int i=0;i<G.vexnum;i++){
        G.Vex[i].first=NULL;
    }
    while(G.edgenum--){

        cin >> u >> v;
        int i = locate1(G,u);
        int j = locate1(G,v);
        if(i!=-1&& j!=-1){
            insertedge(G, i, j);
        }
    }
    
}

/******************深度优先搜索************************** */
bool visited[MaxVnum];

void DFS_AL(ALGraph G, int v){
    cout << G.Vex[v].data << " ";
    visited[v] = true;
    AdjNode *p = G.Vex[v].first;
    while(p){
        int w = p->v;
        if(!visited[w]){
            DFS_AL(G,w);
        }
        p = p->next;
    }
}


/********************广度优先搜索**********************************88 */
#include <queue>



void BFS_AL(ALGraph G, int v){
    queue<int> q;
    q.push(v);
    visited[v]=true;
    AdjNode *p;
    cout << G.Vex[v].data << endl;
    while(!q.empty()){
        
        int u = q.front();
        q.pop();
        p=G.Vex[u].first;
        while(!p){
            int w = p->v;
            if(!visited[w]){
                cout << G.Vex[w].data << " ";
                visited[w]=true;
                q.push(w);
            }
            p = p->next;
        }

    }
}