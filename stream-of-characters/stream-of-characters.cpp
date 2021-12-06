struct Node
{
    Node *arr[26];
    bool isTer;
    
    Node()
    {
        isTer = false;
        for(int i=0;i<26;i++) arr[i] = NULL;
    }
};

void insert(string &word,Node *trie)
{
    reverse(word.begin(),word.end());
    Node *temp = trie;
    for(int i=0;i<size(word);i++)
    {
        if(!temp->arr[word[i] - 'a'])
            temp->arr[word[i] - 'a'] = new Node();
        temp = temp->arr[word[i] - 'a'];
        if(i == word.size() - 1) temp->isTer = true;
    }
}

bool search(Node *trie,list<char> &ls)
{
    Node *temp = trie;
    for(auto it = ls.begin();it != ls.end(); it++)
    {
        char ch = *it;
        if(!temp->arr[ch - 'a']) return false;
        temp = temp->arr[ch - 'a'];
        if(temp->isTer) return true;
    }
    
    return false;
}

class StreamChecker {
    Node *trie;
    int maxLen = 0;
    list<char> ls;
public:
    StreamChecker(vector<string>& words) {
        trie = new Node();
        for(auto &ele : words)
        {
            insert(ele,trie);
            maxLen = max(maxLen,(int)size(ele));
        }
    }
    
    bool query(char letter) {
        ls.push_front(letter);
        if(ls.size() > maxLen) ls.pop_back();
        return search(trie,ls);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */