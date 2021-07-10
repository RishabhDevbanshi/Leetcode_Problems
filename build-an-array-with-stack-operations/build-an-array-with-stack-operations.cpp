class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> arr;
        for(int i=1;i<=target.back();i++)
        {
            arr.push_back("Push");
            if(find(target.begin(),target.end(),i) == target.end()) arr.push_back("Pop");
        }
        
        return arr;
    }
};