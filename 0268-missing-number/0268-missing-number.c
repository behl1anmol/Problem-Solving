int missingNumber(int* nums, int numsSize) {
    int n = numsSize;
    int ans = 0;
    int i = 1;

    for(i=1; i<=n; i++){
        ans = ans ^ i;
    }

    for(i=0; i < n; i++){
        ans = ans ^ nums[i];
    }
    return ans;
}