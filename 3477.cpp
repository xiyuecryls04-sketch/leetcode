#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int fsum = fruits.size();
        int bsize = baskets.size();
        int res = fsum;
        for(int i=0;i<fsum-1;i++){
            for(int j=0;j<bsize-1;j++){
                // if(baskets[j]==0 || baskets[j]<fruits[i]){
                //     ;
                // }
                // else
                if(baskets[j]>fruits[i]){
                    baskets[j]=0;
                    res--;
                    break;
                }
            }
        }
        return res;
        
    }
};

int main(){
    vector<int> fruits={3,6,1};
    vector<int> baskets={6,4,7};
    Solution s;
    int res = s.numOfUnplacedFruits(fruits,baskets);
    cout << res <<endl;
    return 0;
}