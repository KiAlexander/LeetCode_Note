// https://leetcode-cn.com/problems/string-to-integer-atoi/
class Solution {
public:
    // 8ms,6.2MB
    int myAtoi(string str) {
        int n=str.size();
        int start = 0;
        while (start < n && str[start] == ' ') {
            // 去掉前导空格
            start++;
        }
        if (start == n) {
            //去掉前导空格以后到了末尾了
            return 0;
        }
        bool negative = false;
        if (str[start] == '-') {
            //遇到负号
            negative = true;
            start++;
        } else if (str[start] == '+') {
            // 遇到正号
            start++;
        } else if (!isdigit(str[start])) {
            // 其他符号
            return 0;
        }
        int ans = 0;
        while (start < n && isdigit(str[start])) {
            int digit = str[start] - '0';
            if (ans > (INT_MAX - digit) / 10) {
                // 本来应该是 ans * 10 + digit > INT_MAX
                // 但是 *10 和 + digit 都有可能越界，所有都移动到右边去就可以了。
                return negative? INT_MIN : INT_MAX;
            }
            ans = ans * 10 + digit;
            start++;
        }
        return negative? -ans : ans;
    }
};