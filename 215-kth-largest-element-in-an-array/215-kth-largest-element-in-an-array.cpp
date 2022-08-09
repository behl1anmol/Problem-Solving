#define neg(n) n*(-1)

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue <int, vector<int>, greater<int> > heap;
        
        for(int i=0;i<nums.size();i++)
            heap.push(neg(nums[i]));
        
        for(int i=0;i<k-1;i++)
            heap.pop();
        
        return neg(heap.top());
        
        
    }
};