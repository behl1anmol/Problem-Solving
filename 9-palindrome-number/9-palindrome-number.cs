public class Solution {
    public bool IsPalindrome(int x) {
        if(x<0) return false;
        
        string n = x.ToString();
        int len = n.Length;
        
        for(int i=0;i<len/2;i++){
            if(n[i]!=n[len-i-1]) return false;
        }
        
        return true;
    }
}