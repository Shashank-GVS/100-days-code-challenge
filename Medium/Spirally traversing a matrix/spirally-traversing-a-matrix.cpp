//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> >arr, int r, int c) 
    {
        vector<int>v;
      int top = 0, buttom = r - 1;
    int left = 0, right = c - 1;

    while (top <= buttom && left <= right) {
        for (int i = left; i <= right; i++) {
         v.push_back(arr[top][i]);
        }
        top++;

        for (int i = top; i <= buttom; i++) {
            v.push_back(arr[i][right]);
        }
        right--;

        if (top <= buttom) {
            for (int i = right; i >= left; i--) {
               v.push_back(arr[buttom][i]);
            }
            buttom--;
        }

        if (left <= right) {
            for (int i = buttom; i >= top; i--) {
               v.push_back(arr[i][left]);
            }
            left++;
        }
    }
    return v;
    }
}; 


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends