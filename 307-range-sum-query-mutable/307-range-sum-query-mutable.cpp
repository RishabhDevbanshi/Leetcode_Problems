class NumArray {
    vector<int> bit;
    int n;
    vector<int> arr;
public:
    NumArray(vector<int>& nums) {
        n = size(nums);
        bit.resize(n+1);
        arr = nums;
        
        for(int i=0;i<size(nums);i++)
        {
            for(int j=i+1;j<=n;j += (j & -j))
                bit[j] += nums[i];
        }
        
    }
    
    void update(int index, int val) {
        
        for(int i=index+1;i<=n;i+=(i & -i))
            bit[i] += (val - arr[index]);
        
        arr[index] = val;
    }
    
    int sumRange(int left, int right) {
        left++ , right++;
        
        auto query = [&](int idx){
            
            int tot = 0;
            
            for(int i=idx;i>0;i -= (i & -i))
                tot += bit[i];
            
            return tot;
        };
        
        
        return query(right) - query(left-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */