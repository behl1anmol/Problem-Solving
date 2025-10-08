
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) { 
        
    vector<int> num;
    int i=0;
    int j=0;
    int k=0;
            
    while(i<m && j<n){
        if(nums1[i]<nums2[j]){
            num.push_back(nums1[i++]);
        }
        else if(nums1[i]==nums2[j]){
            num.push_back(nums1[i++]);
            num.push_back(nums2[j++]);
        }
        else{
            num.push_back(nums2[j++]);
        }
    }
    while(i<m){
        num.push_back(nums1[i++]);
    }
    while(j<n){
        num.push_back(nums2[j++]);
    }
    for(int i=0;i<num.size();i++){
        nums1[i] = num[i];
    }

}
};