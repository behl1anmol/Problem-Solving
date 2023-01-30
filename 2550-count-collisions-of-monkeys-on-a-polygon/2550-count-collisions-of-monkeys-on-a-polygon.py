class Solution:
    def monkeyMove(self, n: int) -> int:
        mod = 1000000007
        def exponentiation(base, exponent):
            if exponent == 0:
                return 1
            elif exponent == 1:
                return base%mod
            elif exponent%2==0:
                hexp = ((exponent%mod)//2)%mod
                hres = exponentiation(base,hexp)
                return (hres%mod * hres%mod)%mod
            else:
                return base*exponentiation(base,exponent-1)
        return (exponentiation(2,n)-2)%mod