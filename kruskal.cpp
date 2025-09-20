#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct Edge{
    int x,y,w;
} Edge;


int n = 10001;
vector<int> father(n,-1);

int find (int u){
    return u == father[u] ? u : father[u] = find(father[u]);




}

int find(int u){
    return u == father[u] ? u : father[u] = find(father[u]);
}

void initial(){
    for(int i=0;i<n;i++){
        father[i] = i;
    }
}

void unite(int u, int v){
    int p = find(u);
    int q = find(v);
    if(p==q)
        return;
    else{
        father[v]=u;
    }
}

bool issame(int u, int v){
    int p = find(u);
    int q = find(v);
    if(p == q){
        return true;
    }
    return false;
}

int main(){
    int V,E,x,y,w;

    cin >> V >> E;

    vector<Edge> edges(E);

    while(E--){
        cin >> x >> y >> w;

        edges.push_back({x,y,w});
    }

    sort (edges.begin(), edges.end(),[](Edge &a, Edge &b){
        return a.w < b.w;
    });


    int result = 0;

    initial();

    for(auto edge : edges){
        int x = find(edge.x);
        int y = find(edge.y);

        if(x!=y){
            unite(x,y);
            result += edge.w;
        }
    }
    

    cout << result << endl;











    return 0;
}