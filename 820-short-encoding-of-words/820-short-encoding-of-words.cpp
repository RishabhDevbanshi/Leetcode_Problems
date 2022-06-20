class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        for(auto &word : words)
            reverse(word.begin(),word.end());
        
        sort(words.begin(),words.end(),[&](auto &a,auto &b){
            for(int i=0;i<min(size(a),size(b));i++)
                if(a[i] != b[i])
                    return a[i] < b[i];
            
            return size(a) < size(b);
        });
        
        int len = 0;
        for(int i=0;i<size(words)-1;i++)
        {
            string sub = words[i+1].substr(0,size(words[i]));
            // cout << sub << " " << words[i] << "\n";
            if(sub != words[i])
            {
                // cout << "here\n";
                len += size(words[i]) + 1;
            }
        }
        
        len += size(words.back()) + 1;
        
        return len;
    }
};