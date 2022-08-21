//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    void reverse(Node* &head)
    {
        // Initialize current, previous and next pointers
        Node* current = head;
        Node* prev = NULL, *nxt = NULL;
 
        while (current != NULL) {
            // Store next
            nxt = current->next;
            // Reverse current node's pointer
            current->next = prev;
            // Move pointers one position ahead.
            prev = current;
            current = nxt;
        }
        head = prev;
    }
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        reverse(head);
        Node* temp = head;
        Node* prev = NULL;
        int carry = 0;
        if (temp->data == 9) {
            temp->data = 0;
            carry = 1;
        }
        else temp->data++;
        prev = temp;
        temp = temp->next;
        while (temp)
        {
            if (carry) {
                if (temp->data == 9) temp->data = 0;
                else 
                {
                    temp->data += carry;
                    carry = 0;
                }
            }
            prev = temp;
            temp = temp->next;
        }
        if (carry) {
            Node * tmp = new Node(1);
            prev->next = tmp;
        }
        reverse(head);
        return head;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends