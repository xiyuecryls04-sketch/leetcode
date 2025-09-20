#include <iostream>
#include <vector>
#include <list>

using namespace std;

vector<vector<int>> result;
vector<int> path;

void dfs1(vector<vector<int>> &graph,int n, int x){
    if(x==n){
        result.push_back(path);
        return;
    }

    for(int i=0;i<n;i++){
        if(graph[x][i]!=-1){
            path.push_back(i);
            dfs1(graph,n,i);
            path.pop_back();
        }
    }
}


void dfs2(vector<list<int>> &graph, int n, int x){
    if(x==n){
        result.push_back(path);
        return;
    }

    for(int i : graph[x]){
        path.push_back(i);
        dfs2(graph,n,i);
        path.pop_back();
    }
}

int main(){
    int n,m;
    cin >> n >> m;


    vector<vector<int>> graph(n+1,vector<int>(n+1,-1));

    while(m--){
        int x,y;
        cin>>x>>y;
        graph[x][y]=1;
    }

    if(result.size()==0){
        cout<<-1<<endl;
    }
    
    else{
        for(int i=0;i<result.size();i++){
            for(int j=0;j<result[i].size()-1;j++){
                cout<<result[i][j]<<" ";
            }
            cout<<result[i][result[i].size()-1];
        }
        cout<<endl;
    }
    return 0;

    
}

