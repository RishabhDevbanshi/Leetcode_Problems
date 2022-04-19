// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node* partition(struct Node* head, int x);

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
int main(void) {
    int t;
    cin >> t;

    while (t--) {
        struct Node* head = NULL;
        struct Node* temp = NULL;
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            int value;
            cin >> value;
            if (i == 0) {
                head = new Node(value);
                temp = head;
            } else {
                temp->next = new Node(value);
                temp = temp->next;
            }
        }

        int k;
        cin >> k;

        // Solution ob;

        head = partition(head, k);
        printList(head);
    }

    return (0);
}
// } Driver Code Ends


// User function Template for C++

/*struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};*/

struct Node* partition(struct Node* head, int x) {
     Node *lessFirst = NULL, *lessLast = NULL;
    Node *equalFirst = NULL, *equalLast = NULL;
    Node *moreFirst = NULL, *moreLast = NULL;
    
    Node *curr = head;
    
    while(curr)
    {
        if(curr->data < x)
        {
            if(lessFirst == NULL)
            {
                lessFirst = lessLast = curr;
            }
            else
            {
                lessLast->next = curr;
                lessLast = curr;
            }
        }
        else if(curr->data == x)
        {
            if(equalFirst == NULL)
            {
                equalFirst = equalLast = curr;
            }
            else
            {
                equalLast->next = curr;
                equalLast = curr;
            }
        }
        else
        {
            if(moreFirst == NULL)
            {
                moreFirst = moreLast = curr;
            }
            else
            {
                moreLast->next = curr;
                moreLast = curr;
            }
        }
        
        curr = curr->next;
    }
    
    if(moreLast != NULL)
    {
        moreLast->next = NULL;
    }
    
    if(lessFirst == NULL)
    {
        if(equalFirst == NULL)
        {
            return moreFirst;
        }
        
        equalLast->next = moreFirst;
        
        return equalFirst;
    }
    
    if(equalFirst == NULL)
    {
        lessLast->next = moreFirst;
        
        return lessFirst;
    }
    
    lessLast->next = equalFirst;
    equalLast->next = moreFirst;
    return lessFirst;
}