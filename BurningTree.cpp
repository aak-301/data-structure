// https://practice.geeksforgeeks.org/problems/burning-tree/1#
#include<iostream>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct Node{
    int data;
    struct Node *left, *right;

    Node(int x){
        data=x;
        left=NULL;
        right=NULL;
    }

};
bool NodetoRoot(Node* root, int target, vector<Node*>& v){
    if(root == NULL) return false;
    if(root->data == target){
        v.push_back(root);
        return true;
    }
    bool left = NodetoRoot(root->left, target, v);
    if(left){
        v.push_back(root);
        return true;
    }
    bool right = NodetoRoot(root->right, target, v);
    if(right){
        v.push_back(root);
        return true;
    }
    return false;
}
void calcTime(Node* root,Node* blocked,int time, int& maxTime){
    if(root == NULL || root==blocked) return;
    maxTime = max(time,maxTime);

    calcTime(root->left, blocked, time+1,maxTime);
    calcTime(root->right, blocked, time+1,maxTime);
}
int minTime(Node* root, int target){
    vector<Node* >v;
    int maxTime=0;
    NodetoRoot(root, target, v);
    int n = v.size();
    for(int i=0;i<n;i++){
        
        calcTime(v[i], i==0?NULL:v[i-1],i,maxTime);
    }
    return maxTime;

}
int main(){
    /*
          1
        /   \
      2      3
    /  \      \
   4    5      6
       / \      \
      7   8      9
                   \
                   10
*/
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->right = new Node(3);
    root->right->right = new Node(6);
    root->right->right->right = new Node(9);
    root->right->right->right->right = new Node(10);
    root->left->right = new Node(5);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(8);
    cout<<minTime(root,8);
    

}