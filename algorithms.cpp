
//    KADEN'S ALGORITHM for MX SUM SUB-ARRAY
//    GFG link :- https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1
#include<iostream>
#include<climits>
using namespace std;
int maxSubarraySum(int a[], int n){
	int meh = 0,msf = INT_MIN,start,end;
	for(int i=0;i<n;i++){
		meh+=a[i];				
		// first we add up the consecutive elements
		if(meh < a[i]){				
		//here we check that wheteher the present element is greater than the sum till that element
		// if that is so, then we will start the sum from that element. That is our start pointer will point to that element.
			start = i;
			meh = a[i];
		} 
		if(msf<meh){
			// this msf variable job is same as that of when we are finding maximum element in an array
			// Basically this variable msf is used find the max sum from any start point to end point.
			end = i;
			msf = meh;
		} 
	}
	
	if(end>start){
		// in this condition we must have got an array subset then only start and end have different value stored in them.
		
		for(int i=start;i<=end;i++) cout<<a[i]<<" ";
		cout<<"\n";
	}
	
	else {
		// here just one element has that maximum sum so end pointer will point that maximum element in any case
		for(int i=end;i<=end;i++) cout<<a[i];
		cout<<"\n";
	}
	return msf;
}
int main(){
//int n;
//cin>>n;
//int a[n];
//for(int i=0;i<n;i++) cin>>a[i];
int n = 8;
int a[] = {-1,-2,-3,4,-1,2,-4,8};
	cout<<maxSubarraySum(a,n);
}
