//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
	int sumOfPowers(int a, int b){
	    //Seives of erasthrones
	    vector<int>prime(b+1,-1);
	    if(b==1)return 0;
	    for(int i=2;i<=b;i++){
	        if(prime[i]==-1){
	            for(int j=i;j<=b;j+=i){
	                prime[j]=i;
	            }
	        }
	    }
	    
	    int ans = 0;
	    for(int i=a;i<=b;i++){
	        int x = i;
	        while(x>1){
	            x/=prime[x];
	            ans++;
	        }
	    }
	    
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int a, b;
		cin >>  a >> b;
		Solution obj;
		int ans = obj.sumOfPowers(a, b);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends