class Solution:
    def reverse(self, x: int) -> int:
        if x < 0:
            x = abs(x)
            s = str(x)
            x = -1 * int(s[-1::-1])
        else:
            s = str(x)
            x = int(s[-1::-1])
        return x if (x >= -2**31) and (x <= (2**31)-1) else 0
        