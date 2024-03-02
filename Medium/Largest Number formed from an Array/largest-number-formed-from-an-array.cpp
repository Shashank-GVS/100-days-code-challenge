//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

//User function template for C++
class Solution{
   public:
    static bool compare(string s1,string s2)
    {
       string t1=s1+s2;
       string t2=s2+s1;
       return t1<t2;
    }

public:
	// The main function that returns the arrangement with the largest value as
	// string.
	// The function accepts a vector of strings

	string printLargest(int n, vector<string> &arr) {
	    // code here
	    sort(arr.begin(),arr.end(),compare);
	    string ans="";
	    for(int i=n-1;i>=0;i--)
	    ans+=arr[i];
	    return ans;
	    
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<string> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.printLargest(n, arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends