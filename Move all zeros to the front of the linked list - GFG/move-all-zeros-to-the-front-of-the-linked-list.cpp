// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
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

void push(struct Node **head_ref, int new_data) {
    struct Node *new_node = new Node(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void moveZeroes(struct Node **head);

// function to displaying nodes
void display(struct Node *head) {
    while (head != NULL) {
	    cout << head->data << " ";
	    head = head->next;
    }
    cout <<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int q;
        struct Node *Head=NULL;
        for(int i=0;i<n;i++)
        {
            cin>>q;
            push(&Head,q);
        }
        moveZeroes(&Head);
        display(Head);

    }
}
// } Driver Code Ends


//User function Template for C++
/* Linked List Node structure
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
// Move Zeros to the front of the list

Node *move(Node *head)
{
    if(!head || !head->next)
        return head;
    
    
    auto dum = move(head->next);
    
    if(!dum)
        return head;
        
    if(dum->data != 0)
    {
        head->next = dum;
        return head;
    }
    
    Node *node = new Node(head->data);
    
    Node *curr = dum;
    while(curr->next and curr->next->data == 0)
        curr = curr->next;
    
    node->next = curr->next;
    curr->next = node;
    
    return dum;
}

void moveZeroes(struct Node **head)
{
    if(!(*head) || !((*head)->next))
        return;
        
    *head = move(*head);
    
}