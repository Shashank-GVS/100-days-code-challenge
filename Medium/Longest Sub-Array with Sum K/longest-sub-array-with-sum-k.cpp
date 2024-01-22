//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
    public:
    // BRUTE FORCE:
    // int lenOfLongSubarr(int A[],  int n, int K){
    //     int maxLength=0;
    //     for(int i=0;i<n;i++){
    //         int currSum=0;
    //         for(int j=i;j<n;j++){
    //             currSum+=A[j];
    //             if(currSum==K){
    //                 int length=j-i+1;
    //                 maxLength=max(maxLength,length);
    //             }
    //         }
    //     }
    //     return maxLength;
    //     // Complete the function
    // }
    
    
    // OPTIMISATION USING PREFIX SUM AND MAP:
    int lenOfLongSubarr(int A[],  int n, int K){
        unordered_map<int,int>ourMap;
        ourMap[0]=-1;
        int sum=0,maxLength=0;
        for(int i=0;i<n;i++){
            
            sum+=A[i];
            int target=sum-K;
            if(ourMap.count(target)){
                int length=i-ourMap[target];
                maxLength=max(maxLength,length);
            }
            if(!ourMap.count(sum)){
                ourMap[sum]=i;
            }
        }
        return maxLength;
    }
    

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends