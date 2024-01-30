//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    int dp[21][21][21];
    int solve(int i,int j,int k,string A, string B, string C){
        if(i<0 || j<0 || k<0){
            return 0;
        }
        if(dp[i][j][k]!=-1){
            return dp[i][j][k];
        }
        if(A[i]==B[j] && B[j]==C[k]){
            return dp[i][j][k]=1+solve(i-1,j-1,k-1,A,B,C);
        }
        else{
            return dp[i][j][k]=max({solve(i-1,j,k,A,B,C),solve(i,j-1,k,A,B,C),solve(i,j,k-1,A,B,C)});
        }
    }

        int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
        {
            memset(dp,-1,sizeof(dp));
            int ans=solve(n1-1,n2-1,n3-1,A,B,C);
            return ans;
        }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        Solution obj;
        cout << obj.LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends