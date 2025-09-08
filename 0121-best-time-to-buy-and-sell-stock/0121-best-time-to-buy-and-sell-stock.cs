public class Solution {
    public int MaxProfit(int[] prices) {
        if(prices.Length == 1) return 0;
        int i = 0;
        int j = 1;
        int buy = prices[i];
        int profit = (prices[j] - prices[i]);
        profit = profit < 0? 0 : profit;

        while(j < prices.Length-1)
        {
            if(prices[j] < prices[i])
            {
                i = j;
                buy = prices[i];
            }
            j++;
            profit = Math.Max(profit, prices[j]-buy);
        }

        return profit;
    }
}