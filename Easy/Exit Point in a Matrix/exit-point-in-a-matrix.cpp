//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> FindExitPoint(int n, int m, vector<vector<int>>& mat) {
        // Code here
        vector<int> v(2,101);
        vector<int> ans;
        bool right=true, left=false, up=false, down=false;
        int i=0, j=0;
        while((i<n and i>-1) and (j<m and j>-1)){
            if(right and !left and !up and !down){
                if(mat[i][j]==0){
                    j++;
                } 
                else{
                    mat[i][j]=0;
                    i++;
                    right=false;
                    down=true;
                }
            }
            else if(!right and left and !up and !down){
                if(mat[i][j]==0){
                    j--;
                } 
                else{
                    mat[i][j]=0;
                    i--;
                    left=false;
                    up=true;
                }
            }
            else if(!right and !left and up and !down){
                if(mat[i][j]==0){
                    i--;
                } 
                else{
                    mat[i][j]=0;
                    j++;
                    up=false;
                    right=true;
                }
            }
            else if(!right and !left and !up and down){
                if(mat[i][j]==0){
                    i++;
                } 
                else{
                    mat[i][j]=0;
                    j--;
                    left=true;
                    down=false;
                }
            }
        }
        
        if(i<0){
            ans.push_back(++i);
            
        }
        else if(i>=n){
            ans.push_back(--i);
        }
        else{
            ans.push_back(i);
        }
        
        if(j<0){
            ans.push_back(++j);
        }
        else if(j>=m){
            ans.push_back(--j);
        }
        else{
            ans.push_back(j);
        }
        
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        vector<int> ans = obj.FindExitPoint(n, m, matrix);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends