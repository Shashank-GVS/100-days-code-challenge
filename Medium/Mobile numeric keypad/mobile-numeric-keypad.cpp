//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

        
vector<vector<int>> moves = {
    {0,8},
    {1,2,4},
    {2,1,3,5},
    {3,2,6},
    {4,1,5,7},
    {5,2,4,6,8},
    {6,3,5,9},
    {7,4,8},
    {8,0,5,7,9},
    {9,6,8}
};

long long dp[26][10];
class Solution {
    long long solve(int i, int k) {
        if(i == 1)
            return 1;
        
        if(dp[i][k] != -1)
            return dp[i][k];
        
        long long ans = 0;
        for(int j: moves[k])
            ans += solve(i - 1, j);
            
        return dp[i][k] = ans;
    }
  public:
    long long getCount(int n) {
        long long ans = 0;
        memset(dp, -1, sizeof dp);
        for(int i = 0; i < 10; i++) {
            ans += solve(n, i);
        }
        return ans;
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
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends