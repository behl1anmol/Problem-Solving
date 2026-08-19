class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        map<int,int> mp;

        for(int i=0; i< nums.size(); i++)
        {
            mp[nums[i]] = 0;
        }

        for(int i=0; i< nums.size()-k+1; i++)
        {
            unordered_map<int,int> seen;
            for(int j = 0; j < k; j++)
            {
               // cout<<nums[i+j]<<" ";
                if(seen.find(nums[i+j]) != seen.end()) continue;
                mp[nums[i+j]]++;
                seen[nums[i+j]] = 1;
            }
            //cout<<endl;
        }

        //for(const auto &pair : mp)
        //{
        //    cout<<pair.first<<":"<<pair.second<<endl;
        //}

        int res = -1;
        for (const auto &pair : mp)
        {
            if(pair.second == 1)
                res = max(res,pair.first);
        }
        return res;
    }
};