//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends

//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    {
        // Your code goes here
    
         vector<int>ans;
        int m= array1.size();
        int n=array2.size();
        int i=0,j=0;
        while(i<m && j<n)
        {
            if(array1[i]<array2[j])
            {
                ans.push_back(array1[i]);
                i++;
            }
            else if(array1[i]>array2[j])
            {
                ans.push_back(array2[j]);
                j++;
            }
            else
            {
                ans.push_back(array1[i]);
                ans.push_back(array2[j]);
                i++;
                j++;
            }
        }
        if(j==n && i<m)
        {
            for(int k=i;k<m;k++)
              ans.push_back(array1[k]);
        }
         if(i==m && j<n)
        {
            for(int k=j;k<n;k++)
              ans.push_back(array2[k]);
        }
        int p=ans.size();
        float median;
        if(p%2!=0)
        {
          median = double(ans[p/2]);
          return median;
        }
        else
        {
            median = double((ans[p/2]+ans[(p/2)-1])/double(2));
            return median;
        } 
    }
};
    

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends