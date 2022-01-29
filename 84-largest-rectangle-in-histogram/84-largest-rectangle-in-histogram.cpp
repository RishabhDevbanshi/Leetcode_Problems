class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        st.push(-1);
        int max_area = 0;
        for(int i=0;i<=heights.size();i++)
        {
            int val = (i == heights.size()) ? -1 : heights[i];
            while(st.top() != -1 and heights[st.top()] > val)
            {
                int height = heights[st.top()];
                st.pop();
                int width = i - 1 - st.top();
                // cout<<height<<" "<<width<<"\n";
                max_area = max(max_area,height * width);
                // st.pop();
            }
            st.push(i);
        }
        
        return max_area;
    }
};