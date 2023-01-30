/*
Conclusion

If n > 1, we can get 2,3,4...n finally.
If n == 1, we can only get 1.

Intuition

"for 10^9 days", it's quite a long duration.
And n is much smaller than the number of days.

It's a brain-teaser,
the duration is long enough to generate all cards.

Prove

Assume n is on the board,
n % (n - 1) == 1 if n > 2,
so n - 1 will be on the board,
then n - 2 will be on the board,
same for n - 3,n - 4 .... 3, 2.

So for any n > 1,
2,3,4...n will be on the board finally,
we return n - 1

For n = 1 at first,
nothing happens,
we return 1.

So we can return n > 1 ? n - 1 : 1;
also we can return max(n - 1, 1);

Complexity

Time O(1)
Space O(1)
*/

class Solution {
public:
    int distinctIntegers(int n) {
        return n==1? 1 : n-1;
    }
};