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
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:

    void reverse1(Node* &head)
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
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        list<int> third;
        reverse1(first);
        reverse1(second);
        Node* curr1 = first;
        Node* curr2 = second;
        int carry = 0, sum;
        while (curr1 and curr2)
        {
            sum = curr1->data + curr2->data + carry;
            third.push_back(sum % 10);
            carry = sum / 10;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        Node* rem = curr1 ? curr1 : curr2;
        while (rem) 
        {
            sum = rem->data + carry;
            third.push_back(sum % 10);
            carry = sum / 10;
            rem = rem->next;
        }
        if (carry) third.push_back(carry);
        third.reverse();
        Node* head = NULL;
        Node* tail = NULL;
        for (auto &&i : third)
        {
            Node* new_node = new Node(i);
            if (not head)
            {
                head = new_node;
                tail = new_node;
            }
            else
            {
                tail->next = new_node;
                tail = new_node;
            }
        }
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