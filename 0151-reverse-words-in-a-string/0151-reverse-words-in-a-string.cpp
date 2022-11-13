class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        vector<string> arr;
        while(ss >> s)
        {
            arr.push_back(s);
        }
        
        s = "";
        
        for(int i=size(arr)-1;i>=0;i--)
            s += arr[i] + " ";
        
        s.pop_back();
        return s;
    }
};