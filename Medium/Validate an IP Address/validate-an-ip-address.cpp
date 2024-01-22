//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
    public:
        int isValid(string s) {
            // code here
              int c=0;
            for(char i:s){
                if(i == '.') c++;
            }
            if(c > 3 or c<3) return 0;
            int tmp =-1;
            int a =0;
            for(int i=0;i<s.size();i++){
                if(tmp > 255) return 0;
                if(s[i]!= '.' and s[i] > 57) return 0;
                else if(s[i] == '.'){
                    if(!a) return 0;
                    tmp = -1;
                    a=0;
                }
                else{
                    a++;
                    if(i and s[i-1] == s[i] and s[i] == '0') return 0;
                    if(!tmp) return 0;
                    if(tmp == -1) tmp =0;
                    tmp = (tmp*10) + (s[i]-48);
                }
            }
            if(tmp and tmp>255) return 0;
            return 1;
        }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isValid(s) << endl;
    }
    return 0;
}
// } Driver Code Ends