//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    string oddEven(string s) {
        // code here
        int odd = 0;
        int even = 0;
        unordered_map<char, int> mp;
        
        for (char x : s) {
            mp[x]++;
        }
        
        for (const auto& pair : mp) {
            char character = pair.first;
            int freq = pair.second;
            int pos = character - 'a' + 1; 
            
            if (pos % 2 == 0 && freq % 2 == 0) { 
                even++;
            }
            if (pos % 2 != 0 && freq% 2 != 0) {
                odd++;
            }
        }
        
        if ((even + odd) % 2 == 0) {
            return "EVEN";
        }
    
        return "ODD";  
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s;
        getline(cin, s);

        Solution obj;
        string res = obj.oddEven(s);

        cout << res << "\n";
    }
}

// } Driver Code Ends