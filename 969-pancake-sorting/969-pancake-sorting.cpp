class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        
        auto rev = [&](int start,  int end){
            while(start < end)
                swap(arr[start++] , arr[end--]);
        };
        
        vector<int> res;
        
        int last = size(arr) - 1;
        
        while(last > 0)
        {
            auto it = max_element(arr.begin(),arr.end()) - arr.begin();
            if(it == last)
            {
                arr.pop_back();
                last--;
            }
            else
            {
                res.push_back(it+1);
                int start = 0 , end = it;
                rev(0,it);
                res.push_back(last+1);
                rev(0,last);
                last--;
                arr.pop_back();
            }
        }
        
        return res;
    }
};