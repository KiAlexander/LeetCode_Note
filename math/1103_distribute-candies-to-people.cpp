class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        long k=1;
        while(k*(k+1)/2<=candies)
            ++k;
        --k;  // 计算出当前糖果最多可以发给多少个人(如果有无限个同学的话
        int last = candies - (k+1)*k/2; // 计算出最后一个人需要发给多少个（剩余的那些
        vector<int> res(num_people, 0);
        int diff = num_people; // 等差数列的差
        for(int i=0; i<num_people; ++i){
            int cnt = k/num_people + (k%num_people>i); // 计算出第i列的等差数列的长度
            res[i] = cnt*((cnt-1)*diff+2*(i+1))/2; // 以(i+1)为首项，diff为公差，cnt为数列长度，的等差数列的和 
            if ( k%num_people== i)  // 此情况是最后一个同学，需要把剩下的糖果都发给他
                res[i] += last;
        }
        return res;
    }
};