//Leetcode question link -> https://leetcode.com/problems/generate-parentheses/


/* LOGIC
    Here we have to make valide combintion of parenthesis based on the given input
    depending on input(i.e. n) there will be n opening brackets and n closing brackets
    But their order will be different.
    
    let's say if n=2,
    then there will be 2 opening and two closing braces. In total 2*n bracets.
    o/p:- ()() (()) 

    similarly for n=4,
    o/p:- ()()()() ()()(()) ()(())() ()(()()) ()((())) (())()() (())(()) (()())() (()()()) (()(())) ((()))() ((())()) ((()())) (((()))) 


    so one can say that we have to check if there is any opening brackets then only we can have closing brackets.
    e.g.:- if '(' is present then only ')' ,it will occur, else it won't be a valid set

*/

#include<bits/stdc++.h>
using namespace std;
#define fill_array(a,val) memset(a, val, sizeof(a))
#define trav(n) for(auto i=0;i<n;i++)

void fun(int n, int countOpen, int countClosed, string s, vector<string>& store){
    /*
        > n is the input given 
        > countOpen is the counter to count the number of opening brackets
        > countClosed is the counter to count the number of closing brackets.
        > s is to store the string formed which are valid
        > store is a vector which is used to store valid s. and it is passed by reference. That's why function fun() is void type
    */

  if(countClosed == n){
      /*
        it will only happen when all opening brackets are considered
        because only then countClosed will become equal to countOpen, which in turn is equal to n.
        e.g. if n=3 then ((())) (is valid) where we have 3 opening and 3 closing brackets.
        When this condition hits, we simply push that string in this vector store.
      */
    store.push_back(s);
    
  }
  else{
    if(countOpen > countClosed){
        /*
            here we check whether the number of closed brackets are less than opening brackets
            It is less because: 
                > closing bracket cannot exceed opening brackets. This will leed to invalid string
                > when this condition is hit at last then when we call this recursive function then we increment the countClosed which will 
                  automatically staisfy the base condition and we need not to check in this if condition
                 e.g.: ()()  (this is for n=2) in this after storing ()(  in s then, countOpen will be 2 and countClosed will be 1 so 1<2 
                 this condition is satisfied and after that calling function will be like: 
                 fun(n,2,1+1,()(+")",store)
                 so we can see countClosed will become 2, that's why it will be handled in base case
        */
      fun(n,countOpen,countClosed+1,s+")",store);
    }
    if(countOpen < n){
        /*
            here the analogy is similar to above.
            The only difference is no of open braces is checked
            Here it is (countOpen < n) less than because countOpen starts from 0
        */
      fun(n,countOpen+1,countClosed,s+"(",store);
    }
  }
}

    vector<string> generateParenthesis(int n) {
        /*
            store vector to store the result and return it to main
            s is just a temporary variable passed to store the string
            Since fun() is recursive declaring above will lead to overwritting and thus unexpected outcome
        */
        vector<string> store;
        string s="";
        fun(n,0,0,s,store);
        return store;
    }


int main(){


    /*

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    */

  int t,n;
  cin>>t;
  vector<string> res;
  while(t--){
    cin>>n;
    res = generateParenthesis(n);
    // its a for of loop
    for(string parenthesis : res) cout<<parenthesis<<" ";
    cout<<endl;
  }
}
