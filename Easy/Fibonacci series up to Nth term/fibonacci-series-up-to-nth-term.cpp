//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    vector<int> Series(int n) {
       vector<int>arr(n+1);
        arr[0]=0;
        arr[1]=1;
        int mod = 1000000007;
        for(int i=2;i<=n;i++)
        {
            arr[i] = (arr[i-1]+arr[i-2])%mod;
        }
        return arr; // Code here
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;

        vector<int> ans = obj.Series(n);
        for (auto x : ans) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends