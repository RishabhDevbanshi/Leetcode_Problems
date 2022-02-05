class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        if (nums.empty())
            return res;
        res.resize(nums.size(), 0);
        arr.resize(nums.size());
        for (int i = 0; i < nums.size(); ++i)   
            arr[i] = make_pair(nums[i], i);
        mergeSort(0, nums.size()-1);
        return res;
    }    
private:
    void mergeSort(int i, int j) {
        if (i >= j) 
            return;
        int mid = i + (j-i)/2;
        mergeSort(i, mid);
        mergeSort(mid+1, j);
        merge(i, mid, mid+1, j);
    }
    void merge(int i, int j, int k, int l) {
        vector<pair<int, int> > tmp;
        int m1 = i, m2 = k;
        while (m1 <= j && m2 <= l) {
            if (arr[m1].first > arr[m2].first) { 
                res[arr[m1].second] += 1 + l - m2;
                tmp.push_back(arr[m1++]);
            }
            else {
                tmp.push_back(arr[m2++]);                
            }            
        }
        while (m1 <= j) {
            tmp.push_back(arr[m1++]);
        }
        while (m2 <= l) {
            tmp.push_back(arr[m2++]);
        }
        swap_ranges(arr.begin()+i, arr.begin()+i+tmp.size(), tmp.begin());
    }        
    
    vector<pair<int, int> > arr;
    vector<int> res;    
};