class Solution {
    public String simplifyPath(String path) {
        
        String tokens[] = path.split("/+");
        Stack<String> stack = new Stack<>();
        for(int i = 0;i<tokens.length;i++){
            if(!stack.isEmpty() && "..".equals(tokens[i])){
                stack.pop();
            } else if(!Arrays.asList(".","..","").contains(tokens[i])){
                stack.push(tokens[i]);
            }
        }
        
       String str [] = new String[stack.size()];
        int k =0;
        while(!stack.isEmpty()){
          str[k++] = stack.pop();
        }
       String temp ="";
        for(int i =str.length-1;i>=0;i--){
            temp =temp +"/"+str[i];
        }
        return temp.length()==0?"/":temp;
    }
}