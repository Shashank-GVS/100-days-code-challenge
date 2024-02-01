//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool cmp(Job a, Job b){
        return a.profit > b.profit;
    }
    
    vector<int> JobScheduling(Job arr[], int n) 
    {
        sort(arr,arr+n,cmp);
        int len = 0;
        for(int i=0 ; i<n ; i++){
            len = max(len , arr[i].dead);
        }
        vector<int>slots(len,0);
        vector<int>res;
        int count = 0;
        int totalprofit = 0;
        
        for(int i=0 ; i<n ; i++){
            int currprofit = arr[i].profit;
            int currdead = arr[i].dead;
            
            for(int k=currdead-1 ; k>=0 ; k--){
                if(slots[k] == 0){
                    slots[k] = 1;
                    count++;
                    totalprofit += currprofit;
                    break;
                }
            }
        }
        
        res.push_back(count);
        res.push_back(totalprofit);
        return res;
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends