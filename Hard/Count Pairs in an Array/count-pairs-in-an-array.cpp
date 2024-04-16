//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends



class Solution{
    public:
    long long int merge(vector<int>&arr, long long s, long long mid, long long e){
    
        long long temp[e-s+1];
        long long int i = s;
        long long int j = mid+1;
        long long int k = 0;
        long long int inversion = 0;
        
        while(i<=mid && j<=e){
            if(arr[i]<=arr[j]){
                temp[k++] = arr[i++];
            }
            else{
                inversion+=(mid-i+1);
                temp[k++] = arr[j++];
            }
        }
        
        while(i<=mid){
            temp[k++] = arr[i++];
        }
        
        while(j<=e){
            temp[k++] = arr[j++];
        }
        
        for(int l = s;l<=e;l++){
            arr[l] = temp[l-s];
        }
        
        return inversion;
    }
    
    long long int mergeSort(vector<int>&arr, long long s, long long e){
        long long int inversion = 0;
        
        if(s<e){
            long long int mid = s + (e-s)/2;
            inversion+=mergeSort(arr,s,mid);
            inversion+=mergeSort(arr,mid+1,e);
            inversion+=merge(arr,s,mid,e);
        }
        
        return inversion;
    }
    
    int numberOfInversions(vector<int>&a, int n) {
        return mergeSort(a,0,n-1);
    }
    
    int countPairs(int arr[] , int n ) 
    {
        vector<int>temp;
        for(int i=0;i<n;i++)temp.push_back(i*arr[i]);
        return numberOfInversions(temp,n);
    }
}; 

//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	Solution ob;
    	cout<<ob.countPairs(a, n)<<endl;
    }
}
// } Driver Code Ends