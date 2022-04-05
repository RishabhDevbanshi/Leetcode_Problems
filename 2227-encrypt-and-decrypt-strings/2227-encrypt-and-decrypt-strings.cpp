class Encrypter {
    
    unordered_map<char,string> mp;
    unordered_map<string,int> dict;
    
    
public:
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        for(int i=0;i<size(keys);i++)
        {
            mp[keys[i]] = values[i];
        }
        for(auto &ele : dictionary)
        {
            string enc = encrypt(ele);
            dict[enc]++;
        }
        
        // for(auto it : dict)
        // {
        //     cout << it.first << " " << it.second << "\n";
        // }
        
    }
    
    string encrypt(string word1) {
        
        string str = "";
        
        for(auto &ch : word1)
        {
            if(mp.find(ch) != mp.end())
                str += mp[ch];
            else 
                str += ' ';
        }
        
        // cout << word1 << " " << str << "\n";
        
        return str;
        
    }
    
    int decrypt(string word1) {
        
        if(dict.find(word1) == dict.end())
            return 0;
        
        return dict[word1];
        
        
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */