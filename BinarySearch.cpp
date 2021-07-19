#include<iostream>
#include<stdio.h>

#define isf(n) scanf("%d",&n)
#define spf(s) printf("\n%s",s)

using namespace std;

int BinarySearch(int a[], int start, int end, int val){
    int mid = (start+ end)/2;
    if(a[mid] == val) return mid;
    else if(val > a[mid]){
        return BinarySearch(a,mid+1,end,val);
    }
    else{
        return BinarySearch(a,start,mid-1,val);
    }
}
int main(){
    int n,num;
    spf("enter array size: ");
    isf(n);
    spf("enter the array elements: ");
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    spf("enter the number to be searhed: ");
    isf(num);
    int index = BinarySearch(a,0,n-1,num);
    if(index == -1){
        spf("Not found");
    }
    else printf("%d found at: %d", n, index+1);    
}