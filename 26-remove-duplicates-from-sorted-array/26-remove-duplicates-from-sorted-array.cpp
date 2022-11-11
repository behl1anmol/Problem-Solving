class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int ele = nums[0];
        
        for(int i=1;i<n;i++){
            if(nums[i]!=ele){
                ele = nums[i];
            }
            else{
                nums[i] = -101;
            }
        }
        int j = 0;
        for(int i=0;i<n;i++){
            if(nums[i]!=-101){
                nums[j] = nums[i];
                j+=1;
            }
        }
        return j;
    }
};