//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
        // code here
       vector<int>res;
       for(int i=0;i<n;i++)
       {
           if(arr[i]==x)
           {
               res.push_back(i);
              
           }
       }
       vector<int>j;
       if(res.size()==0)
       {
           j.push_back(-1);
           j.push_back(-1);
           return j;
       }
       if(res.size()==1)
       {
           j.push_back(res[0]);
           j.push_back(res[0]);
           return j;
       }
       j.push_back(res[0]);
       j.push_back(res[res.size()-1]);
       return j;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends