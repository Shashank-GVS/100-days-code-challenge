//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends

//User function template for C++
class Solution{
public:
	// Function to check if the
	// Pythagorean triplet exists or not
	bool checkTriplet(int arr[], int n) {
	   // if(n<3) return false;
	   // for(int i=0;i<n-2;i++){
	   //     for(int j=i;j<n-1;j++){
	   //         for(int k=j;k<n;k++){
	   //             if((arr[i]*arr[i] + arr[j]*arr[j] - arr[k]*arr[k]) == 0){return true;}
	   //             else if((arr[j]*arr[j] + arr[k]*arr[k] - arr[i]*arr[i]) == 0){return true;}
	   //             else if((arr[i]*arr[i] - arr[j]*arr[j] + arr[k]*arr[k]) == 0){return true;}
	   //         }
	   //     }
	   // }
	   // return false; 
// 	    unordered_set<int> mp;
// 	  for(int i=0;i<n;i++){
// 	      mp.insert(arr[i]*arr[i]);
// 	  }
// 	  for(int i=0;i<n;i++){
// 	      for(int j=i+1;j<n;j++){
// 	          if(mp.find(pow(arr[i],2)+pow(arr[j],2))!=mp.end()){
// 	              return true;
// 	          }
// 	      }
// 	  }
// 	  return false;


// sort(arr,arr+n);
       
//       for(int i=n-1;i>1;i--){
            
//           int l=0;
//           int r=i-1;
           
//           while(l<r){
//               if((arr[l]*arr[l])+(arr[r]*arr[r])<(arr[i]*arr[i]))
//               l++;
               
//               else if((arr[l]*arr[l])+(arr[r]*arr[r])>(arr[i]*arr[i]))
//               r--;
               
//               else 
//               return true;
//           }
//       }
//       return false;
  int hash[1001]={0};
        for(int i=0;i<n;i++)
        hash[arr[i]]++;
        for(int i=3;i<=1000;i++)
        {
           // int a=i;
            if(hash[i])
            for(int j=i+1;j<=1000;j++)
            {
               // float b=j;
                if(hash[j])
                {
                    int sum=pow(i,2)+pow(j,2);
                    int sqsum=sqrt(sum);
                    int sum1=pow(sqsum,2);
                    if(sum==sum1 && hash[sqsum])
                    {
                        return 1;
                    }
                    
                }
            }
        }
        return 0;


	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.checkTriplet(arr, n);
        if (ans) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}

// } Driver Code Ends