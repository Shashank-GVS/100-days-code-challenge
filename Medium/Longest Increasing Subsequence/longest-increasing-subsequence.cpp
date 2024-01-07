//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    
    int dpSolution(int n, int arr[]) {
        vector<int> lis(n, 1);
       for (int i = 1; i < n; i++) {
           for (int j = 0; j < i; j++) {
               if (arr[j] < arr[i]) {
                   lis[i] = max(lis[i], 1+lis[j]);
               }
           }
       }
       int res = lis[0];
       for (int val : lis) {
           res = max(res, val);
       }
       return res;
    }
    
    int ceilIndex(vector<int>& arr, int val) {
        int l = 0, r = arr.size() - 1;
        int res = arr.size();
        
        while (l <= r) {
            int mid = (l+r)/2;
            
            if (arr[mid] == val) {
                return mid;
            } else if (arr[mid] > val) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return res;
    }
    
    int binarySearchSolution(int n, int arr[]) {
        vector<int> lis;
       for (int i = 0; i < n; i++) {
           if (lis.empty() || arr[i] > lis.back()) {
               lis.push_back(arr[i]);
           } else {
               int ceil_index = ceilIndex(lis, arr[i]);
               lis[ceil_index] = arr[i];
           }
       }
       return lis.size();
    }
    
    int longestSubsequence(int n, int arr[]) {
       return binarySearchSolution(n, arr);
    }
};// your code here


//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends