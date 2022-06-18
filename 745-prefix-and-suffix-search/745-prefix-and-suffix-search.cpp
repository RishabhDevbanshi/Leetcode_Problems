struct trie{
    vector<int> index;
    vector<trie *> arr;
    
    trie()
    {
        arr.resize(26,nullptr);
    }
    
};

class WordFilter {
    trie *pre, *suff;
    map<pair<string,string>,int> mp;
public:
    WordFilter(vector<string>& words) {
        pre = new trie();
        suff = new trie();
        
        auto add = [&](string &word , int idx , bool ok){
            trie *tmp;
            if(ok) tmp = pre;
            else tmp = suff;
            
            for(auto &ch : word)
            {
                if(tmp->arr[ch - 'a'] == nullptr)
                    tmp->arr[ch - 'a'] = new trie();
                tmp = tmp->arr[ch - 'a'];
                tmp->index.push_back(idx);
            }
        };
        
        for(int i=0;i<size(words);i++)
        {
            add(words[i] , i , true);
            reverse(words[i].begin(),words[i].end());
            add(words[i],i,false);
        }
        
    }
    
    int f(string prefix, string suffix) {
        reverse(suffix.begin(),suffix.end());
        
        if(mp.find({prefix,suffix}) != mp.end())
            return mp[{prefix,suffix}];
        
        auto search = [&](string &word,bool ok)->vector<int>{
            trie *tmp;
            if(ok) tmp = pre;
            else tmp = suff;
            
            for(auto &ch : word)
            {
                if(tmp->arr[ch - 'a'] == nullptr)
                    return {};
                tmp = tmp->arr[ch - 'a'];
            }
            
            return tmp->index;
        };
        
        auto a = search(prefix,true);
        auto b = search(suffix,false);
        
        int i=size(a)-1 , j = size(b)-1;
        
        while(i>=0 and j>=0)
        {
            if(a[i] == b[j])
                return mp[{prefix,suffix}] = a[i];
            if(a[i] > b[j]) i--;
            else j--;
        }
        
        return mp[{prefix,suffix}] =  -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */