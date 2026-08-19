class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        int freq[51] = {};

        for(int i=0;i<n;i++)
        {
            freq[nums[i]]++;
        }

        //if a single element in subarray return the largest element
        if(k==1)
        {
            for(int i = 50; i >= 0 ; i--)
            {
                if(freq[i] == 1) return i;
            }
            return -1;
        }

        //if subarray size is whole array then return the largest element
        int answer  = -1;
        if(k == n)
        {
            for(int i=0;i<n;i++)
            {
                answer = max(answer, nums[i]);
            } 
            return answer;
        }

        answer = -1;
        //since the interior element will never be the one to occur once in a subarray 
        //we can check only for first and the last element
        if(freq[nums[0]] == 1) answer = max(answer,nums[0]);
        if(freq[nums[n-1]] == 1) answer = max(answer, nums[n-1]);

        return answer;
    }
};