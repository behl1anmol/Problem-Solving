class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, unordered_set<int>> st;
        unordered_map<int, int> balls;
        vector<int> ans;
        int n = queries.size();

        for(auto query : queries)
        {
            int num = query[0];
            int color = query[1];

            //balls colored
            if(balls.contains(num))
            {
                int prevColor = balls[num];
                st[prevColor].erase(num);
                if(st[prevColor].size() == 0) st.erase(prevColor);
            }
            balls[num] = color;
            st[color].insert(num);
            ans.push_back(st.size());
        }
        return ans;
    }
};