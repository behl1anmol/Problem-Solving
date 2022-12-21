class Solution {
public:
     int isPalindrome(string s, int left, int right){

        while(left>=0 && right < s.size() && s[left]==s[right]){
            left--;
            right++;
        }
        return right-left-1;
    }


    string longestPalindrome(string s) {

        int n = s.size();
        int l = 0, r = 0;
        for(int i=0;i<n;i++){
            //odd palindrome
            int i1 = isPalindrome(s, i, i); 
            //even palindrome
            int i2 = isPalindrome(s, i, i+1);
            int maxLen = max(i1, i2);

            if(maxLen > (r-l)){
                l = i - (maxLen-1)/2;
                r = i + maxLen/2;
            }
        }
        string ans = "";
        for(int i=l;i<=r;i++){
            ans = ans+s[i];
        }
        return ans;
    }

};