//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{

  public:
	int minDifference(int arr[], int n)  {
	    int sum=0,w,s1;
	    for(int i=0;i<n;i++){
	        sum+=arr[i];
	    }
	    w=sum/2;
	    vector <vector<int>> memo(n+1,vector<int>(w+1,-1));
	    w=rec(arr,n,w,memo);
	    s1=(sum/2)-w;
	    return sum-2*s1;
	}
	
	int rec(int arr[],int n,int w,vector<vector<int>> &memo){
	    if(w==0||n==0){
	        return w;
	    }
	    if(memo[n][w]!=-1){
	        return memo[n][w];
	    }
	    
	    if(arr[n-1]<=w){
	        return memo[n][w]=min(rec(arr,n-1,w,memo),rec(arr,n-1,w-arr[n-1],memo));
	    }
	    else{
	        return memo[n][w]=rec(arr,n-1,w,memo);
	    }
	}
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends