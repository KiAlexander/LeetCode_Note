// https://leetcode-cn.com/problems/text-justification/
class Solution {
public:
	// 4ms,7MB
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ret;
        string str;
        vector<int> index; // 记录每行空格的位置
        for (int i = 0; i < words.size(); i++) {
            if (str.length() + words[i].length() < maxWidth) {
                str += words[i];
                index.push_back(str.length());
                str += ' ';
            } else if (str.length() + words[i].length() == maxWidth) {
                str += words[i];
                ret.push_back(str);
                str.clear();
                index.clear();
            } else {
                int gap = maxWidth - str.length();
                if (index.size() > 1) {
                    str.erase(index.back(), 1);
                    index.pop_back();
                    gap++;
                }
                int x = 0, y = 0;
                if (!index.empty()) {
                    x = gap / index.size();
                    y = gap % index.size();
                }
                for (int j = index.size()-1; j >= 0; j--) {
                    str.insert(index[j], string(x + (j < y ? 1 : 0), ' ')); // 从后往前补齐需要的空格
                }
                ret.push_back(str);
                str = words[i];
                index.clear();
                if (str.length() < maxWidth) {
                    index.push_back(str.length());
                    str += ' ';
                }
            }
        }
        if (!str.empty()) {
            if (str.length() < maxWidth)
                str += string(maxWidth - str.length(), ' ');
            ret.push_back(str);
        }
        return ret;
    }
};