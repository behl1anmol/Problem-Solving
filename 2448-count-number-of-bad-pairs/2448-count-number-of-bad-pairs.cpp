class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        long long goodPairs = 0;
        long long n = nums.size();

        for(int i=0;i<n;i++)
        {
            int key = nums[i]-i;
            goodPairs = goodPairs + mp[key];
            mp[key]++;
        }    

        return (n*(n-1)) / 2 - goodPairs;
    }
};