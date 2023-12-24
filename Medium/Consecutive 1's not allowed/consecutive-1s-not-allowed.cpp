//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends

//User function template for C++
class Solution{
public:
#define ll long long
	
	ll func(ll n,ll i,ll prev, vector<vector<ll>> &dp){
	    if( i>=n ){
	        return 1;
	    }
	    if( dp[i][prev] != 0 ){
	        return dp[i][prev] ;
	    }
	   
	    ll count = 0;
	    if(prev == 0){
	        count = (( (func(n,i+1,0,dp)) + (func(n,i+1,1,dp)) )%1000000007) ;
	    }
	    else{
	        count = (func(n,i+1,0,dp)) ;
	    }
	    
	    return dp[i][prev] = count ;
	}
	
	ll countStrings(int n) {
        vector<vector<ll>> dp(n+1,vector<ll>(2,0));
	    return ((func(n,1,0,dp)) + (func(n,1,1,dp)) )%1000000007;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends