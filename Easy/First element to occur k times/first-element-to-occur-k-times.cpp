//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
    public:
    int firstElementKTime(int n, int k, int a[])
    {
        
          unordered_map<int , int>count;
        
        for(int i=0; i<n; i++) {
            
            int num = a[i];
        
            count[num]++;
            
            if(count[num]==k) {
                return num;
                break;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n, k;
	    cin >> n >> k;
	    int a[n];
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    Solution ob;
	    cout<<ob.firstElementKTime(n, k, a)<<endl;
	}
	
	return 0;
}
// } Driver Code Ends