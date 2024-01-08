//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
        vector<int>lps;
        void fill(string pat)
        {
            int n=pat.size();
            lps = vector<int>(n,0);
            int i=1,len=0;
            while(i<n)
            {
                if(pat[i]==pat[len])
                {
                    len++;
                    lps[i]=len;
                    i++;
                }
                else{
                    if(len == 0)
                    {
                        i++;
                    }
                    else{
                        len = lps[len-1];
                    }
                }
            }
        }
        vector <int> search(string pat, string txt)
        {
            fill(pat);
            int i=0,j=0;
            int n=txt.size();
            int m=pat.size();
            vector<int>ans;
            while(i<n)
            {
                if(txt[i]==pat[j])
                {
                    i++;
                    j++;
                }
                if(j==m)
                {
                    ans.push_back(i-j+1);
                    j=lps[j-1];
                }
                else if(i<n and txt[i]!=pat[j])
                {
                    if(j==0) i++;
                    else j=lps[j-1];
                }
            }
            return ans;
        }
     
};//code hee.

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends