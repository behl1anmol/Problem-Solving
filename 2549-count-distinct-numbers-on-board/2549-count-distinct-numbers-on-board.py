class Solution:
    def distinctIntegers(self, n: int) -> int:
        ans = []
        board = list()
        board.append(n)
        
        while len(board):
            ele = board.pop(0)
            if ele in ans:
                continue
            ans.append(ele)
            for i in range(2,ele):
                if ele%i == 1:
                    board.append(i)
        return len(ans)
                