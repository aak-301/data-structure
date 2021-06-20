#include<iostream>
#include<queue>
using namespace std;
class BST{
    int val;
    BST *left,*right;
    queue<BST* > levelOrederQueue;
    public:
    BST();
    BST(int val);
    BST* Insert(BST* head, int val);
    BST* Delete(BST* head, int val);
    BST* mirrorImage(BST* head);
    void Inorder(BST* head);
    void Preorder(BST* head);
    void Postorder(BST* head);
    void leafNode(BST* head);
    void Levelorder(BST* head);
    void InternalNode(BST* head);
    int LargestNode(BST* head);
    int SmallestNode(BST* head);
    int Height(BST* node);
    bool hasElement(BST* head, int val);
};
BST::BST(){
    val=0;
    left=right=NULL;
}
BST::BST(int data){
    val=data;
    left=right=NULL;    
}
void BST::Inorder(BST* head){
    if( !head ) return;
    Inorder(head->left);
    cout<<head->val<<" ";
    Inorder(head->right);
}
void BST::Preorder(BST* head){
    if(!head) return;
    cout<<head->val<<" ";
    Preorder(head->left);
    Preorder(head->right);
}
void BST::Postorder(BST* head){
    if(!head) return;
    Postorder(head->left);
    Postorder(head->right);
    cout<<head->val<<" ";
}
void BST::Levelorder(BST* head){
    if(!head) return;
    levelOrederQueue.push(head);
    while(!levelOrederQueue.empty()){
        BST* temp = levelOrederQueue.front();
        cout<<temp->val<<" ";
        levelOrederQueue.pop();

        if(temp->left != NULL)
            levelOrederQueue.push(temp->left);
        if(temp->right != NULL)
            levelOrederQueue.push(temp->right);
    }
}
void BST::leafNode(BST* head){
    if(! head) return;
    if(head->left==NULL && head->right==NULL){
        cout<<head->val<<" ";
        return;
    }
    leafNode(head->left);
    leafNode(head->right);
}
int BST:: LargestNode(BST* head){
    if(head->right==NULL) return head->val;
    LargestNode(head->right);
}
int BST:: SmallestNode(BST* head){
    if(head->left==NULL) return head->val;
    SmallestNode(head->left);
}
int BST::Height(BST* head){
    if(!head) return 0;
    if(head->left == NULL && head->right == NULL){
        return 1;
    }
    if(Height(head->left)+1 > Height(head->right)+1)
    return Height(head->left)+1 ;
    else return Height(head->right)+1;
}
bool BST::hasElement(BST* head, int data){
    if(!head) return false;
    else if(head->val == data) return true;
    if(hasElement(head->left,data)||hasElement(head->right,data)) return true;
}
void BST:: InternalNode(BST* head){
    if(!head) return ;
    if(head->left==NULL && head->right==NULL){
        return;
    }
    cout<<head->val<<" ";
    InternalNode(head->left);
    InternalNode(head->right);
}
BST* BST::mirrorImage(BST* head){
    BST* temp;
    while(!head){
        mirrorImage(head->left);
        mirrorImage(head->right);
        temp = head->right;
        head->right = head->left;
        head->left = temp;
    }
}
BST* BST::Insert(BST* head, int data){
    if(!head)
         return new BST(data);
    if(data>head->val)
        head->right = Insert(head->right, data);
    else
        head->left = Insert(head->left, data);
    return head;
}
BST* BST::Delete(BST* head, int data){
    if(!head) return NULL;
    else if(data < head->val){
        head->left = Delete(head->left,data);
    }
    else if(data > head->val){
        head->right = Delete(head->right,data);
    }
    else{
        if(head->left==NULL && head->right == NULL){
            return NULL;
        }
        else if(head->left == NULL){
            BST* temp = head->right;
            free (head);
            return temp;
        }
        else if(head->right == NULL){
            BST* temp = head->left;
            free (head);
            return temp;
        }
        int small = SmallestNode(head->right);
        head->val = small;

        head->right = Delete(head->right, small);

        return head;        
    }
}
int main(){

    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    BST tree;
    BST *head = NULL;
    int t;
    cin>>t;
    int delete_element, occured;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        if(i==0)
            head = tree.Insert(head,n);
        else
            tree.Insert(head,n);
    }
    cout<<"Preorder Traversal: ";
    tree.Preorder(head);
    cout<<endl;
    cout<<"Inorder Traversal: ";
    tree.Inorder(head);
    cout<<endl;
    cout<<"Postorder Traversal: ";
    tree.Postorder(head);
    cout<<endl;
    cout<<"Levelorder Traversal: ";
    tree.Levelorder(head);
    cout<<endl;
    cout<<"leafNodes are: ";
    tree.leafNode(head);
    cout<<endl;
    cout<<"InternalNodes are: ";
    tree.InternalNode(head);
    cout<<endl;
    cout<<"LargestNode: ";
    cout<<tree.LargestNode(head)<<endl;
    cout<<"SmallestNode: ";
    cout<<tree.SmallestNode(head)<<endl;
    cout<<"Height: ";
    cout<<tree.Height(head)<<endl;
    cout<<"Enter the element to search: ";
    cin>>occured;
    cout<<occured<<endl;
    if(tree.hasElement(head, occured)) cout<<"Yes "<<occured<<" is present\n";
    else  cout<<"No "<<occured<<" is not present\n";
    cout<<"Enter a number to delete: ";
    cin>>delete_element;
    cout<<delete_element<<endl;
    if(tree.hasElement(head, delete_element)){
        tree.Delete(head, delete_element); cout<<"Deleted "<<delete_element<<endl;
    }
    else  cout<<"There isn't any "<<delete_element<<endl;
    cout<<endl;
    tree.mirrorImage(head);
    cout<<"After finding mirror Image of tree: \n";
    cout<<"Preorder Traversal: ";
    tree.Preorder(head);
    cout<<endl;
    
}
