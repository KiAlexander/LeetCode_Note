// https://leetcode-cn.com/problems/simplify-path/
class Solution {
public:
	// 4ms,7.9MB
    string simplifyPath(string path) {
        vector<string> v;
        istringstream iss(path);
        string buf;
        while (getline(iss, buf, '/')) {
            if (!buf.empty() && buf != "." && buf != "..") {
                v.push_back(buf);
            } else if (!v.empty() && buf == "..") {
                v.pop_back();
            }
        }
        if (v.empty()) {
            return "/";
        }

        buf.clear();
        for (string &s : v) {
            buf += "/";
            buf += s;
        }
        return buf;
    }
};