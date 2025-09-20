// #include <iostream>
// #include <vector>
// #include <climits>

// using namespace std;

// int main(){
//      int n,m,x,y,w;
//     cin >> n >> m;
//     vector<vector<int>> grid(n+1,vector<int>(n+1,10001));
   

//     vector<int> minDist(n+1,10001);
//     vector<bool> visited(n+1, false);

//     while(m--){
//         cin >> x >> y >>w;
//         grid[x][y]=w;
//         grid[y][x]=w;
//     }


//     for(int i=1;i<n;i++){


//         int cur=-1;
//         int min_val=INT_MAX;

//         for(int j=1;j<=n;j++){
//             if(!visited[j]&&minDist[j]<min_val){
//                 min_val = minDist[j];
//                 cur = j;
//             }
//         }

//         visited[cur]=true;

//         for(int i=1;i<=n;i++){
//             if(!visited[i]&&grid[cur][i]<minDist[i]){
//                 minDist[i]=grid[cur][i];
//             }
//         }
//     }

//     int result = 0;
//     for(int i=2;i<=n;i++){
//         result+=minDist[i];
//     }
//     cout << result << endl;



// }


#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main(){
    int n,m,x,y,w;
    cin >> n >> m;

    vector<vector<int>> grid(n+1, vector<int>(n+1,10001));

    while(m--){
        cin >> x >> y >> w;
        grid[x][y]=w;
        grid[y][x]=w;
    }


    vector<bool> visited(n+1,false);

    vector<int> minDist(n+1,10001);

    vector<int> parent(n+1,-1);


    for(int i=1;i<n;i++){
        int cur = -1;
        int min_val = INT_MAX;

        for(int j = 1;j<=n;j++){
            if(!visited[j]&&minDist[j]<min_val){
                min_val = minDist[j];
                cur = j;
            }
        }

        visited[cur]=true;

        for(int j = 1;j<=n;j++){
            if(!visited[j]&&grid[cur][j]<minDist[j]){
                minDist[j]=grid[cur][j];
                parent [j]=cur;
            }
        }




    }

    for(int i=1;i<=n;i++){
        cout << i <<"--"<< parent[i]<<endl;
    }

  

    return 0;
}