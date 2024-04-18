//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends

/*You are required to complete this method*/

class Solution{
    
    
    void PreviousSmallerElements(int* arr, int n , vector<int>& prevSmaller){
        // int n = arr.size();
        stack<int> st;
        st.push(-1);
        for(int i=0;i<n;i++){
            while(st.top() != -1 && arr[st.top()] >= arr[i]){
                st.pop();
            }
            prevSmaller[i] = st.top();
            st.push(i);
        }
    }
    void NextSmallerElements(int* arr, int n , vector<int>& nextSmaller){
        // int n = arr.size();
        stack<int> st;
        st.push(-1);
        for(int i=n-1;i>=0;i--){
            while(st.top() != -1 && arr[st.top()] >= arr[i]){
                st.pop();
            }
            nextSmaller[i] = st.top();
            st.push(i);
        }
    }
    int largestRectangleArea(int *arr, int n) {
        // int n = arr.size();
        vector<int>prevSmaller(n);
        vector<int>nextSmaller(n);

        // set corresponding previous smaller elements
        PreviousSmallerElements(arr,n,prevSmaller);
        // set corresponding next smaller elements
        NextSmallerElements(arr,n,nextSmaller);

        int area = INT_MIN;

        for(int i=0;i<n;i++){
            // rectangle ka area = l * b
            int l = arr[i]; 

            // incase nextSmaller element is not present 
            if(nextSmaller[i] == -1)nextSmaller[i]=n;

            // breadth = index of next smaller - that of previous 
            int b = nextSmaller[i] - prevSmaller[i] - 1;

            int newArea = l*b;
            area = max(area,newArea);
        }
        return area;
    }
    
  public:
  
  
    int maxArea(int M[MAX][MAX], int n, int m) {
        int area  = largestRectangleArea(M[0] , m);
        
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(M[i][j] != 0){
                    M[i][j] += M[i-1][j];
                }
            }
            area = max( area , largestRectangleArea( M[i] , m ) );
        }
        return area;
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends