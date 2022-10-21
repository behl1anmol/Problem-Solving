class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        return set<int>(begin(nums), end(nums)).size() - (count(begin(nums), end(nums), 0) > 0);
    }
};