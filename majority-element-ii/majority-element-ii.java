class Solution {
    public List<Integer> majorityElement(int[] nums) {
        int m1 = 0 , m2 = 0, cnt1 = 0 , cnt2 = 0;
        for(int i=0;i<nums.length;i++)
        {
            if(nums[i] == m1) cnt1++;
            else if(nums[i] == m2) cnt2++;
            else if(cnt1 == 0) {cnt1 = 1 ; m1 = nums[i];}
            else if(cnt2 == 0) {cnt2 = 1; m2 = nums[i];}
            else {cnt1--; cnt2--;}
        }
        
        cnt1 = 0; cnt2 = 0;
        for(int i=0;i<nums.length;i++)
        {
            if(nums[i] == m1) cnt1++;
            else if(nums[i] == m2) cnt2++;
        }
        
        List<Integer> ans = new ArrayList<Integer>();
        
        if(cnt1 > nums.length/3) ans.add(m1);
        if(cnt2 > nums.length/3) ans.add(m2);
        
        return ans;
    }
}