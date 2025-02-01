class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int evenParity =  nums[0]%2;
        for(int i = 0; i<nums.size(); i++)
        {
            if(i%2 == evenParity && nums[i]%2!=0)
            {
                return false;
            }
            else if(i%2 != evenParity && nums[i]%2 == 0)
            {
                return false;
            }
        }
        return true;
    }
};