//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}


Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}


// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
};

*/
class Solution
{
    public:
    Node* reverse(Node*head){
        Node*prev=NULL;
        while(head){
            Node*next=head->next;
            head->next=prev;
            prev=head;
            head=next;
        }
        return prev;
    }
    struct Node * mergeResult(Node *node1,Node *node2)
    {
        Node* a=reverse(node1);
        Node*b=reverse(node2);
        Node* res=newNode(-1);
        Node* ans=res;
        while(a and b){
            if(a->data>b->data){
                res->next=newNode(a->data);
                a=a->next;
                res=res->next;
            }
            else{
                res->next=newNode(b->data);
                b=b->next;
                res=res->next;
            }
        }
        while(a){
            res->next=newNode(a->data);
            a=a->next;
            res=res->next;
        }
        while(b){
            res->next=newNode(b->data);
            b=b->next;
            res=res->next;
        }
        return ans->next;
    }  
};// your code goes here

//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;

        struct Node* headA=NULL;
        struct Node* tempA = headA;

        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);

            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }

        struct Node* headB=NULL;
        struct Node* tempB = headB;


        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);

            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }
        
        Solution ob;
        struct Node* result = ob.mergeResult(headA,headB);

        print(result);
        cout<<endl;


    }
}

// } Driver Code Ends