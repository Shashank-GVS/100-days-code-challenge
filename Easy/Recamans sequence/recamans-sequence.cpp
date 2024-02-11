//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution{
public:
    vector<int> recamanSequence(int n){
        vector<int>soln(n,0);
        map<int,bool>mp;
        for(int a=1;a<n;a++){
            soln[a] = soln[a-1]-a>0 && mp[soln[a-1]-a]==false? soln[a-1]-a : soln[a-1]+a;
            mp[soln[a]]=true;
        }
        return soln;
        // code here
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<int> ans = ob.recamanSequence(n);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends