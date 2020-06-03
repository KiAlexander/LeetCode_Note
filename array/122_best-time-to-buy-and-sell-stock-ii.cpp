// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/
// 算法可以直接简化为只要今天比昨天大，就卖出。
class Solution {
public:
	// 4ms,7.2MB
    int maxProfit(vector<int>& prices) {
        int tmp = prices[0];
        int profit = 0;
        for(int i= 1;i<prices.size();i++){
            if(prices[i]>tmp){
                profit+=prices[i]-tmp;
            }
            tmp = prices[i];

        }
        return profit;
        
    }
};