//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

        
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find maximum circular subarray sum.
    int normalMaxSum(int arr[], int n)
    {
    	int res = arr[0];
    	int maxEnding = arr[0];
    	for(int i = 1; i < n; i++)
    	{
    		maxEnding = max(maxEnding + arr[i], arr[i]);
    		res = max(maxEnding, res);
    	}
    	
    	return res;
    }
    int circularSubarraySum(int arr[], int n){
        int max_normal = normalMaxSum(arr, n);
    	if(max_normal < 0)
    		return max_normal;
    	int arr_sum = 0;
    	for(int i = 0; i < n; i++)
    	{
    		arr_sum += arr[i];
    		arr[i] = -arr[i];
    	}
    	int max_circular = arr_sum + normalMaxSum(arr, n);
    	return max(max_circular, max_normal);
    }
};

//{ Driver Code Starts.

int main()
 {
	int T;
	
	//testcases
	cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    //size of array
	    cin>>num;
	    int arr[num];
	    
	    //inserting elements
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	        
	    Solution ob;
	    //calling function
	    cout << ob.circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends