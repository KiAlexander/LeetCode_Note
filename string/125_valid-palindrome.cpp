// https://leetcode-cn.com/problems/valid-palindrome/
class Solution {
public:
	// 12ms,7.5MB
    bool isPalindrome(string s) {
        string str;
        //只保存字母数字
        for(int i=0;i<s.length();i++)
        {
            if(isalnum(s[i]))
            {
                str+=tolower(s[i]);
            }
        }
        //判断是否是回文
        int len = str.length();
        for(int i=0;i<len/2;i++)
        {
            if(str[i]!=str[len-1-i])
            {
                return false;
            }
        }
        return true;
    }
};
