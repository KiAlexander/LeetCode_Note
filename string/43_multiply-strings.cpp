// https://leetcode-cn.com/problems/multiply-strings/
class Solution {
public:
	// num1的第i位(高位从0开始)和num2的第j位相乘的结果在乘积中的位置是[i+j, i+j+1]
	// 12ms,6.6MB
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        int len1 = num1.length(), len2 = num2.length();
        vector<int> res(len1 + len2);
        for (int i = len1 - 1; i >= 0; i--) {
            for (int j = len2 - 1; j >= 0; j--) {
                int val = (num1[i] - '0') * (num2[j] - '0');
                int idx = len1 + len2 - i - j - 2;
                res[idx] += val;
                res[idx + 1] += res[idx] / 10;
                res[idx] %= 10;
            }
        }
        string s = "";
        if (res.back() == 0) res.pop_back();
        for (int n : res) s += (n + '0');
        reverse(s.begin(), s.end());
        return s;
    }
};
