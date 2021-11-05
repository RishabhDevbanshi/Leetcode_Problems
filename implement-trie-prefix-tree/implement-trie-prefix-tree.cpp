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

class Trie {
    Node *trie;
    
    void insert(Node *trie,string word)
    {
        if(word.size() == 0) 
        {
            trie->isTerminal = true;
            return;
        }
        int i = word[0] - 'a';
        Node *child;
        if(trie->children[i]) child = trie->children[i];
        else {
            child = new Node(word[0]);
            trie->children[i] = child;
        }
        
        insert(child,word.substr(1));
    }
    
    bool search(Node *trie,string word)
    {
        if(trie == NULL and word.size()>0) return  false;
        else if(!trie) return  true;
        if(word.size() == 0) return trie->isTerminal;
        
        int i = word[0] - 'a';
        if(!trie->children[i]) return false;
        
        return search(trie->children[i],word.substr(1));
    }
    
    bool startsWith(Node *trie,string word)
    {
        if(trie == NULL and word.size()>0) return  false;
        else if(!trie) return  true;
        if(word.size() == 0) return true;
        
        int i = word[0] - 'a';
        if(!trie->children[i]) return false;
        
        return startsWith(trie->children[i],word.substr(1));
    }
public:
    Trie() {
        trie = new Node('\0');
    }
    
    void insert(string word) {
        return  insert(trie,word);
    }
    
    bool search(string word) {
        return search(trie,word);
    }
    
    bool startsWith(string prefix) {
        return startsWith(trie,prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */