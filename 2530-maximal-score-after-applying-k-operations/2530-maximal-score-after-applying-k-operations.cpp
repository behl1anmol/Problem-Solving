class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long n = nums.size();
        priority_queue <long long> pq;
        
        for(long long i=0;i<n;i++){
            pq.push(nums[i]);
        }
        
        long long ans = 0;
        
        for(long long i=0;i<k;i++){
            long long top = pq.top();
            pq.pop();
            ans += top;
            top = ceil((double)top/3);
            pq.push(top);
        }
        
        return ans;
    }
};