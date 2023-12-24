//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
     static int cmp(pair<int,int> a,pair<int,int> b){
        return a.first<b.first;
    }
    int buyMaximumProducts(int n, int k, int price[]){
        //Write your code here
        vector<pair<int,int>> ocr;
        
        
        int ans=0;
        
        for(int i=0;i<n;i++) ocr.push_back({price[i],i+1});
        
        sort(ocr.begin(),ocr.end(),cmp);
        
        for(auto i:ocr){
            int q=k/i.first;
           // cout<<i.first<<" "<<q<<endl;
            if(q>i.second)q=i.second;
            k-=q*i.first;
            ans+=q;
        }
       
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends