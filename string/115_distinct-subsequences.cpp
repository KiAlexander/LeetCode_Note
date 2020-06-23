// https://leetcode-cn.com/problems/distinct-subsequences/
class Solution {
public:
	// 16ms,11,1MB
   	int numDistinct(string s, string t)
    {
        int m = s.size(),n = t.size(),i,j;
        //特殊情况
        if(m == 0 && n == 0)	return 1;
        if(m == 0 && n != 0)	return 0;
        if(m != 0 && n == 0)    return 1;
        //long int 数组，否则范围不够
        long int dp[m+1][n+1];   
        //初始子问题
        if(s[m-1] == t[n-1])	dp[m][n] = 1;
        else   dp[m][n] = 0;
        //动态规划过程
        for(i = m-1;i >= 1;i--)
        {
            if(s[i-1] == t[n-1])
                dp[i][n] = dp[i+1][n] + 1;
            else
                dp[i][n] = dp[i+1][n];
        }
        for(j = n-1;j >= 1;j--)	
        	dp[m][j] = 0;
        for(j = n-1;j >= 1;j--)
        {
            for(i = m-1;i >=  1;i--)
            {
                if(s[i-1] == t[j-1])
                    dp[i][j] = dp[i+1][j] + dp[i+1][j+1];
                else
                    dp[i][j] = dp[i+1][j];
            }
        }
        return dp[1][1];
    }
};