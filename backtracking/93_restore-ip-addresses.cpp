// https://leetcode-cn.com/problems/restore-ip-addresses/
class Solution {
public:
	// dfs +剪枝
	// 0ms,6.8MB
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        dfs(ans, s, 1, 0, "");
        return ans;
    }

    void dfs(vector<string> &ans, string &s, int depth, int left, string temp) {
        if (left >= s.length()) return ;
        for (int right = left; right < s.length() && right <= left + 2; right++) {
            if (s.length() - right - 1 > 3 * (4 - depth)) continue;
            if (s.length() - right - 1 < (4 - depth)) continue;
            char ts[4];
            int i = 0;
            for (; i <= right - left; i++) ts[i] = s[i+left];
            ts[i] = '\0';
            if (is_ip(ts)) {
                if (depth == 4) {
                    temp += ts;
                    ans.push_back(temp);
                    return ;
                }
                dfs(ans, s, depth + 1, right + 1, temp + ts + ".");
            }
        }
    }

    bool is_ip(const char ts[]) {
        int a;
        sscanf(ts, "%d", &a);
        if (ts[0] == '0' && ts[1] != '\0') return false;
        if (0 <= a && a < 256) return true;
        else return false;
    }
};
