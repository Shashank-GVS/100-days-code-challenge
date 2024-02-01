//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    int t[100001];
  Solution()
  {
      memset(t,-1,sizeof(t));
  }
    int nthFibonacci(int n)
    {
        if(n<=1)
        {
         t[n]=n;
         return t[n]%1000000007;
        }
        if(t[n]!=-1)
        return t[n]%1000000007;
        
        
        
        t[n]= nthFibonacci(n-1)%1000000007+nthFibonacci(n-2)%1000000007;
        return t[n]%1000000007;
    }
    
    int countWays(int n)
    {
       return nthFibonacci(n+1)%1000000007;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends