// https://leetcode-cn.com/problems/sqrtx/
class Solution {
public:
	// 1.袖珍计算器
    // 用指数函数 exp 和对数函数 ln 代替平方根函数的方法
	// 时间O(1),空间O(1)
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }
        int ans = exp(0.5 * log(x));
        return ((long long)(ans + 1) * (ans + 1) <= x ? ans + 1 : ans);
    }

    // 2.二分查找
    // 由于 xx 平方根的整数部分 ans 是满足 k^2 ≤x 的最大k值，
    // 因此我们可以对 k 进行二分查找，从而得到答案。
	// 时间O(logx),空间O(1)
    int mySqrt(int x) {
        int l = 0, r = x, ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if ((long long)mid * mid <= x) {
                ans = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return ans;
    }



    //3.牛顿迭代法
    // https://en.wikipedia.org/wiki/Integer_square_root#Using_only_integer_division
	// 时间O(logx),空间O(1)
    int mySqrt(int x) {
        if(x<=1)
            return x;
        long r = x;
        while(r > x/r){
           r = (r + x/r) / 2;
        }   
        return int(r);  
        
    }
};