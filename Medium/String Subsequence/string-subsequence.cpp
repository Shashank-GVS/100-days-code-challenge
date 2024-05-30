//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
   int mod=1e9+7;
    int countWays(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<int>prev(m+1,0),curr(m+1,0);
        prev[m]=1;
        curr[m]=1;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int notPick=prev[j];
                int pick=0;
                if(s1[i]==s2[j]){
                    pick=prev[j+1];
                }
                curr[j]=(pick+notPick)%mod;
            }
            prev=curr;
        }
        return prev[0]; // code here
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        Solution obj;
        int res = obj.countWays(s1, s2);

        cout << res << endl;
    }
}

// } Driver Code Ends