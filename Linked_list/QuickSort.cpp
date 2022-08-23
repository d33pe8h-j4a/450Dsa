//{ Driver Code Starts
#include <iostream>
#include <cstdio>
using namespace std;
 
/* a node of the singly linked list */
struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
};

/* A utility function to insert a node at the beginning of linked list */
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node = new node(new_data);
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
/* A utility function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
void quickSort(struct node **headRef);
int main()
{
	int t,n,x;
	cin>>t;
	while(t--){
		
        
        cin>>n;n=n-1;
		cin>>x;
        node *temp,*head = new node(x);
        temp=head;
        while(n--)
        {
			cin>>x;
          temp->next=new node(x);
          temp=temp->next;
			}
    
    quickSort(&head);
 
    printList(head);
 while(head!= NULL){
     temp=head;
     head=head->next;
     free(temp);
     
 }
	}
    return 0;
}
// } Driver Code Ends


 
/* a node of the singly linked list 
struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
}; */

node* getMetail(node* &head) {
    node* tail = head;
    while (tail->next) tail = tail->next;
    return tail;
}

node* getMeprev(node* &Node, node* &head) {
    if (not(Node and Node != head)) return NULL;
    node* temp = head;
    while (temp->next != Node)
    {
        temp = temp->next;
    }
    return temp;
}

void swap2(node* &a, node* &b) {
    if (not(a and b)) return;
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

node* partition(node* &head) {
    node* temp = NULL;
    node* h = head;
    node* t = head;
    while (t->next)
    {
        t = t->next;
    }
    int pivot = t->data;
    while (h != t)
    {
        if (h->data < pivot) {
            temp = temp?temp->next:head;
            swap2(temp, h);
        }
        h = h->next;
    }
    swap2(temp?temp->next:head, t);
    return temp?temp->next:head;
}

//you have to complete this function
void quickSort(struct node **headRef) {
    if (not(*headRef and (*headRef)->next)) return;
    node* pivot = partition(*headRef);
    node* pivotprev = getMeprev(pivot, *headRef);
    if (pivotprev) pivotprev->next = NULL; 
    if (*headRef != pivot) {
        quickSort(headRef);
        pivotprev = getMetail(*headRef);
        pivotprev->next = pivot;
    }
    quickSort(&(pivot->next));
}