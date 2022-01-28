struct Node
{
    Node *alpha[26];
    bool isEnd;
    
    Node()
    {
        isEnd = false;
        // alpha = new Node[26];
        for(int i=0;i<26;i++)
            alpha[i] = nullptr;
    }
};

class WordDictionary {
    Node *trie;
    
    bool recur(string &word,Node *root,int idx)
    {
        if(idx == size(word))
            return root->isEnd;
        
        char ch = word[idx];
        
        if(ch == '.')
        {
            for(int i=0;i<26;i++)
            {
                if(root->alpha[i])
                {
                    bool ok = recur(word,root->alpha[i],idx+1);
                    if(ok) return true;
                }
            }
        }
        else 
        {
            int i = ch - 'a';
            if(root->alpha[i])
                return recur(word,root->alpha[i],idx+1);
            else
                return false;
        }
        
        return false;
    }
    
public:
    WordDictionary() {
        trie = new Node();
    }
    
    void addWord(string word) {
        Node *root = trie;
        for(auto &ch : word)
        {
            if(!root->alpha[ch - 'a'])
                root->alpha[ch - 'a'] = new Node();
            
            root = root->alpha[ch - 'a'];
        }
        
        root->isEnd = true;
    }
    
    bool search(string word) {
        Node *root = trie;
        return recur(word,root,0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */