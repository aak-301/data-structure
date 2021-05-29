#include<iostream>
using namespace std;
struct node{
	// structure use to create nodes of linked list
	// it consists data part and a pointer part
	int data;
	node* next;
};
node* insert(node* head, int value){
	// function to insert a node to a linked list
	node* temp = head;
	node* newnode = new node;
	newnode->data = value;
	newnode->next = NULL;
	if(head == NULL){
		// when head is NULL that is nothing is added to linked list,
		// then head will store the value of this newly created newnode
		head = newnode;
	}
	else{
		while(temp->next != NULL) temp = temp->next;
		// while loop is used to reach the end of the loop
		// as we have to add node at last that's why we itterate the linked list
		temp->next = newnode;
		temp = newnode;	
		// after iterating temp variable will point to very last element of linked lst
		// after this last element we added the newnode using next pointer of last node	
	}
	return head;
}
void display(node* head){
	// display function is of void as it doesn't return anything
	node* temp = head;
	while(temp != NULL){
		//here we traverse till we doesn't meet NULL
		//when we encounter NULL, this loop break
		cout<<temp->data<<" ";
		temp = temp->next;
	}
}
node* reverseItr(node* head){
	//function to reverse the linked list itteratively
	//it is stuct node type as we have to return new revesed node back to main to store it in head
	
	node* prev = NULL;     
	node* current = head;
	node* futureValue = head->next;
	
	//Example:
	//[1]->[2]->[3]->NULL (A simple linked list)
	//Here prev store NULL
	//current point to [1]
	//futureValue point to [2]
	
	while(futureValue != NULL){
		current->next = prev;
		prev = current;
		current = futureValue;
		futureValue = futureValue = futureValue->next;
		
		/* During 1st itteration:
		   current->next = prev,  this statement leads [1] to point NULL;
		   prev = current, here prev now store the value of current,i.e,[1]
		   current = futureValue, and current store the value of futureValue, i.e, [2]
		   futureValue = futureValue = futureValue->next , here head moves to element [3]
		   Result: NULL<-[1]
		
		   During 2nd itteration:
		   current->next = prev,  this statement leads [2] to point [1];
		   prev = current, here prev now store the value of current,i.e,[2]
		   current = futureValue, and current store the value of futureValue, i.e, [3]
		   futureValue = futureValue = futureValue->next , here head moves to NULL
		   Result: NULL<-[1]<-[2]
		
		   while going for thired itteration loop breaks as futureValue = NULL
		*/
	}
	current->next = prev;
	// As curren is at [3] we simply point the next of [3] to prev,i.e,[2]
	head = current;
	//After that making head = current ,i.e., head = [3]
	// Result: NULL<-[1]<-[2]<-[3] or [3]->[2]->[1]->NULL
	
	return head;
	
}
node* reverseRec(node* head){
	//reversing linked list recursively
	//Example:
	//[1]->[2]->[3]->NULL (A simple linked list)
	node* temp;
	if(head == NULL || head->next == NULL) return head;
	
		/*
			recursion will make a stack like this |1|2|3|
			As 3 is reached if condition becomes true, beacuse [3]->next = NULL
			So temp stores [3]
			Now at that point, current head will point to [2] as [3] has been returned from stack
			Now at line 109
			
			Now [2] is returned
			At line 114	
		
		*/
	temp = reverseItr(head->next);
	head->next->next = head;
	head->next = NULL;
	/*
		so in linked list [2]->next = [3] and [3]->next= NULL
		so head->next->next = head, this mean [2]->[3]->[2]
		and head->next = NULL meant that [2]->next = NULL
		i.e. [2]->NULL and [3]->[2]->NULL
		
		when [2] is returned [1] is the head, so [1]->next = [2] and [2]->next = NULL as shown above
		so head is at [1]
		therfore 	head->next->next = head meant [1]->[2]->[1]
		and head->next = NULL  this meant [1]->next = NULL
		so result is [3]->[2]->[1]->NULL
		
		It is confusing, just remember we are dealing address here.
	*/
	
	return temp;
}
int main(){
	node* head = NULL;
	//head variable of type struct node where linked list starts from
	head = insert(head, 5);
	head = insert(head, 4);
	head = insert(head, 3);
	head = insert(head, 2);
	head = insert(head, 1);
	head = insert(head, 0);
	display(head);
	cout<<"\n";
	head = reverseItr(head);
	display(head);
	cout<<"\n";
	head = reverseItr(head);
	display(head);
}
