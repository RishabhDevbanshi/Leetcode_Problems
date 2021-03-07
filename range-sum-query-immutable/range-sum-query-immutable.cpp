class NumArray {
public:
    int *tree;
    int n;
    
    void buildSegmentTree(int *tree,vector<int>& arr,int index,int start,int end)
    {
        if(start > end)
        {
            return;
        }
        
        if(start == end)
        {
            tree[index] = arr[start];
            return;
        }
        
        int mid = start + (end-start)/2;
        buildSegmentTree(tree,arr,2*index,start,mid);
        buildSegmentTree(tree,arr,2*index + 1,mid + 1,end);
        
        tree[index] = tree[2*index] + tree[2*index + 1];
    }
    
    NumArray(vector<int>& nums) {
        n = nums.size();
        tree = new int[4*n + 1];
        
        buildSegmentTree(tree,nums,1,0,n-1);
    }
    
    int query(int *tree,int index,int start,int end,int qs,int qe)
    {
        if(qe < start or qs > end)
        {
            return 0;
        }
        
        if(qs <= start and qe >= end)
        {
            return tree[index];
        }
        
        int mid = start + (end-start)/2;
        
        int leftAns = query(tree,2*index,start,mid,qs,qe);
        
        int rightAns = query(tree,2*index + 1,mid + 1,end,qs,qe);
        
        return leftAns + rightAns;
    }
    
    int sumRange(int i, int j) {
        return query(tree,1,0,n-1,i,j);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */