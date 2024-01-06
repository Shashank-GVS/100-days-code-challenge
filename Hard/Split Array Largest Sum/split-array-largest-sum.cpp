//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    bool ispossible(int cap,int arr[],int n,int k){
        int countsub=1;
        int sum=0;
        
        for(int i=0;i<n;i++){
            if(sum+arr[i]>cap){
                countsub++;
                sum=arr[i];
            }
            else{
                sum+=arr[i];
            }
        }
        if(countsub<=k)return true;
        return false;
        
    }
  public:
    int splitArray(int arr[] ,int n, int k) {
        // code here
        int maxi=INT_MIN,sum=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,arr[i]);
            sum+=arr[i];
        }
        
        int low=maxi,high=sum;
       int ans=-1;
       while(low<=high){
           int mid=low+(high-low)/2;
           if(ispossible(mid,arr,n,k)){
               ans=mid;
                high=mid-1;
           }
           else{
               low=mid+1;//we need to increase the limits so that less partion we require
           }
       }
       return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends