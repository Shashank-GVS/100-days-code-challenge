//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int ans = 0,index = -1;
	    for(int i=0;i<n;i++) {
	        int low = 0,high = m-1;
	        while(low<=high) {
	            int mid = low + (high - low)/2;
	            if((mid == 0 && arr[i][mid] == 1) || (arr[i][mid] == 1 && arr[i][mid-1] == 0)) {
	                if(m-mid>ans) {
	                    index = i;
	                    ans = m-mid;
	                }
	                break;
	            } else if(arr[i][mid] == 1) {
	                high = mid -1;
	            } else {
	                low = mid + 1;
	            }
	        }
	    }
	    return index;
	}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends