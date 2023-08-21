class Solution {
public:
    
    void merge(vector<int>& nums, int p, int q, int r){
        
        int n1 = q-p+1;
        int n2 = r-q;
        
        vector<int> arr1(n1);
        vector<int> arr2(n2);
        
        for(int i=0;i<n1;i++){
            arr1[i] = nums[p+i];
        }
        for(int i=0;i<n2;i++){
            arr2[i] = nums[q+i+1];
        }
        
        int i=0,j=0, k=p;
        
        while(k<=r && i<n1 && j<n2){
            if(arr1[i]<=arr2[j]){
                nums[k] = arr1[i];
                k++;
                i++;
            }
            else{
                nums[k] = arr2[j];
                k++;
                j++;
            }
        }
        while(i<n1 && k<=r){
            nums[k++] = arr1[i++];
        }
        while(j<n2 && k<=r){
            nums[k++] = arr2[j++];
        }
        
    }
    
    void _sortArray(vector<int>& nums, int p, int r){
        if(p<r){
            int q = p + (r-p)/2;
            _sortArray(nums, p, q);
            _sortArray(nums, q+1, r);
            merge(nums, p, q, r);
        }
    }
    
    vector<int> sortArray(vector<int>& nums) {
        int p = 0, r = nums.size();
        
        _sortArray(nums, p, r-1);
        return nums;
    }
};