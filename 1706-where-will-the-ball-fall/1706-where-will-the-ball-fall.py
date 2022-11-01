class Solution:
    def findBall(self, grid: List[List[int]]) -> List[int]:
        
        n = len(grid)
        m =  len(grid[0])
        
        def listToTuple(function):
            def wrapper(*args):   
                args = [tuple(map(tuple, x)) if type(x) == list else x for x in args]
                result = function(*args)
                result = tuple(result) if type(result) == list else result
                return result
            return wrapper
        
        @listToTuple
        @lru_cache(None)
        def dfs(grid, row, column, n, m):
            if row == n: return column
            nextColumn = column + grid[row][column];
            
            if nextColumn < 0 or nextColumn > m-1 or grid[row][column] != grid[row][nextColumn]: return -1
            
            return dfs(grid, row+1, nextColumn, n, m)
        
        ans = []
        
        for i in range(0,m):
            res = dfs(grid, 0, i, n, m)
            ans.append(res)
            
        return ans
        
        
        