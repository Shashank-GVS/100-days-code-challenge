//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int padovanSequence(int n) {
        // code here
        if(n<=2){
            return 1 ; 
        }
        
        int a = 1;
        int b = 1;
        int c = 1;
        int d = -1;
        for(int i = 0; i < n - 2; i++) {
            d = (a + b)  % static_cast<int>(1e9 + 7);  ;
            a = b;
            b = c;
            c = d;
        }
        
        return d  ;  
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
        cout << ob.padovanSequence(n) << endl;
    }
    return 0;
}
// } Driver Code Ends