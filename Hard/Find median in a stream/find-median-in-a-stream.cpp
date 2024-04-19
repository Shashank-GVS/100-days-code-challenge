//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution
{
    public:
    //Function to insert heap.
    priority_queue<double> maxheap;
    priority_queue<double , vector<double> , greater<double>> minheap;
    double median;
    
    int sizecmp(int m , int n)
    {
        if(m==n)
            return 0;
        else if(m>n)
            return -1;
        else
            return 1;
    }
    void insertHeap(int &num)
    {
        switch(sizecmp(maxheap.size(),minheap.size()))
        {
            case 0 :
            {
                if(num>=median)
                {
                    minheap.push(num);
                    median = minheap.top();
                }
                else
                {
                    maxheap.push(num);
                    median=maxheap.top();
                }
                break;
            }
            case -1:
            {
                if(num>=median)
                {
                    minheap.push(num);
                    median=(maxheap.top()+minheap.top())/2;
                }
                else
                {
                    minheap.push(maxheap.top());
                    maxheap.pop();
                    maxheap.push(num);
                    median=(maxheap.top()+minheap.top())/2;
                }
                break;
            }
            case 1:
            {
                if(num>=median)
                {
                    maxheap.push(minheap.top());
                    minheap.pop();
                    minheap.push(num);
                    median=(maxheap.top()+minheap.top())/2;
                }
                else
                {
                    maxheap.push(num);
                    median=(maxheap.top()+minheap.top())/2;
                }
                break;
            }
        }   
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        
    }
    
    //Function to return Median.
    double getMedian()
    {
        return median;
    }
};

//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}
// } Driver Code Ends