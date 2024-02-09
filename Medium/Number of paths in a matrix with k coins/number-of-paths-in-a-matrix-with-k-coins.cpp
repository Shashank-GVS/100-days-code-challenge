//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

        
class Solution {
public:
    long long solve(vector<vector<int>> &arr,int k,int n,int index1,int index2,  vector<vector<vector<long long >>>&dp){
        if(index1==n-1 && index2==n-1){
            if(k-arr[index1][index2]==0){
                return 1;
            }
            else{
                return 0;
            }
        }
        if(index1>n-1 || index2>n-1){
            return 0;
        }
        if(k<0){
            return 0;
        }
        if(dp[k][index1][index2]!=-1){
            return dp[k][index1][index2];
        }
        long long  down=solve(arr,k-arr[index1][index2],n,index1+1,index2,dp);
        long long right=solve(arr,k-arr[index1][index2],n,index1,index2+1,dp);
        return dp[k][index1][index2]=down+right;
    }
    
    long long numberOfPath(int n, int k, vector<vector<int>> arr){
        
        int index1=0;
        int index2=0;
        vector<vector<vector<long long >>>dp(k+1,vector<vector<long long >>

        (n+1,vector<long long >(n+1,-1)));
        return solve(arr,k,n,index1,index2,dp);
    }
};

//{ Driver Code Starts.

int main()
{
    Solution obj;
    int i,j,k,l,m,n,t;
    cin>>t;
    while(t--)
    {
        cin>>k>>n;
        vector<vector<int>> v(n+1, vector<int>(n+1, 0));
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                cin>>v[i][j];
        cout << obj.numberOfPath(n, k, v) << endl;
    }
}
// } Driver Code Ends