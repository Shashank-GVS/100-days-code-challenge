//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution{
public:
    bool solve(int *arr,int n,int target,int i,vector<vector<int>> &dp){
        if(target == 0) return 1;
        if(i == n) return 0;
        
        if(dp[i][target] != -1) return dp[i][target];
        int include = 0;
        if(arr[i]<=target) include = solve(arr,n,target-arr[i],i+1,dp);
        int exclude = solve(arr,n,target,i+1,dp);
        
        return dp[i][target] = exclude|include;
    }
    int equalPartition(int N, int arr[])
    {   
        int sum = 0;
        for(int i = 0;i<N;i++){
            sum += arr[i];
        }   
        
        if(sum%2==1) return 0;
        
        vector<vector<int>> dp(N+1,vector<int>((sum/2)+1,-1));
        return solve(arr,N,sum/2,0,dp);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends