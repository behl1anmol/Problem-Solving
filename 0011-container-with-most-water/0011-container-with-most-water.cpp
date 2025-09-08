class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int n = height.size();
        
        int i=0;
        int j=n-1;
        int area = 0;
        int len = j;
        
        while(i<j){
            if(height[i]<=height[j]){
                area = max(area,height[i]*len);
                i++;
            }
            else{
                area = max(area,height[j]*len);
                j--;
            }
            len--;
        }
        return area;
    }
};