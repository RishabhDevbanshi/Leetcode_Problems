struct Node{
    char data;
    bool isTerminal;
    Node **children;
    
    Node(char data)
    {
        this->data = data;
        isTerminal = false;
        children = new Node*[26];
        for(int i=0;i<26;i++) children[i] = NULL;
    }
};

class WordDictionary {
    Node *trie;
    
    void insert(Node *root,string &word,int idx)
    {
        if(idx >= word.size())
        {
            root->isTerminal = true;
            return;
        }
        
        Node *child;
        int i = word[idx] - 'a';
        if(root->children[i]) child = root->children[i];
        else {
            child = new Node(word[idx]);
            root->children[i] = child;
        }
        
        insert(root->children[i],word,idx+1);
    }
    
    bool search(Node *trie,string &word,int idx)
    {
        if(!trie and word.size() > idx) return  false;
        if(!trie) return true;
        if(idx >= word.size()) return  trie->isTerminal;
        
        if(word[idx] != '.')
        {
            int i = word[idx] - 'a';
            if(!trie->children[i]) return false;
            
            return search(trie->children[i],word,idx+1);
        }
        else
        {
            for(int j=0;j<26;j++) 
            {
                if(trie->children[j] && 
                   search(trie->children[j],word,idx+1))
                    return  true;
            }
            
            return false;
        }
    }
public:
    WordDictionary() {
        trie = new Node('\0');
    }
    
    void addWord(string word) {
        insert(trie,word,0);
    }
    
    bool search(string word) {
        return search(trie,word,0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */