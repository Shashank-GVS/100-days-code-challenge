//{ Driver Code Starts
// A C++ program to print elements with count more than n/k

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to find all elements in the array that appear more than n/k times.
    int countOccurence(int arr[], int n, int k) {
        // Calculate the minimum count required for an element to appear more than n/k times
        int min_count = n / k;

        // Create a hash map to store the frequency of each element
        unordered_map<int, int> freq_map;

        // Count the frequency of each element in the array
        for (int i = 0; i < n; i++) {
            freq_map[arr[i]]++;
        }

        // Count the elements with frequency more than n/k
        int count = 0;
        for (auto it = freq_map.begin(); it != freq_map.end(); it++) {
            if (it->second > min_count) {
                count++;
            }
        }

        return count;
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

        for (i = 0; i < n; i++) cin >> arr[i];
        int k;
        cin >> k;
        Solution obj;
        cout << obj.countOccurence(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends