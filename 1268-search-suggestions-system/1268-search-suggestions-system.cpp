struct node{
    vector<int> idx;
    vector<node *> arr;
    
    node()
    {
        arr.resize(26,nullptr);
    }
};


class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        node *t = new node();
        
        auto add = [&](string &word,int idx){
            auto root = t;
            for(auto &ch : word)
            {
                if(root->arr[ch - 'a'] == nullptr)
                    root->arr[ch - 'a'] = new node();
                root = root->arr[ch - 'a'];
                root->idx.push_back(idx);
            }
        };
        
        sort(products.begin(),products.end());
        
        for(int i=0;i<size(products);i++)
        {
            add(products[i],i);
        }
        
        vector<vector<string>> res(size(searchWord));
        
        auto root = t;
        for(int i=0;i<size(searchWord);i++)
        {
            char ch = searchWord[i];
            if(root->arr[ch - 'a'] == nullptr)
                break;
            root = root->arr[ch - 'a'];
            int cnt = 0;
            for(auto &id : root->idx)
            {
                res[i].push_back(products[id]); cnt++;
                if(cnt == 3) break;
            }
        }
        
        return res;
    }
};