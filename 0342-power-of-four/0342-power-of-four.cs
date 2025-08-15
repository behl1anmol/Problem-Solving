public class Solution {
    public bool IsPowerOfFour(int n) {
        var logBase4 = Math.Log(n, 4);
        return (logBase4 % 1) == 0;
    }
}