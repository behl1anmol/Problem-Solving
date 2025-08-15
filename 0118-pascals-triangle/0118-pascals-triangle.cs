public class Solution {
    public IList<IList<int>> Generate(int numRows) {
        var ans = new List<IList<int>>();
        ans.Add(new List<int>(){1});
        if(numRows == 1)
            return ans;
        
        for(int i = 1; i < numRows; i++)
        {
            var curr = new List<int>();
            curr.Add(1);
            for(int j = 0; j < i-1; j++)
            {
                var sum = ans[i-1][j] + ans[i-1][j+1];
                curr.Add(sum);
            }
            curr.Add(1);
            ans.Add(curr);
        }
        return ans;
    }
}