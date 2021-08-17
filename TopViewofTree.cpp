// https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1
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
void findMinMax(Node* root, int h, int a[]){
    if(root == NULL) return;

    a[0] = min(a[0], h);
    a[1] = max(a[1], h);

    findMinMax(root->left, h-1, a);
    findMinMax(root->right, h+1, a);
}
vector<int> verticalTraversal(Node* root) {
    queue<pair<Node* ,int>> q;
    int a[2] = {0};
    findMinMax(root,0,a);
    int len = a[1] - a[0] + 1;
    vector<int> v(len,'\0');
    q.push({root,abs(a[0])});
    while(!q.empty()){
        int n = q.size();
        while(n--){
            Node* temp = q.front().first;
            int h = q.front().second;

            q.pop();
            if(v[h] =='\0'){
                v[h] = temp->data;
            }


            if(temp->left)
                q.push({temp->left, h-1});
            if(temp->right)
                q.push({temp->right , h+1});

        }
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
                    \    \
                     5    9
                      \
                       8  
*/
 struct Node* root = new Node(1);
    root->left = new Node(2);
    root->left->right = new Node(7);
    // root->left->right->left = new Node(10);
    // root->left->right->left->left = new Node(11);
    // root->left->right->left->left->left = new Node(20);
    root->right = new Node(6);
    root->left->left = new Node(4);
    root->right->left = new Node(3);
    root->left->right->right = new Node(5);
    root->right->right = new Node(7);
    root->right->right->right = new Node(9);
    root->left->right->right->right = new Node(8);
    vector<int> v = verticalTraversal(root);
    for(int e: v) cout<<e<<" ";
}