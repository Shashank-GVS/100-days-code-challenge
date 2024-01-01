//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{

	public:
	int f(int arr[], int i, int sum,vector<vector<int>> &dp)
	{
	    
    if(i==0)
    {
        if(sum==0 && arr[0]==0)
        return 2;
        if(sum==0 ||arr[0]==0)
        return 1;
        return 0;
    }
    
	    if(dp[i][sum]!=-1) return dp[i][sum];
	    int not_take=f(arr,i-1,sum,dp);
	   int take=0;
	   if(arr[i] <= sum)
	   take=f(arr,i-1,sum-arr[i],dp);
	   return dp[i][sum]=take+not_take;
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
      long long  mod=1e9+7;
    vector<vector<int>> dp(n,vector<int> (sum+1,0));
     int target=sum;
     for(int i=0;i<n;i++)
     dp[i][0]=1;
     if(arr[0]<=sum)
     dp[0][arr[0]]+=1;
     for(int i=1;i<n;i++)
     {
         for(int sum=0;sum<=target;sum++)
         {
             long long not_take=dp[i-1][sum];
             long long take=0;
             if(arr[i]<=sum)
             take=dp[i-1][sum-arr[i]];
             dp[i][sum]=(take+not_take)%mod;
         }
     }
	    return dp[n-1][sum];
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends