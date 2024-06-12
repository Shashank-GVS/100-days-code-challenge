//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countNumberswith4(int n) {
                 
        int ans = 0;
        int i = 1;
        while (i <= n) {
            int num = i;
            bool isFound = false;
            while (num > 1) {
                if (isFound == false && num % 10 == 4) {
                    ans++;
                    isFound = true;
                    break;
                }
                num /= 10;
            }
            i++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        int res = obj.countNumberswith4(n);

        cout << res << endl;
    }
}

// } Driver Code Ends