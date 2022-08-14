class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int n = nums.size();
        int l = 0;
        int r = n-1;
        
        while(l<=r){
            int mid = (l+r)/2;
            cout<<"mid: "<<mid<<" ";
            
            if(nums[mid]==target) return mid;
            
            if(nums[mid]<target) l = mid+1;
            
            if(nums[mid]>target) r = mid-1;
            
        }
        
        cout<<l<<r;
        
        return l;
        
    }
};