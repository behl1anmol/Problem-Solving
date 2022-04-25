class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()<=1) return;
        
        int n = nums.size();
        int i=n-2;
        while(i>=0 && nums[i]>=nums[i+1]) i--;
        //cout<<i;
        if(i<0){
            reverse(nums.begin(), nums.end());
        }
        else{
            int j=n-1;
            while(nums[i]>=nums[j]) j--;
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            reverse(nums.begin()+i+1,nums.end());
            //cout<<endl;
            //for(int i=0;i<n;i++) cout<<nums[i];
        }
        
    }
};