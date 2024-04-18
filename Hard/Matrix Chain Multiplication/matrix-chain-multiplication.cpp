//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++
int t[101][101];

class Solution{
    int MCM(int i,int j,int arr[])
    {
        if(i>=j) return 0;
        if(t[i][j]!=-1) return t[i][j];
        int mn=INT_MAX;
        for(int k=i;k<j;k++)
        {
            int temp_ans=MCM(i,k,arr)+MCM(k+1,j,arr)+arr[i-1]*arr[k]*arr[j];
            mn=min(temp_ans,mn);
        }
        return t[i][j]=mn;
    }
    
public:
    int matrixMultiplication(int N, int arr[])
    {
        int i=1,j=N-1;
        memset(t,-1,sizeof(t));
        return MCM(i,j,arr);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends