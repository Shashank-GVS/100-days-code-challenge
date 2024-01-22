//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends


class Solution
{
    public:
    
    struct Node* reverse(struct Node* head){
        struct Node* prev=NULL;
        struct Node* temp=head;
        struct Node* after=head;
        while(temp != NULL){
            after =temp->next;
            temp->next=prev;
            prev=temp;
            temp=after;
        }
        return prev;
    }
    void insert(struct Node* &head,struct Node* &tail,int value){
        Node* temp = new Node(value);
        if(head==NULL){
            head=temp;
            tail=head;
        }
        else{
            tail->next=temp;
            tail=temp;
        }
    }
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        struct Node* temp1=reverse(first);
        struct Node* temp2=reverse(second);
        struct Node* head=NULL;
        struct Node* tail=NULL;
        struct Node* i1=temp1;
        struct Node* i2=temp2;
        int carry=0;
        while(i1 != NULL || i2 != NULL || carry != 0){
            int digit1=0,digit2=0;
            if(i1 != NULL){
                digit1=i1->data;
            }
            if(i2 != NULL){
                digit2=i2->data;
            }
            int sum=digit1+digit2+carry;
            carry=sum/10;
            insert(head,tail,sum%10);
            if(i1 != NULL)
                i1=i1->next;
            int d2=0;
            if(i2 != NULL)
                i2=i2->next;
        }
        return reverse(head);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends