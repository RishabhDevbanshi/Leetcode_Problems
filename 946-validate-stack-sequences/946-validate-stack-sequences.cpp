class Solution {
    
    void print(stack<int> st)
    {
        while(!st.empty())
        {
            cout << st.top() << " ";
            st.pop();
        }
        
        cout<<"\n";
    }
    
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        
        int i=0, j=0;
        while(i < size(pushed) and j<size(popped))
        {
            if(st.empty())
            {
                st.push(pushed[i]);
                i++;
                while(!st.empty() and j < size(popped) and st.top() == popped[j])
                {
                    j++;
                    st.pop();
                }
            }
            else 
            {
                st.push(pushed[i++]);
                // cout << st.top() << " " << j << " " << popped[j] << "\n";
                while(!st.empty() and j < size(popped) and st.top() == popped[j])
                {
                    j++;
                    // cout << "here \n";
                    st.pop();
                }
            }
            
            // print(st);
        }
        
        // print(st);
        
        while(!st.empty() and j < size(popped) and st.top() == popped[j])
        {
            j++;
            st.pop();
        }
        
        return st.empty();
    }
};