//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        unordered_map<char,int>mp;
       for(int i=0;i<s.size();i++){
           mp[s[i]]++;
       }
       vector<int>v;
       for(auto it:mp){
         v.push_back(it.second);  
       }
       sort(v.begin(),v.end());
       for(int i=0;i<k;i++){
           int s=v.size();
           v[s-1]=v[s-1]-1;
           sort(v.begin(),v.end());
       }
       int sum=0;
       for(int i=0;i<v.size();i++){
           sum+=v[i]*v[i];
       }
       return sum;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends