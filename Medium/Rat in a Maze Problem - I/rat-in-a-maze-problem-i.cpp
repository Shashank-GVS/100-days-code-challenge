//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution{
    public:
    string str="DLRU";
    vector<int> di{1,0,0,-1};
    vector<int> dj{0,-1,1,0};
    bool check(vector<vector<int>> &input, int n, int i,int j){
        //  cout << "Checking indices: i = " << i << ", j = " << j << endl; 
        if(i<0 || i>=n)return false;
        if(j<0 || j>=n)return false;
        if(input[i][j]==0)return false;
        return true;
    }
    
    void helper(vector<vector<int>>& input, int n, int i,int j,string temp,vector<string>& ans){
        if(i==n-1 && j==n-1){
            ans.push_back(temp);
            // return true;
        }
       for(int k=0;k<4;k++){
           int ni=i+di[k],nj=j+dj[k];
           if(check(input,n,ni,nj)){
                    temp.push_back(str[k]);
                    input[i][j]=0;
                    helper(input,n,ni,nj,temp,ans);
                    input[i][j]=1;
                    temp.pop_back();
            }
       }
        // //  check for DOWN direction      
        //         if(check(input,n,i+1,j)){
        //             temp.push_back('D');
        //             input[i][j]=0;
        //             helper(input,n,i+1,j,temp,ans);
        //             input[i][j]=1;
        //             temp.pop_back();
        //         }
                
        // // check for left direction       
        //         if(check(input,n,i,j-1)){
        //             temp.push_back('L');
        //             input[i][j]=0;
        //             helper(input,n,i,j-1,temp,ans);
        //         input[i][j]=1;
        //             temp.pop_back();
        //         }
                
        //  // check for right direction
        //         if(check(input,n,i,j+1)){
        //             temp.push_back('R');
        //             input[i][j]=0;
        //             helper(input,n,i,j+1,temp,ans);
        //             input[i][j]=1;
        //             temp.pop_back();
        //         }
        // // check for UP direction
        //         if(check(input,n,i-1,j)){
        //             temp.push_back('U');
        //             input[i][j]=0;
        //             helper(input,n,i-1,j,temp,ans);
        //             input[i][j]=1;
        //             temp.pop_back();
        //         }
     
        
    }
    vector<string> findPath(vector<vector<int>> &input, int n) {
        vector<string> ans;
        string temp;
        if(input[0][0]==0){
            temp= "-1";
            ans.push_back(temp);
            return ans;
        }
        helper(input,n,0,0,temp,ans);
        return ans;
    }
};

    

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends