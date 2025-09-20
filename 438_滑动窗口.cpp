#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.size() < p.size()) return {};

        vector<int> pmap(26, 0), smap(26, 0), res;
        for (char c : p) pmap[c - 'a']++;

        int psize = p.size();

        for (int i = 0; i < s.size(); i++) {
            smap[s[i] - 'a']++;  // add current char to window

            // keep window size == psize
            if (i >= psize) {
                smap[s[i - psize] - 'a']--;
            }

            if (smap == pmap) {
                res.push_back(i - psize + 1);
            }
        }
        return res;
    }
};

int main() {
    Solution so;
    string s = "cbaebabacd";
    string p = "abc";
    vector<int> res = so.findAnagrams(s, p);

    for (int i : res) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}


// 时间超限

// #include <iostream>
// #include <vector>
// #include <string>
// #include <unordered_map>

// using namespace std;

// class Solution {
// public:
//     vector<int> findAnagrams(string s, string p) {
//         unordered_map<char, int> pmap,smap;
//         for(char c: p){
//             if(pmap.find(c)==pmap.end()){
//                 pmap.insert({c,1});
//             }
//             else{
//                 pmap[c]++;
//             }
//         }

        

//         int psize = p.size();
//         int ssize = s.size();

//         vector<int> res;
//         // n-1-x+1 = psize
//         for(int i=0;i<=ssize-psize;i++){
//             smap = pmap;
//             for(int j=0;j<psize;j++){
//                 if(smap.find(s[i+j])==smap.end()){
//                     break;
//                 }
//                 else{
//                     smap[s[i+j]]--;
//                     if(smap[s[i+j]]==0){
//                         smap.erase(s[i+j]);
//                     }
//                 }
//             }
//             if(smap.size()==0){
//                 res.push_back(i);
//             }

//         }
//         return res;
//     }
// };

// int main(){
//     Solution so;
//     string s, p;
//     s="cbaebabacd";
//     p = "abc";
//     vector<int> res = so.findAnagrams(s,p);

//     for(int i : res){
//         cout << i << " ";
//     }
//     cout << endl;
//     return 0;
// }