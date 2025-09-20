#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        vector<int> pre;
        result.push_back({1});
        pre = {1};
        for(int i = 1;i<numRows;i++){
            vector<int> tmp;
            tmp.push_back(1);
            if(i>=2){
                for(int j=0;j<pre.size()-1;j++){
                    tmp.push_back(pre[j]+pre[j+1]);
                }
            }
            tmp.push_back(1);
            result.push_back(tmp);
            pre = tmp;
        }
        return result;
    }
};

int main(){
    int numRows =5;
    Solution s;
    vector<vector<int>> res = s.generate(5);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}