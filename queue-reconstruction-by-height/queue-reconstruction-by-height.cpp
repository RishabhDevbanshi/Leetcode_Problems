struct node
{
    int data;
    int pos;
    node *next;
    
    node(int data,int pos)
    {
        this->data = data;
        this->pos = pos;
        next = NULL;
    }
};

void display(node *curr)
{
    node *head = curr;
    while(head)
    {
        cout<<"( "<<head->data<<" "<<head->pos<<" ) , ";
        head = head->next;
    }
    cout<<"\n";
}

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        map<int,set<int,greater<int>>> mp;
        for(auto &val : people) mp[val[1]].insert(val[0]);
        
        node *head = new node(-1,-1);
        node *tail = head;
        
        for(auto &[key,value] : mp)
        {
            for(auto &ele : value)
            {
                node *curr = new node(ele,key);
                if(key == 0)
                {
                    tail = head->next;
                    head->next = curr;
                    curr->next = tail;
                }
                else
                {
                    node *temp = head->next; int cnt=0;
                    node *prev = head;
                    while(temp)
                    {
                        if(temp->data >= ele) cnt++;
                        if(cnt == key) break;
                        prev = temp;
                        temp = temp->next;
                    }
                    // cout<<"b ";
                    // if(!temp) cout<<"null ";
                    // else cout<<temp->data;
                    // cout<<"a\n";
                    if(!temp) prev->next = curr;
                    else {
                    prev = temp;
                    temp = prev->next;
                    prev->next = curr;
                    curr->next = temp;
                    }
                }
            }
            // display(head);
        }
        
        vector<vector<int>> res;
        // vector<int> arr(2);
        
        head = head->next;
        
        while(head)
        {
            res.push_back({head->data,head->pos});
            head = head->next;
        }
        
        return res;
    }
};