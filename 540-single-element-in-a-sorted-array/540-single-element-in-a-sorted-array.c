

int singleNonDuplicate(int* nums, int numsSize){
    
    int low = 0;
    int high = numsSize-2;
    int mid = 0;
    while(low<=high){
       mid = (low+high)/2;
        
        if(mid%2!=0){
            printf("%d %d\n",mid, nums[mid]);
            if(nums[mid] == nums[mid+1]) high = mid-1; //right array
            else low = mid+1;
        }
        else{
            if(nums[mid] != nums[mid+1]) high = mid-1; //right array
            else low = mid+1;
        }
    }
    return nums[low];
}