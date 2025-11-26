class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size()-1;
        vector<int> arr(2);

        while(l<r)
        {
            int sum = numbers[l]+numbers[r];
            if(sum == target)
            {
                arr[0] = l+1;
                arr[1] = r+1;
                return arr;
            }
            else if(sum < target)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return arr;
    }
};