#include <iostream>
#include <vector>
#include <queue>

using namespace std;


 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
    priority_queue<int, vector<int>, greater<int>> construct(TreeNode *root){
        priority_queue<int, vector<int>, greater<int>> result;
        if(root){
            result.push(root->val);
        }
        queue<TreeNode *> que;
        que.push(root);
        while(!que.empty()){
            TreeNode *top = que.front();
            que.pop();
            if(top->left){
                que.push(top->left);
                result.push(top->left->val);
            }
            if(top->right){
                que.push(top->right);
                result.push(top->right->val);
            }
        }
        return result;
    }
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        minHeap = construct(root);
        int res;
        while(k){
            res = minHeap.top();
            minHeap.pop();
            k--;
        }
        return res;
        

    }
};

int main(){
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);

    Solution so;
    int res = so.kthSmallest(root, 1);
    cout << res << endl;

    return 0;
}