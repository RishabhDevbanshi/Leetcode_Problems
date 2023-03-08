class Solution {
    private long util(int[] piles, int l, int k){
        long time = 0;

        for(int b : piles){
            if(b <= k)  time += 1;
            else{
                time += (b/k + (b % k == 0 ? 0 : 1));
            }
        }
        return time;

    }

    public int minEatingSpeed(int[] piles, int h) {
        Arrays.sort(piles);
        int l = piles.length;

        int low = 1, high = piles[l-1], mid = 0;
        long currTime = 0;
        int res = Integer.MAX_VALUE;
        while(low <= high){
            mid = (low + high)/2;

            currTime = util(piles,l,mid);

            if(currTime > h){
                low = mid + 1;
            }else{
                high = mid - 1;
                res = mid;
            }
        }

        return res;
    }
}