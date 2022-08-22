//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
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
    Node* merge(Node* &head1, Node* &head2) {
        Node* temp1 = head1;
        Node* temp2 = head2;
        vector<int> v;
        while (temp1 and temp2)
        {
            v.push_back(temp1->data <= temp2->data ? temp1->data : temp2->data);
            temp1->data <= temp2->data ? temp1 = temp1->next : temp2 = temp2 = temp2->next;
        }
        Node* temp = temp1?temp1:temp2;
        while (temp)
        {
            v.push_back(temp->data);
            temp = temp->next;
        }
        Node* head = NULL;
        Node* tail = NULL;
        for (auto &&i : v)
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
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        // your code here
        if (not (head and head->next)) return head;

        int len = findlen(head);
        Node* temp = head;
        for (int i = 0; i < len/2 - 1; i++)
        {
            temp = temp->next;
        }
        Node* second = mergeSort(temp->next);
        temp->next = NULL;
        Node* first = mergeSort(head);
        head = merge(first, second);
        return head;
    }
};


//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends