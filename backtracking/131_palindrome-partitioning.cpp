// 分两步。
// 第一步对s使用dp方法确定回文子串。dp[i][j]代表s(i,j)是否为回文（包含i和j）字符串，注意当ij之间的字符大于等于3个时，dp[i][j]=dp[i+1][j-1]&&s[i]==s[j]，即i递减，j递增，又j>=i，即可确定i，j的递推方向。
// 第二步使用回溯法进行分割。dfs(i,j)，将s(i,j)放入组合，对dp[j+1][k] (j+1<=k<n)中为true的进行dfs，当j==n-1时，当前组合放入结果。注意dfs的优化，模版类使用传址，复用变量（如字符串s的大小）使用全局变量。
class Solution {
public:
    int n;//字符串长度作为全局变量 这样在dfs里不需声明变量
    vector<vector<string>> res;//回文串分割结果
    vector<vector<string>> partition(string s) {
        n=s.size();//字符串长度
        vector<vector<bool>> dp(n,vector<bool>(n,false));//dp[i][j] s(i,j)是否为回文字符串
        for(int i=n-1;i>=0;i--)//i递减
            for(int j=i;j<n;j++)//j递增 且j>=i
            {
                if(i==j)//一个字母是回文
                    dp[i][j]=true;
                else if(i==j-1)//相邻字母 相同是回文
                {
                    if(s[i]==s[j])
                        dp[i][j]=true;
                }
                else//长度>=3 中间为回文且首尾字母相同为回文
                {
                    if(s[i]==s[j]&&dp[i+1][j-1])
                        dp[i][j]=true;
                }
            }
        vector<string> temp;//组合暂存变量 储存一个有效的回文串分割
        for(int i=0;i<n;i++)
            if(dp[0][i])
                dfs(temp,dp,s,0,i);//从第一个字母开始 向后取回文串进行分割
        return res;
    }
    void dfs(vector<string>& temp,vector<vector<bool>>& dp,string s,int i,int j)
    {
        temp.push_back(s.substr(i,j-i+1));//s(i,j)放入组合
        if(j==n-1)
            res.push_back(temp);//到达单词结尾 把当前组合放入结果
        j++;//从j+1开始继续找回文串
        for(int k=j;k<n;k++)
            if(dp[j][k])
                dfs(temp,dp,s,j,k);
        temp.pop_back();//尾回溯 退出时删除本轮添加的字符串
    }
};