//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<long long> jugglerSequence(long long n) {
        // code here
        vector<long long> ans;
        long long ak=n;
        ans.push_back(ak);
        const float a=1.0/2.0;
        const float b=3.0/2.0;
        while(ak!=1){
            if(ak%2==0){
                ak=pow(ak,a);
            }
            else
            ak=pow(ak,b);
            ans.push_back(ak);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;

        Solution ob;
        vector<long long> ans = ob.jugglerSequence(n);
        for (long long u : ans)
            cout << u << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends