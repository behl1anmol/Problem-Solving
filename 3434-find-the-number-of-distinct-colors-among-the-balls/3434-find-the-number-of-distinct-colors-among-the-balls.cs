public class Solution {
    public int[] QueryResults(int limit, int[][] queries) {
        var distinct_colors = new Dictionary<int,int>();
        var balls = new Dictionary<int,int>();
        var ans = new List<int>();
        var n = queries.Count();

        foreach(var query in queries)
        {
            int num = query[0];
            int color = query[1];

            if(balls.ContainsKey(num))
            {
                int prevColor = balls[num];
                distinct_colors[prevColor]--;
                if(distinct_colors[prevColor] == 0) distinct_colors.Remove(prevColor);
            }
            if(!balls.ContainsKey(num)) balls[num] = 0;
            if(!distinct_colors.ContainsKey(color)) distinct_colors[color] = 0;
            balls[num] = color;
            distinct_colors[color]++;
            ans.Add(distinct_colors.Count());
        }
        return ans.ToArray();
    }
}