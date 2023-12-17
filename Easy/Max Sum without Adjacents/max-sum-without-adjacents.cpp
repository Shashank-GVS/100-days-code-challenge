//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int dp[100001][2];
	int solve(int i,int bit,int *arr,int& n){
	    if(i==n) return 0;
	    if(dp[i][bit]!=-1) return dp[i][bit];
	    int t=0,nt=0;
	    nt = solve(i+1,0,arr,n);
	    if(bit==0) t=arr[i]+solve(i+1,1,arr,n);
	    return dp[i][bit] = max(t,nt);
	}
	int findMaxSum(int *arr, int n) {
	    // code here
	    memset(dp,-1,sizeof dp);
	    return solve(0,0,arr,n);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends