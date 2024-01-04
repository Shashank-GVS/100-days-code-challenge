//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
	public:
	int TotalWays(int N)
	{
	    const int mod = 1e9 + 7;
	    
	    int prev = 2 , curr = 3;
	    if(N==1)
	        return prev * prev;
	    
	    for(int i=2 ; i<=N ; i++){
	        int temp = prev%mod + curr%mod;
	        prev = curr;
	        curr = temp;
	    }
	    return (prev * 1LL * prev)%mod;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends