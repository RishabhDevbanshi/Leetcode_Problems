class Solution {
    bool hasLead(string str)
    {
        int n = str.size();
        if(n == 1) return false;
        return str[0] == '0';
    }
public:
    vector<string> restoreIpAddresses(string s) {
        int n = s.size();
        
        vector<string> arr;
        string a = "";
        for(int i=0;i<n-3;i++)
        {
            string b= "";
            a += s[i];
            if(a.size() > 3 or stoi(a)>255) continue;
            for(int j=i+1;j<n-2;j++)
            {
                string c="";
                b += s[j];
                if(b.size() > 3 or stoi(b)>255) continue;
                for(int k=j+1;k<n-1;k++)
                {
                    c += s[k];
                    if(c.size() > 3 or stoi(c)>255) continue;
                    
                    string d = s.substr(k+1);
                    // cout<<i<<" "<<j<<" "<<k<<" "<<d<<"\n";
                    if(d.size() > 3 or stoi(d)>255) continue;
                    if(!hasLead(a) and !hasLead(b) and !hasLead(c) and !hasLead(d))
                    {
                        string req = a + '.' + b + '.' + c + '.' + d;
                        arr.push_back(req);
                    }
                    
                }
            }
        }
        return arr;
        
    }
};