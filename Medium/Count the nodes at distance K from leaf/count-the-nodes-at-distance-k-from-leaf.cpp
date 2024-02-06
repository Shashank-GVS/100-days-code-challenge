//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}



// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends

//Node Structure
/*struct NodeGiven a binary tree with n nodes and a non-negative integer k, the task is to count the number of special nodes. A node is considered special if there exists at least one leaf in its subtree such that the distance between the node and leaf is exactly k.
{
	int data;
	Node *left, *right;
};*/

class Solution
{
    public:
    //Function to return count of nodes at a given distance from leaf nodes.
    int printKDistantfromLeaf(Node* root, int k)
    {
    	//Add your code here. 
    	    queue<Node*>q,q2;
        map<Node*,Node*>mp;
        q.push(root);
        while(q.size()){
            Node *root=q.front();
            q.pop();
            if(root->left){
                mp[root->left]=root;
                q.push(root->left);
            }
            if(root->right){
                q.push(root->right);
                mp[root->right]=root;
            }
            if(!root->left and !root->right)q2.push(root);
        }
        int ans=0;
        map<Node*,bool>mp2;
        while(q2.size()){
            int p=k;
            Node *a=q2.front();
            q2.pop();
            while(p>0 and mp[a]!=NULL){
                p--;
                a=mp[a];
            }
            if(p==0){
                if(mp2[a]==0){
                    ans++;
                    
                }
                mp2[a]=1;
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s, ks;
        getline(cin, s);
        Node* root = buildTree(s);
        getline(cin, ks);
        int k=stoi(ks);
        Solution obj;
        cout<<obj.printKDistantfromLeaf(root, k)<<endl;
    }
    return 0;
}


// } Driver Code Ends