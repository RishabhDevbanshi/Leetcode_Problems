struct trie{
    vector<int> index;
    vector<trie *> arr;
    bool isEnd;
    
    trie()
    {
        arr.resize(26,nullptr);
        isEnd = false;
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
            
            tmp->isEnd = true;
            // tmp->index.push_back(idx);
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
            
            // if(tmp->isEnd == false)
            //     return {};
            return tmp->index;
        };
        
        auto a = search(prefix,true);
        auto b = search(suffix,false);
        
        if(size(a) == 0 || size(b) == 0)
            return -1;
        
        unordered_set<int> st(b.begin(),b.end());
        
        // cout << "here\n";
        
        int ans = -1;
        
        for(auto &x : a)
        {
            if(st.find(x) != st.end())
            {
                if(ans == -1) ans = x;
                else ans = max(ans,x);
            }
        }
        
        return mp[{prefix,suffix}] = ans;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */