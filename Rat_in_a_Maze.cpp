#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

int result;
bool Check(int i,int j,int n){
    return i>=0 && i<n && j>=0 && j<n;
}
void RatMaze(vector<vector<int>>maze, vector<vector<int>> visited, int n, int i, int j){
    if(maze[i][j] == 1) return;
    else if(i==n-1 && j==n-1){
        result++;
        return;
    }
    if(! Check(i,j,n)) return;

    visited[i][j] = 1;
    if(Check(i-1,j,n) && visited[i-1][j] ==0 && maze[i-1][j] == 0)
        RatMaze(maze,visited,n,i-1,j);

    if(Check(i+1,j,n) && visited[i+1][j] ==0 && maze[i+1][j] == 0)
        RatMaze(maze,visited,n,i+1,j);

    if(Check(i,j+1,n) && visited[i][j+1] ==0 && maze[i][j+1] == 0)
        RatMaze(maze,visited,n,i,j+1);

    if(Check(i,j-1,n) && visited[i][j-1] ==0 && maze[i][j-1] == 0)
        RatMaze(maze,visited,n,i,j-1);
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> a(n, vector<int>(n,0));
    vector<vector<int>> visited(n, vector<int>(n,0));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d", &a[i][j]);
    RatMaze(a, visited, n, 0, 0);
    printf("%d",result);
}