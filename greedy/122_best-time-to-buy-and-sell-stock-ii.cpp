class Solution {
public:
    // 只要今天比昨天大，就卖出。
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