// https://leetcode-cn.com/problems/implement-strstr/
class Solution {
public:
	// 4ms,6.8MB
    int strStr(string haystack, string needle) {
        if (needle.size()==0)
            return 0;
        if (needle.size() > haystack.size())
            return -1;
        int j=0;//needle指针
        int i=0;
        for (i = 0; i < haystack.size(); ++i) {
            if (j==needle.size()){//判断完成
                return i - needle.size();
            }
            if (haystack[i] == needle[j]){
                j++;
            } else{
                i -= j;
                j=0;
            }
        }
        if (j==needle.size()){//判断完成
            return i - needle.size();
        }
        return -1;
    }
};