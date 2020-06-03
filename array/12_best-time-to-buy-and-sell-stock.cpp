// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/
class Solution {
public:
	// 动态规划 前i天的最大收益 = max{前i-1天的最大收益，第i天的价格-前i-1天中的最小价格}
	// 12ms,12.9MB
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1)
            return 0;
        int minProfit = prices[0], maxProfit = 0;
        for(int i = 1; i < prices.size(); i++) {
            maxProfit = max(maxProfit, prices[i] - minProfit);
            minProfit = min(minProfit, prices[i]);
        }
        return maxProfit;   

    }
};