#include<iostream>
#include<stdio.h>

#define isf(n) scanf("%d",&n)
#define spf(s) printf("%s",s)

using namespace std;

int BinarySearchAscending(int a[], int start, int end, int val){
    int mid = start + (end - start)/2;
    if(start > end) return -1;
    if(a[mid] == val) return mid;
    else if(val > a[mid]){
        return BinarySearchAscending(a,mid+1,end,val);
    }
        return BinarySearchAscending(a,start,mid-1,val);
   
}

int BinarySearchDescending(int a[], int start, int end, int val){
    int mid = start + (end - start)/2;
    if(start > end) return -1;
    if(a[mid] == val) return mid;
    else if(val > a[mid]){
        return BinarySearchDescending(a,start,mid-1,val);
    }
        return BinarySearchDescending(a,mid+1,end,val);
   
}

void printArr(int a[], int n){
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;
}

void Acsending(int a[], int n, int num){
    printf("\n\n\n\n\t\t\t\tAscending.... \n\n");
    printArr(a,n);
    int index = BinarySearchAscending(a,0,n-1,num);
    if(index == -1){
        spf("Not found");
        printf("\n");
    }
    else printf("%d found at: %d", num, index+1); 
    printf("\n");
}

void Reverse(int a[], int n){
    for(int i=0;i<n/2;i++){
        int temp = a[i];
        a[i] = a[n-1-i];
        a[n-i-1] = temp;
    }
}

void Descending(int a[], int n, int num){
    printf("\n\n\n\n\t\t\t\tAscending.... \n\n");
    Reverse(a,n);
    printArr(a,n);
    int index = BinarySearchDescending(a,0,n-1,num);
    if(index == -1){
        spf("Not found");
        printf("\n");
    }
    else printf("%d found at: %d", num, index+1); 
    printf("\n");
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
    Acsending(a,n,num);
    Descending(a,n,num);

}
