//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function Template for C++

class Solution {
    
    public:
    int isPossible(int N , int coins[]) 
    {
        vector<vector<int>>dp(N+1,vector<int>(2025,-1));
        return fun(0,0,N,coins,dp);
    }
    private:
    bool fun(int i,int sum,int n,int coins[],vector<vector<int>>&dp)
    {
        if(sum&&(sum%20==0||sum%24==0||sum==2024))
            return true;
        if(i==n)
            return false;
        if(dp[i][sum]!=-1)  
            return dp[i][sum];
        return dp[i][sum]=(fun(i+1,sum+coins[i],n,coins,dp)||fun(i+1,sum,n,coins,dp));
    }
    
};   


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int coins[N];
        for(int i=0 ; i<N ; i++)
            cin>>coins[i];

        Solution ob;
        cout << ob.isPossible(N,coins) << endl;
    }
    return 0;
}
// } Driver Code Ends