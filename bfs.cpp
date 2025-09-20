#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dir[4][2] = {0,1,1,0,0,-1,-1,0};

void bfs(vector<vector<int>> &graph, vector<vector<bool>> &visited, int x, int y){
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y] = true;
    while(!q.empty()){
        pair<int,int> cur = q.front();
        q.pop();
        int curx = cur.first;
        int cury = cur.second;
        for(int i=0;i<4;i++){
            int nextx = curx+dir[i][0];
            int nexty = cury + dir[i][1];
            if(nextx<0||nextx>graph.size()||nexty<0||nexty>graph[0].size()){
                continue;
            }
            if(!visited[nextx][nexty]){
                visited[nextx][nexty] = true;
                //处理
                q.push({nextx,nexty});
            }
        }


    }
    
}