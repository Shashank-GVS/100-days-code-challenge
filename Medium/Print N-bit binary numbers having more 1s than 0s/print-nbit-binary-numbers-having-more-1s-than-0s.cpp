//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template fo
//User function template for C++
class Solution{
    void solve(int n, int num0, int num1, vector<string>& ans, string& cur){
        if(cur.size()==n){
            ans.push_back(cur);
            return;
        }
        if(num0==num1){
            // just adding 1 is allowed
            cur.push_back('1');
            solve(n,num0,num1+1,ans,cur);
            cur.pop_back();
        }else{
            cur.push_back('1');
            solve(n,num0,num1+1,ans,cur);
            cur.pop_back();
            cur.push_back('0');
            solve(n,num0+1,num1,ans,cur);
            cur.pop_back();
        }
    }
public:	
	vector<string> NBitBinary(int n)
	{
	    // Your code goes here
	    vector<string> ans;
	    string cur = "";
	    solve(n,0,0,ans,cur);
	    return ans;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends