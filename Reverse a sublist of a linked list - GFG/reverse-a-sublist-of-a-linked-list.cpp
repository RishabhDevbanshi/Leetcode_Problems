// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};


 // } Driver Code Ends
//User function Template for C++

/*Link list node 
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
    public:
    Node* reverseBetween(Node* head, int m, int n)
    {
        int cnt = 1;
        Node *curr = head;
        while(cnt < n and curr)
        {
            cnt++;
            curr = curr->next;
            // cout << curr->data << " ";
        }
        // cout << "\n";
        
        Node *next = nullptr;
        
        if(curr)
        {
            next = curr->next;
            curr->next = nullptr;
        }
        
        if(m == 1)
        {
            Node *a = head, *prev = NULL,  *c;
            while(a)
            {
                c = a->next;
                a->next = prev;
                prev = a;
                a = c;
            }
            
            head->next = next;
            return prev;
        }
        else
        {
            Node *tmp = nullptr; cnt = 0;
            do
            {
                tmp = tmp ? tmp->next : head;
                cnt++;
                // cout << tmp->data << "\n";
            }while(cnt < m-1 and tmp);
            
            
            if(!tmp || !tmp->next)
                return head;
            
            // cout << tmp->data << "\n";
            
            Node *pehle = tmp;
            
            curr = pehle->next; pehle->next = nullptr;
            
            // cout << "curr = " << curr->data << "\n";
            
            Node *p = curr , *q = nullptr , *r;
            while(p)
            {
                r = p->next;
                p->next = q;
                q = p;
                p = r;
            }
            
            pehle->next = q;
            curr->next = next;
            return head;
        }
        
        return head;
    }
};

// { Driver Code Starts.

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}



// Driver program to test above functions
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int N, m, n;
		cin >> N>>m>>n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < N; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

		

        Solution ob;

		Node* newhead = ob.reverseBetween(head, m, n);
		printList(newhead);

		cout << "\n";



	}
	return 0;
}
  // } Driver Code Ends