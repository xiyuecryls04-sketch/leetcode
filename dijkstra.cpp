#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main(){
    int n, m ,p1,p2,val;
    cin >> n >> m;

    vector<vector<int> >grid(n+1,vector<int>(n+1,INT_MAX));
    while(m--){
        cin >> p1 >> p2 >> val;

        grid[p1][p2]=val;
    }

    int start = 1;
    int end = n;

    vector<int> visited(n+1,false);
    visited[1]=true;

    vector<int> minDist(n+1, INT_MAX);

    minDist[start]=0;

    for(int i=1;i<=n;i++){
        int min_val = INT_MAX;
        int cur = 1;

        for(int j=1;j<=n;j++){
            if(!visited[i]&&minDist[i]<min_val){
                min_val = minDist[i];
                cur = j;
            }
        }

        visited[cur] = true;

        for(int j = 1;j<=n;j++){
            if(!visited[j]&&grid[cur][j]!=-1 && grid[cur][j]<minDist[j]){
                minDist[j]=grid[cur][j]+minDist[cur];

            }
        }
    }

    if(minDist[end]==INT_MAX)
        cout << -1 << endl;
    else{
        cout << minDist[end] << endl;
    }
}