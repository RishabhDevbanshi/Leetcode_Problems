class Solution {
    int max = 0;
    public int maxProduct(String s) {
        backtrack(s,0,"","");
        return max;
    }
    
    private void backtrack(String s, int i,String s1, String s2){
        if(i == s.length()){
            if(isValid(s1) && isValid(s2)){
                max = Math.max(max, s1.length()*s2.length());
            }
            return;
        }
        backtrack(s,i+1,s1,s2);
        backtrack(s,i+1,s1+s.charAt(i),s2);
        backtrack(s,i+1,s1,s2+s.charAt(i));
    }
    private boolean isValid(String s){
        if(s == null) return false;
        for(int i = 0,j=s.length() - 1;i<j;i++,j--){
            if(s.charAt(i) != s.charAt(j)) return false;
        }
        return true;
    }
}