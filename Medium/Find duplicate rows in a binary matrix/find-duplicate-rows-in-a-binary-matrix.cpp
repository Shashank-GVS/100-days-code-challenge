//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

//User function Template for C++

class Solution
{   
    public:
    vector<int> repeatedRows(vector<vector<int>> &matrix, int M, int N) 
    { 
        // Your code her
vector<int>ansi;
      
        unordered_map<int,int>mp;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=n-1;i>=0;i--){
            int count=0;
            int ans=0;
            for(int j=m-1;j>=0;j--){
                if(matrix[i][j]!=0)
                ans+=1<<count;
                count++;
            }
            if(mp.find(ans)!=mp.end() ){ansi.push_back(mp[ans]);
            mp[ans]=i;
            }
            else mp[ans]=i;
        }
        
   sort(ansi.begin(),ansi.end());
    return ansi;
        
    } 
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        vector<int> ans = ob.repeatedRows(matrix, row, col);


        for (int i = 0; i < ans.size(); ++i)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}



// } Driver Code Ends