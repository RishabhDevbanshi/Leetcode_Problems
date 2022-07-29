class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        vector<string> res;
        for(auto &word : words)
        {
            vector<char> arr(26,'$') , rev(26,'$');
            bool ok = true;
            for(int i=0;i<size(word);i++)
            {
                int w = word[i] - 'a' , p = pattern[i] - 'a';
                if(arr[w] == '$' and rev[p] == '$')
                    arr[w] = pattern[i] , rev[p] = word[i];
                else if(arr[w] == pattern[i] and word[i] == rev[p])
                    continue;
                else
                {
                    ok = false;
                    break;
                }
            }
            
            if(ok)
                res.push_back(word);
        }
        
        return res;
    }
};