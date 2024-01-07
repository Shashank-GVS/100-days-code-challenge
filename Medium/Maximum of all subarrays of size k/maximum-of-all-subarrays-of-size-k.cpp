//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        vector<int>nums(arr,arr+n);
        vector<int>ans;
        if(k>nums.size()){
            ans.push_back(*max_element(nums.begin(),nums.end()));
            return ans;
        }
       
        deque<int>temp;
        int i=0;
        int j=0;
        while(i<n&&j<n){
            // int ind=0;
            while(temp.size()!=0&&temp.back()<nums[j]){
                temp.pop_back();
            }
            // for(auto it:temp){
            //     if(it<nums[j])temp.erase(it,1);
            // }
            temp.push_back(nums[j]);
            if(j-i+1==k)ans.push_back(temp.front());
            while(i<n&&j-i+1>k){
                if(temp.front()==nums[i])temp.pop_front();
                i++;
                if(j-i+1==k)ans.push_back(temp.front());
            }
            j++;
        }
        return ans;
        // your code here
    }
};

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends