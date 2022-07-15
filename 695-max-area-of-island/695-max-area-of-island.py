class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        vis = [ [False for i in range(len(grid[0]))] for i in range(len(grid)) ]
        
        dire = [
            [1,0] , [-1,0] , [0,1] , [0,-1]
        ]
        
        def isVal(i,j):
            return i>=0 and j>=0 and i<len(grid) and j<len(grid[0]) and grid[i][j] == 1 and vis[i][j] == False
        
        def dfs(i,j):
            if isVal(i,j) == False:
                return 0
            
            vis[i][j] = True
            
            ans = 1
            for d in dire:
                ans += dfs(i+d[0],j+d[1])
            return ans
        
        maxi = 0
        
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if isVal(i,j) == True:
                    val = dfs(i,j)
                    maxi = max(maxi,val)
        
        return maxi