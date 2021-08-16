// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/submissions/
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
using namespace std;
struct TreeNode{
    int val;
    struct TreeNode *left, *right;

    TreeNode(int x){
        val=x;
        left=NULL;
        right=NULL;
    }

};
vector<vector<int>> verticalTraversal(TreeNode* root) {
    queue<pair<TreeNode* ,int>> q;
    map<int, vector<int>> mp;
    vector<vector<int>> v;
    q.push({root,0});
    while(!q.empty()){
        int n = q.size();
        map<int, multiset<int>> store;
        while(n--){
            TreeNode* temp = q.front().first;
            int idx = q.front().second;
            q.pop();
            store[idx].insert(temp->val);
            if(temp->left != NULL){
                q.push({temp->left,idx-1});
            }
            if(temp->right != NULL){
                q.push({temp->right,idx+1});
            }
        }
        for(auto it: store)
            for(auto itr: it.second)
                mp[it.first].push_back(itr);
    }
    for(auto e : mp){
            v.push_back(e.second);
    }
        return v;

}
int main(){
    /*

                    1
                  /  \
                 2    6
                / \  / \
               4   7 3  7
                    \
                     5
                      \
                       8  
*/
 struct TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->right = new TreeNode(7);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    root->left->right->right->left = new TreeNode(8);
    vector<vector<int>> v = verticalTraversal(root);
    int n = v.size();
    for(int i=0;i<n;i++){
        int m = v[i].size();
        for(int j=0;j<m;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }

}