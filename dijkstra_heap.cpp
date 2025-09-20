#include <iostream>
#include <vector>
#include <list>
#include <queue>


using namespace std;

struct Edge{
    int to;
    int val;

    Edge(int t, int w):to(t),val(w){}
};

class mycomparison{
public : 
    bool operator()(const pair<int, int>&l, const pair<int,int>&r){
        return l.second > r.second;
    }
        
};

int main(){
    int n,m,p1,p2,val;
    cin >> n >> m;
    vector<list<Edge>> grid(n+1);

    for(int i=0;i<m;i++){
        cin >> p1 >> p2 >> val;
        grid[p1].push_back(Edge(p2,val));
    }

    int start = 1;
    int end = n;

    vector<int> minDist(n+1,INT_MAX);

    vector<bool> visited(n+1,false);

    priority_queue<pair<int,int>, vector<pair<int,int>>, mycomparison> pq;

    pq.push(pair<int,int>(start,0));

    minDist[start]=0;

    while(!pq.empty()){
        pair<int,int> cur = pq.top();
        pq.pop();

        if(visited[cur.first]) continue;

        visited[cur.first] = true;

        for(Edge edge : grid[cur.first]){
            if(!visited[edge.to] && minDist[cur.first] + edge.val < minDist[edge.to]){
                minDist[edge.to] = minDist[cur.first] + edge.val;
                pq.push(pair<int,int>(edge.to, minDist[edge.to]));
            }
        }
    }

    if(minDist[end] == INT_MAX ) cout << -1 <<endl;
    else cout << minDist[end] << endl;

    return 0;
}
