class Solution:
    def findPaths(self, m: int, n: int, maxMove: int, startRow: int, startColumn: int) -> int:
        
        mod = 1e9 + 7
        
        dire = [
            [1,0] , [-1,0] , [0,1] , [0,-1]
        ]
        
        dp = [[[-1 for i in range(maxMove+1)] for i in range(n+1)] for i in range(m+1)]
        
        def isVal(i,j):
                return i>=0 and j>=0 and i<m and j<n
        
        def dfs(i,j,moves)->int:
                if moves > maxMove:
                    return 0
                if isVal(i,j) == False:
                    return 1
                
                if dp[i][j][moves] != -1:
                    return dp[i][j][moves]
                
                ways = 0
                
                for d in dire:
                    ways += dfs(i+d[0],j+d[1],moves+1)
                    ways %= mod
                
                dp[i][j][moves] = int(ways%mod)
                return dp[i][j][moves]
        
        return int(dfs(startRow,startColumn,0)%mod)