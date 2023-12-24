//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int f(int index,int W,int wt[], int val[],vector<vector<int>> &dp){
      if(W==0)return 0;  
    if(index==0){
        if(wt[index]<=W)return val[index];
        else{return 0;}
        
    }
    if(dp[index][W]!=-1)return dp[index][W];
    int nottake=f(index-1,W,wt,val,dp);
    int take=INT_MIN;
    if(wt[index]<=W){
        take=f(index-1,W-wt[index],wt,val,dp)+val[index];
        
    }
    return dp[index][W]=max(nottake,take);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { vector<vector<int>> dp(n,vector<int>(W+1,-1));
    
    return f(n-1,W,wt,val,dp);
       // Your code here
    }
};


//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends