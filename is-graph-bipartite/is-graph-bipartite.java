class Solution {
    public boolean isBipartite(int[][] graph) {
        int n = graph.length;
        int []color = new int[n];
        Arrays.fill(color,-1);

        
        Queue<Integer>qu = new LinkedList<>();
        for(int i=0;i<n;i++)
        {
            if(color[i] != -1) continue;
            qu.add(i);
            color[i]=0;

            while(!qu.isEmpty()){
                int top = qu.poll();
                int col = color[top];

                for(int x: graph[top]){
                    if(color[x]==-1)
                        {qu.add(x); color[x]=1-col;}
                    else if(color[x]==color[top]) return false;
                }
            }
        }
        
        return true;
    }
}

