//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        sort(arr, arr+N);
        
        int ans = 1;
        int longest = 1;
        int last = arr[0];
        
        for(int i=0; i<N; i++){
            if(arr[i] == last)
                continue;
            if(arr[i] == last+1){
                longest++;
                last++;
            }
            else ans = max(ans, longest), longest = 1, last = arr[i];
        }
        ans = max(ans, longest);
        return ans;
    }
};//Your code here

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends