//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string S) {
        // Code here
        int x=-1;
        int y=-1;
        int z=-1;
        int ans=1e6;
        for(int i=0;i<S.size();i++){
            if(S[i]=='0'){
                x=i;
            }
            else if(S[i]=='1'){
                y=i;
            }
            else{
                z=i;
            }
            if(z!=-1 && y!=-1 && x!=-1){
                ans=min(ans,max({x,y,z})-min({x,y,z})+1);
                
            }
            
            
        }
        if(ans==1e6){
            return -1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}
// } Driver Code Ends