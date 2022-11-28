void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int i = m-1;
    int j = n-1;
    
    while(i>=0 && j>=0){
        
        if(nums1[i]>=nums2[j]){
            nums1[i+j+1] = nums1[i];
            i--;
        }
        else{
            nums1[i+j+1] = nums2[j];
            j--;
        }
    }
    while(j>=0){
        nums1[i+j+1] = nums2[j];
        j--;
    }
    return nums1;
}