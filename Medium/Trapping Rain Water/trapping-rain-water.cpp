//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        long long ans=0,curr=0;
        stack <int> s;
        s.push(0);
        for(int i=1;i<n;i++){
            if(arr[i]<=arr[s.top()]){
                ans-=(i-(s.top())-1)*(arr[s.top()]-arr[i]);
                s.push(i);
            }
            else if(arr[i]>arr[s.top()]){
                long long temp=arr[s.top()],sum=0,curr;
                stack<int> s2;
                while((arr[s.top()]<=arr[i])&&(s.size()!=1)){
                    s2.push(s.top());
                    s.pop();
                }
                curr=s.top();
                while(!s2.empty()){
                    sum+=((s2.top())-curr)*(arr[s2.top()]-temp);
                    curr=s2.top();
                    s2.pop();
                }
                if(s.size()==1&&arr[s.top()]<=arr[i]){
                    ans+=(i-(s.top())-1)*(arr[s.top()]-temp)-sum;
                    s.pop();
                    s.push(i);
                }
                else if(arr[s.top()]>arr[i]){
                    ans+=(i-(s.top())-1)*(arr[i]-temp)-sum;
                    s.push(i);
                }
            }
        }
        return ans;
    }
};// code here
   
//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends