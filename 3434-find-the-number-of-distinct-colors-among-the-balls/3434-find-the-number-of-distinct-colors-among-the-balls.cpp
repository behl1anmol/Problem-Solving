class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> distinct_colors;
        unordered_map<int, int> balls;
        vector<int> ans;
        int n = queries.size();

        for(auto query : queries)
        {
            int num = query[0];
            int color = query[1];

            //balls colored
            if(balls.find(num) != balls.end())
            {
                int prevColor = balls[num];
                distinct_colors[prevColor]--;
                if(distinct_colors[prevColor] == 0) distinct_colors.erase(prevColor);
            }
            balls[num] = color;
            distinct_colors[color]++;
            ans.push_back(distinct_colors.size());
        }
        return ans;
    }
};