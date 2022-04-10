class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> arr;
        int res = 0;
        
        
        for(auto &str : ops)
        {
            if(str == "+")
            {
                int n = size(arr);
                arr.push_back(arr[n-1] + arr[n-2]);
                res += arr[n-1] + arr[n-2];
            }
            else if(str == "C")
            {
                res -= arr.back();
                arr.pop_back();
            }
            else if(str == "D")
            {
                res += 2*arr.back();
                arr.push_back(2*arr.back());
            }
            else
            {
                res += stoi(str);
                arr.push_back(stoi(str));
            }
        }
        
        
        return res;
    }
};