// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/submissions/

#include<iostream>
#include<vector>
using namespace std;
struct TreeNode{
    int val;
    struct TreeNode *left, *right;

    TreeNode(int x){
        val = x;
        left=NULL;
        right=NULL;
    }
};
bool findUntil(TreeNode* root, TreeNode* target,vector<TreeNode* >& v){
    if(root == NULL) return false;
    if(root->val == target->val) {
        v.push_back(root);
        return true;
    }
    bool b = findUntil(root->left,target,v);
    if(b){
        v.push_back(root);
        return true;
    }
    bool c = findUntil(root->right,target,v);
    if(c){
        v.push_back(root);
        return true;
    }
    return false;
}
vector<TreeNode*> findNode(TreeNode* root, TreeNode* target){
    vector<TreeNode* > v;
    findUntil(root, target, v);
    return v;
}
void GetNodes(TreeNode* root,int k, TreeNode* p, vector<int>& store){
    if(root==NULL || root==p || k<0) return;
    if(k==0){
        store.push_back(root->val);
    }
    GetNodes(root->left, k-1, p, store);
    GetNodes(root->right, k-1, p, store);
}
vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    vector<TreeNode* > v = findNode(root, target);
    int n = v.size();
    vector<int> store;
    for(int i=0;i<n;i++){
        GetNodes(v[i],k-i, i==0?NULL:v[i-1], store);
    }
    return store;
}
int main(){
    /*
                        3
                      /    \
                     5      1  
                    / \     / \  
                   6   2   0   8
                      / \
                     7   4 
    */
   struct TreeNode* root = new TreeNode(3);
   root->left = new TreeNode(5);
   root->right = new TreeNode(1);
   root->left->left = new TreeNode(6);
   root->left->right = new TreeNode(2);
   root->right->left = new TreeNode(0);
   root->right->right = new TreeNode(8);
   root->left->right->left = new TreeNode(7);
   root->left->right->right = new TreeNode(4);
   vector<int> v = distanceK(root, root->left->right->right,2);
   for(int e : v) cout<<e<<" ";
}