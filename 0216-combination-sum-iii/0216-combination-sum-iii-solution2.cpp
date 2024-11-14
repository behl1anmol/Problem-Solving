class Solution {
public:
    void combinationSum3(vector<int> nums, set<vector<int>> &ans, vector<int> temp, int idx, int sum, int k) {
    if (sum == 0 && temp.size() == k) {
            ans.insert(temp); // Insert into set to ensure uniqueness
        }

        if (idx >= nums.size() || sum < 0 || temp.size() > k || (temp.size() == k && sum != 0)) return;
        
        temp.push_back(nums[idx]);
        combinationSum3(nums, ans, temp, idx + 1, sum - nums[idx], k);
        temp.pop_back();
        combinationSum3(nums, ans, temp, idx + 1, sum, k);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums;
        set<vector<int>> ans; // Use set for unique combinations
        vector<int> temp;

        for (int i = 1; i <= 9; i++) {
            nums.push_back(i);
        }

        combinationSum3(nums, ans, temp, 0, n, k);

        // Convert set back to vector for the final output
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};