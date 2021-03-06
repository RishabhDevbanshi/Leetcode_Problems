class TrieNode
{
    public:
    char data;
    bool isTerminal = false;
    TrieNode **children;
    
    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode*[26];
        for(int i=0;i<26;i++) children[i] = NULL;
        bool isTerminal = false;
    }
};

class Trie {
    public:
    /** Initialize your data structure here. */
    TrieNode* root;
    
    Trie() {
        root = new TrieNode('\0');       
    }
    
    private:
    
    void insert(TrieNode* root,string word)
    {
        if(word.size()==0)
        {
            root->isTerminal = true;
            return;
        }
        
        int index = word[0] - 'a';
        TrieNode* child;
        if(root->children[index])
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        insert(child,word.substr(1));
    }
    
    bool search(TrieNode* root,string word)
    {
        if(root == NULL and word.size()>0) return false;
        if(root == NULL) return true;
        if(word.size()==0)
        {
            if(root->isTerminal) return true;
            else return false;
        }
        
        int index = word[0] - 'a';
        if(root->children[index] != NULL)
        {
            return search(root->children[index],word.substr(1));
        }
        else return false;
    }
    
    
    bool startsWith(TrieNode* root,string word)
    {
        if(word.size()==0) return true;
        
        int index = word[0] - 'a';
        if(root->children[index])
        {
            return startsWith(root->children[index],word.substr(1));
        }
        else
        {
            return false;
        }
    }
public:
    
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        insert(root,word);
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return search(root,word);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return startsWith(root,prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */