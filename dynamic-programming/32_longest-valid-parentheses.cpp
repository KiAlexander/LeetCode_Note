// https://leetcode-cn.com/problems/longest-valid-parentheses/
class Solution {
public:
	// 用栈模拟一遍，将所有无法匹配的括号的位置全部置1
	// 此题就变成了寻找最长的连续的0的长度
	// 8ms，7.5MB
    int longestValidParentheses(string s) {
        stack<int> st;
        vector<bool> mark(s.length());
        for(int i = 0; i < mark.size(); i++) mark[i] = 0;
        int left = 0, len = 0, ans = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(') st.push(i);
            else {
                // 多余的右括号是不需要的，标记
                if(st.empty()) mark[i] = 1;
                else st.pop();
            }
        }
        // 未匹配的左括号是不需要的，标记
        while(!st.empty()) {
            mark[st.top()] = 1;
            st.pop();
        }
        // 寻找标记与标记之间的最大长度
        for(int i = 0; i < s.length(); i++) {
            if(mark[i]) {
                len = 0;
                continue;
            }
            len++;
            ans = max(ans, len);
        }
        return ans;
    }
};