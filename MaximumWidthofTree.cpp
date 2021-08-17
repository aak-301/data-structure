// https://practice.geeksforgeeks.org/problems/maximum-width-of-tree/1
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
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
void calc(Node* root, int h, int a[]){
    if(root == NULL) return;
    a[0] = min(h,a[0]);
    a[1] = max(h,a[1]);

    calc(root->left, h-1, a);
    calc(root->right, h+1, a);
}
int getMaxWidth(struct Node* root) {
    int a[2] = {0};
    calc(root, 0, a);

    return a[1] - a[0] + 1;
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
 struct Node* root = new Node(1);
    root->left = new Node(2);
    root->left->right = new Node(7);
    root->right = new Node(6);
    root->left->left = new Node(4);
    root->right->left = new Node(3);
    root->left->right->right = new Node(5);
    root->left->right->right->left = new Node(8);
    root->right->right = new Node(7);
    cout<<getMaxWidth(root);
}