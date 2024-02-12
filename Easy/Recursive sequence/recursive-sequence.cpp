//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function Template for C++

class Solution{
public:
    long long ans=1;
    int mod = 1e9+7;
    long long sequence(int n){
        // code here
        // int p = 1;
        // for(int i=2;i<=n;i++){
        //     int a = 1;
        //     int temp = p;
        //     p=p+1;
        //     while(a<i){
        //         p*=(p+1);
        //         a++;
        //     }
        //     cout<<p<<endl;
        //     ans+=p;
        //     p=temp;
        // }
        // return ans;
        long long ans=0;
        int st=1;
        long long mod=1e9+7;
        for(int i=1;i<n+1;i++){
            long long cur=1;
            int j=0;
            while(j<i){
                cur=(cur*st)%mod;
                st++;
                j++;
            }
            ans=(ans+cur)%mod;
        }
        return ans%mod;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends