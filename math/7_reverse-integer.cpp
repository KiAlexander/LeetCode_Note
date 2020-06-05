// https://leetcode-cn.com/problems/reverse-integer/
class Solution {
public:
    // 2^31-1=2147483647,-2^31=-2147483648
    // 4ms,5.9MB
    int reverse(int x) {
         int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }

    // 4ms,5.8MB
    int reverse(int x)
    {
        int max = 0x7fffffff, min = 0x80000000;//int的最大值最小值
        long rs = 0;//用long类型判断溢出
        for(;x;rs = rs*10+x%10,x/=10);//逆序，正负通吃，不用单独考虑负值
        return rs>max||rs<min?0:rs;//超了最大值低于最小值就返回0
    }
};