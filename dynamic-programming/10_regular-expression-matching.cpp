// https://leetcode-cn.com/problems/regular-expression-matching/
class Solution {
public:
	// 1.递归
	// 如果p为空，s为空匹配，s非空不匹配；
	// s非空，p == s || p == '.'时第一个字符匹配；
	// (p+1) != ''，则递归判断剩下的是否匹配 first_match && isMatch(++s, ++p)
	// (p+1) == '*'，则有两种情况匹配：
	// 	*匹配0个字符，s匹配剩下的，即isMatch(s, p+2)
	// 	*匹配1个字符，继续用p匹配剩下的s，即first_match && isMatch(s+1, p)

	// 36ms,6.1MB
    bool isMatch(string s, string p) {
        return isMatch(s.c_str(), p.c_str());
    }
    
    bool isMatch(const char* s, const char* p) {
        if(*p == 0) return *s == 0;
        
        auto first_match = *s && (*s == *p || *p == '.');
        
        if(*(p+1) == '*'){
            return isMatch(s, p+2) || (first_match && isMatch(++s, p));
        }
        else{
            return first_match && isMatch(++s, ++p);
        }
    }

    // 2
    // 0ms,6.4MB
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        int f[n + 1]; memset(f, 0, sizeof f);
        
        f[0] = true;
        for (int j = 1; j <= n; ++j)
            f[j] = j >= 2 && p[j - 1] == '*' && f[j - 2];
        
        for (int i = 1; i <= m; ++i){
            f[0] = false;
            bool pre = i == 1;
            for (int j = 1; j <= n; ++j){
                bool tmp = f[j];
                if (p[j - 1] != '*') f[j] = isMatch(s[i - 1], p[j - 1]) && pre;
                else f[j] = j >= 2 && (f[j - 2] || f[j] && isMatch(s[i - 1], p[j - 2]));
                pre = tmp;
            }
        }
            
        return f[n];
    }
    
    bool isMatch(char c_s, char c_p){
        return c_s == c_p || c_p == '.';
    }
};