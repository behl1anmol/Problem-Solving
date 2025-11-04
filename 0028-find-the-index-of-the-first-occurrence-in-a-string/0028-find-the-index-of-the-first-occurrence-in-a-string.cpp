class Solution {
public:
    int strStr(string haystack, string needle) {
        int h = haystack.length();
        int n = needle.length();
        if((h==0 && n==0) || n==0){
            return 0;
        }
        if(h<n){
            return -1;
        }
        for(int i=0;i<h;i++){
            int temp = i;
            int j=0;
            while(j<n){
                if(haystack[temp]==needle[j]){
                    temp++;
                    j++;
                }
                else{
                    break;
                }
            }
            if(j==n){
                return i;
            }
        }
        return -1;
    }
};