//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function Template for C++
class Solution
{
public:
int mod = 1e9+7;
    int f (int x, int y, vector<vector<int>> &dp){
        if(x<0 || y<0) return 0;
        if(dp[x][y] !=  -1) return dp[x][y];
        if((x==1 && y==0)  || (x==0 && y==1)) return 1;
        return dp[x][y]= 1LL*(f(x-1,y, dp) + f(x,y-1, dp)) % mod;
    }
    int ways(int x, int y)
    {
        //code here.
        vector<vector<int>> dp(x+1,vector<int> ( y+1,-1));
        return f(x,y,dp);
        // for(int i=1;i<x+1;i++){
        //     dp[i][1] =1;
        // }
        // for(int i=1;i<y+1;i++){
        //     dp[1][i] =1;
        // }
        
        // for(int i=2;i<x+1;i++){
        //     for(int j =2;j<y+1;j++){
                
        //     }
        // }
        
        if(x<0 || y<0) return 0;
        if((x==1 && y==0)  || (x==0 && y==1)) return 1;
        return 1LL*(ways(x-1,y) + ways(x,y-1)) % mod;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        Solution ob;
        cout<<ob.ways(x,y)<<endl;
    }
	return 0;
}

// } Driver Code Ends