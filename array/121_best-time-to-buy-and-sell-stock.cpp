// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock
class Solution {
public:
    // 记录【今天之前买入的最小值】
    // 计算【今天之前最小值买入，今天卖出的获利】，也即【今天卖出的最大获利】
    // 比较【每天的最大获利】，取最大值即可
    //12ms,12.9MB
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