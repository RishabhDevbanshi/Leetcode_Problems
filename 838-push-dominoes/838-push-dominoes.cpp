class Solution {
public:
    string pushDominoes(string dominoes) {
        vector<int> right(size(dominoes)) , left(size(dominoes));
        
        string res = "";
        
        char ch = 'R' , prev = '.';
        int cnt=0;
        
        for(int i=0;i<size(dominoes);i++)
        {
            if(dominoes[i] == ch) prev = ch , cnt = 1;
            else if(dominoes[i] != '.') prev = dominoes[i];
            if(prev == ch and dominoes[i] == '.') right[i] = cnt++;
        }
        
        cnt = 0; ch = 'L'; prev = '.';
        
        for(int i=size(dominoes)-1;i>=0;i--)
        {
            if(dominoes[i] == ch) prev = ch , cnt = 1;
            else if(dominoes[i] != '.') prev = dominoes[i];
            if(prev == ch and dominoes[i] == '.') left[i] = cnt++;
        }
        
        for(int i=0;i<size(dominoes);i++)
        {
            if(!left[i] and !right[i])
                res += dominoes[i];
            else if(!left[i])
                res += 'R';
            else if(!right[i])
                res += 'L';
            else if(left[i] == right[i])
                res += '.';
            else
                res += right[i] > left[i] ? 'L' : 'R';
        }
        
        return res;
    }
};

