#include<bits/stdc++.h>
using namespace std;
class BST{
	int data;
	BST *left;
	BST *right;
	public:
		BST(){
			data = 0;
			left = right = NULL;
		}
		BST(int n){
			data = n;
			left = right = NULL;
		}
		BST* Insert(BST* head, int n);
		void Inorder(BST* head);
		void Preorder(BST* head);
		void Postorder(BST* head);
		int smallestElement(BST* head);
		int largestElement(BST* head);
		int totalNode(BST* head);
		int height(BST* head);
		int internalNodes(BST* head);
		int totalLeafNodes(BST* head);
		int search(BST* head, int n);
		int InOrderSuccessor(BST* head);
		BST* deleteElement(BST* head, int n);
		void deleteNode(BST* head);
};
BST* BST::Insert(BST* head, int n){
	if(head==NULL) return new BST(n);
	else if(head->data < n) head->right = Insert(head->right,n);
	else head->left = Insert(head->left,n);
}

void BST::Inorder(BST* head){
	if(head == NULL) return;
	Inorder(head->left);
	cout<<head->data<<" ";
	Inorder(head->right);
}

void BST::Preorder(BST* head){
	if(head == NULL) return;
	else cout<<head->data<<" ";
	Preorder(head->left);
	Preorder(head->right);
}

void BST::Postorder(BST* head){
	if(head == NULL) return;
	Postorder(head->left);
	Postorder(head->right);
	cout<<head->data<<" ";
}

int BST::smallestElement(BST* head){
	if(head->left == NULL) return head->data;
	else return smallestElement(head->left);
}

int BST::largestElement(BST* head){
	if(head->right == NULL) return head->data;
	else return largestElement(head->right);
}

int BST::totalNode(BST* head){
	if(head == NULL) return 0;
	else 
	return (totalNode(head->left) + totalNode(head->right) +1);
}

int BST::height(BST* head){
	if (head == NULL) return 0;
	int left_height = height(head->left)+1;
	int right_height = height(head->right)+1;
	if(left_height > right_height) return left_height;
	else return right_height;
}

int BST::internalNodes(BST* head){
	if(head == NULL || (head->left == NULL && head->right == NULL)) return 0;
	else return (internalNodes(head->left) + internalNodes(head->right) + 1);
}

int BST::totalLeafNodes(BST* head){
	if(head == NULL || (head->left == NULL && head->right == NULL)) return 1;
	else return (internalNodes(head->left) + internalNodes(head->right));
}

int BST::search(BST* head, int n){
	if(head == NULL) return 0;
	else if(head->data == n) return 1;
	return search(head->left,n) + search(head->right,n);
}

int BST::InOrderSuccessor(BST* head){
	int min;
	while(head->left != NULL){
		min = head->left->data;
		head = head->left;
	}
	return min;
}

BST* BST::deleteElement(BST* head, int n){
	if(head == NULL) return head;
	else if(n < head->data)	
	head->left =  deleteElement(head->left,n);
	else if(n > head->data) 
	head->right = deleteElement(head->right,n);
	else{
		if(head->left == NULL) {
			return head->right;
		}
		else if(head->right == NULL){
			return head->left;			
		}
		head->data = InOrderSuccessor(head->right);
		head->right = deleteElement(head->right, head->data);	
	}
	return head;
}

void BST::deleteNode(BST* head){
	if (head != NULL){
		deleteNode(head->left);
		deleteNode(head->right);
		delete head;		
	}	
}

int main(){
	int r,n,v,d;
	cin>>n;
	BST b, *root = NULL;
	cin>>r;
	root = b.Insert(root,r);	
	for(int i=1;i<n;i++){
		cin>>v;
		b.Insert(root,v);
	}
	b.Preorder(root);
	cout<<endl;
	b.Inorder(root);
	cout<<endl;
	b.Postorder(root);
	cout<<endl<<"Samllest element: "<<b.smallestElement(root);
	cout<<endl<<"Largest element: "<<b.largestElement(root);
	cout<<endl<<"Total number of nodes: "<<b.totalNode(root);
	cout<<endl<<"Height of tree: "<<b.height(root);
	cout<<endl<<"number of internal nodes: "<<b.internalNodes(root);
	cout<<endl<<"number of leaf nodes: "<<b.totalLeafNodes(root);
	cout<<endl<<"Enter the elemnet to be searched: ";
	cin>>d;
	if(b.search(root, d)) cout<<endl<<"Element found";
	else cout<<endl<<"Element not found";
	b.deleteNode(root);
	cout<<endl<<"Enter the elemnet to be deleted: ";
	cin>>d;
	if(b.search(root, d)) {
		b.deleteElement(root, d);
		cout<<endl<<"Element found and deleted";
	}	
	else cout<<endl<<"Element not found"<<endl;
	b.Preorder(root);
}
