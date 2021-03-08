class NumArray {
public:
    int n;
    int *arr;
    int *fenwickTree;
    
    void updateFenwickTree(int index,int val)
    {
        for( ; index <= n; index += (index & -index))
        {
            fenwickTree[index] += val;
        }
    }
    
    NumArray(vector<int>& nums) {
        n = nums.size();
        
        arr = new int[n+1]();
        fenwickTree = new int[n+1]();
        
        for(int i=0;i<n;i++) arr[i+1] = nums[i];
        
        for(int i=1;i<=n;i++) updateFenwickTree(i,arr[i]);
    }
    
    void update(int index, int val) {
        index++; //for 1 based indexing
        
        updateFenwickTree(index,val - arr[index]);
        arr[index] = val;
    }
    
    int query(int index)
    {
        int ans = 0;
        for( ; index > 0; index -= (index & -index))
        {
            ans += fenwickTree[index];
        }
        
        return ans;
    }
    
    int sumRange(int left, int right) {
        left++; right++;
        
        return query(right) - query(left - 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
