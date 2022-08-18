//{ Driver Code Starts
// driver code

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}

bool isLoop(Node* head)
{
    if(!head) return false;
    
    Node* fast = head->next;
    Node* slow = head;
    
    while( fast != slow)
    {
        if( !fast || !fast->next ) return false;
        fast=fast->next->next;
        slow=slow->next;
    }
    
    return true;
}

int length(Node* head)
{
    int ret = 0;
    while(head)
    {
        ret++;
        head = head->next;
    }
    return ret;
}


// } Driver Code Ends
/*
structure of linked list node:

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to remove a loop in the linked list.
    Node* detectLoop(Node* head)
    {
        // your code here
        struct Node *fast = head;
        struct Node *slow = head;
        while (slow and fast)
        {
            fast = fast->next;
            if (fast) fast = fast->next;
            slow = slow->next;
            if (fast == slow) return slow;
        }
        return NULL;
        
    }

    Node* getStartingNode(Node *head) 
    {
        Node * intersection = detectLoop(head);
        if (not intersection) return NULL;
        Node * temp = head;
        while (temp != intersection) {
            temp = temp->next;
            intersection = intersection->next;
        }
        return temp;
    }
    
    void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
        if (not head) return;
        Node * startOfLoop = getStartingNode(head);
        if (not startOfLoop) return;
        Node * temp = startOfLoop;
        while (temp->next != startOfLoop)
        {
            temp = temp->next;
        }
        temp->next = NULL;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        Solution ob;
        ob.removeLoop(head);
        
        if( isLoop(head) || length(head)!=n )
            cout<<"0\n";
        else
            cout<<"1\n";
    }
	return 0;
}

// } Driver Code Ends