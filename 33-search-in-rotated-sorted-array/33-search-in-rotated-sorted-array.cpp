class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;

        
        while(low<=high){
            int mid = (low+high)/2;
            if(low>high) return -1;
            
            if(target==nums[mid]) return mid;
            
            if(nums[low]<=nums[mid]){ //left array ia ascending
                if(target>=nums[low] && target<nums[mid]) high = mid-1;
                else low = mid+1;
            }
            else{ //right array is ascending
                if(target<=nums[high] && target>nums[mid]) low = mid+1;
                else high = mid-1;
            }
        }
        return -1;
    
    }
};