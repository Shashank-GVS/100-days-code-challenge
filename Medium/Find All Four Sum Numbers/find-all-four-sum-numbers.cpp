//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int>> fourSum(vector<int> &arr, int k) {
        // Your code goes here
        vector<vector<int>> ans;
        sort(arr.begin(),arr.end());
        int n = arr.size();
        for(int i = 0 ; i<n ; ++i){
            if(i > 0 && arr[i] == arr[i-1]) continue;
            
            for(int j = i+1; j<n ; ++j){
                
                if(j>i+1 && arr[j] ==arr[j-1]) continue;
                int l = j+1;
                int m = n-1;
                
                while(l<m){
                    
                    long sum = arr[i]+arr[j]+arr[l]+arr[m];
                    if(sum == k){
                        ans.push_back({arr[i],arr[j],arr[l],arr[m]});
                        l++;
                        m--;
                        
                        while(l<m && arr[l] == arr[l-1])l++;
                        while(l<m && arr[m] == arr[m+1])m--;
                    }
                    
                    else if(sum<k)l++;
                    else m--;
                    
                    
                }
                
            }
        }
        // for(auto &x:ans){
        //     for(auto &y:x)cout<<y<<" ";
        //     cout<<endl;
        // }
        return ans;
        
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends