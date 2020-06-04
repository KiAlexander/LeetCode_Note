// https://leetcode-cn.com/problems/climbing-stairs/
public:
    // 0ms,6MB
    int climbStairs(int n) {
        int prev = 0;
        int cur = 1;
        for(int i = 1; i <= n ; ++i){
            int tmp = cur;
            cur += prev;
            prev = tmp;
        }
        return cur; 
    }
};