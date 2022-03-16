class Solution {
    
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int i=0 , j=0;
        while(i<=size(pushed) and j<size(popped))
        {
            if(i < size(pushed))
                st.push(pushed[i]);
            
            i++;
            
            while(!st.empty() and j<size(popped) and st.top() == popped[j])
            {
                j++;
                st.pop();
            }
        }
        
        return st.empty();
    }
};