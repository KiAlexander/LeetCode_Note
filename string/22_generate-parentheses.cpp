// https://leetcode-cn.com/problems/generate-parentheses/
class Solution {
public:
	// DFS+少量的剪枝，剪枝的条件为：左括号的数目一旦小于右括号的数目，以及，左括号的数目和右括号数目均小于n。
	// 8ms,16.4MB
    vector<string> generateParenthesis(int n) {
    	// 8ms,16.4MB
        vector<string> res;
        func(res, "", 0, 0, n);
        return res;
    }
    
    void func(vector<string> &res, string str, int l, int r, int n){
        if(l > n || r > n || r > l) return ;
        if(l == n && r == n) {res.push_back(str); return;}
        func(res, str + '(', l+1, r, n);
        func(res, str + ')', l, r+1, n);
        return;
    }
};