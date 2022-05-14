class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> st;
        
        for(auto &mail : emails)
        {
            int i=0;
            string p = "";
            while(i<size(mail) and mail[i] != '@' and mail[i] != '+')
            {
                if(mail[i] != '.')
                    p += mail[i];
                i++;
            }
            
            while(i<size(mail) and mail[i] != '@')
                i++;
            
            p += mail.substr(i);
            
            st.insert(p);
        }
        
        return size(st);
    }
};