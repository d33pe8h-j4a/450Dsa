//{ Driver Code Starts
#include<iostream>

#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2);

Node* inputList(int size)
{
    if(size==0) return NULL;
    
    int val;
    cin>> val;
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

/* Driver program to test above function*/
int main()
{
    int T,n1,n2,n3;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        
        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);
        
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}


// } Driver Code Ends


/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

int findlen(Node* &head){
    if(head == NULL){
        return 0;
    }
    Node* temp = head;
    int count = 0;

    while(temp){
        temp=temp->next;
        count++;
    }

    return count;
}

//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    int len1 = findlen(head1);
    int len2 = findlen(head2);
    
    int diff;
    int larger;
    if(len1>len2){
        diff=len1-len2;
        larger=1;
    }
    else{
        diff=len2-len1;
        larger=2;
    }

    int stepAhead=0;
    if(larger==1){
        while(stepAhead==diff){
            head1=head1->next;
            stepAhead++;
        }
    }
    else{
        while(stepAhead==diff){
            head2=head2->next;
            stepAhead++;
        }
    }

    while(head1!=NULL && head2!=NULL){
        if(head1==head2){
            return head1->data;
        }
        
        head1=head1->next;
        head2=head2->next;

    }

    return -1;
}

