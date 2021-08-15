// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/

#include<iostream>
#include<vector>
#include<queue>
#include<map>
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
int maxLevelSum(TreeNode* root) {
    queue<TreeNode* >q;
    q.push(root);
    long int maxSum = INT_MIN;
    int maxLevel;
    long int sum;
    int l=0;
    while(!q.empty()){
        sum=0;
        l++;
        int n = q.size();
        for(int i=0;i<n;i++){
            TreeNode* temp = q.front();
            q.pop();
            sum+=temp->val;
            if(temp->left != NULL)
                q.push(temp->left);
            if(temp->right!=NULL)
                q.push(temp->right);
        }

        if(sum>maxSum){
            maxLevel=l;
            maxSum=sum;
        }       
    }
    return maxLevel;
}
int main(){
    /*

                    1
                  /   \
                 7     0
                /\     
               7 -8  
*/
    // struct TreeNode* root = new TreeNode(1);
    // root->left = new TreeNode(7);
    // root->left->right = new TreeNode(-8);
    // root->left->left = new TreeNode(7);
    // root->right = new TreeNode(0);

    struct TreeNode* root = new TreeNode(989);
    // root->right = new TreeNode(10250);
    // root->right->left = new TreeNode(98693);
    // root->right->right = new TreeNode(-89388);
    // root->right->right->right = new TreeNode(-32127);
    cout<<maxLevelSum(root);

}