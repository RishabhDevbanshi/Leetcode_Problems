class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k == size(num))
            return "0";
        
        stack<int> st;
        vector<int> ng(size(num),-1);
        
        for(int i=size(num)-1;i>=0;i--)
        {
            int val = num[i] - '0';
            while(!st.empty() and val <= (num[st.top()] - '0'))
                st.pop();
            if(!st.empty()) ng[i] = st.top();
            st.push(i);
        }
        
        int cnt = size(num) - k;
        
        string res = "";
        
        int tmp = 0;
        
        int idx = 0;
        
        while(size(res) < cnt and idx < size(num))
        {
            // ++tmp;
            // if(tmp == 3) break;
            int i = ng[idx];
            if(i == -1)
                res += num[idx++];
            else
            {
                // cout<<i<<" "<<size(num)<<" "<<size(res)<<"\n";
                if(size(num) - i >= cnt - size(res))
                    idx = i;
                else
                    res += num[idx++];
            }
            
            // cout<<idx<<" ";
        }
        
        idx=0;
        while(idx < size(res) and res[idx] == '0')
            idx++;
        
        if(idx == size(res))
            return "0";
         
        return res.substr(idx);
        
    }
};