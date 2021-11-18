class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_map<string,int> mp;
        for(auto &ele : dictionary) mp[ele] = 1;
        stringstream s(sentence);
        string word;
        
        string res = "";
        
        while(s>>word)
        {
            string root = "";
            string to_add = word;
            for(auto &ch : word)
            {
                root += ch;
                if(mp.find(root) != mp.end()) 
                {
                    to_add = root;
                    break;
                }
            }
            
            res += to_add;
            res += " ";
        }
        
        
        return res.substr(0,res.size()-1);
    }
};