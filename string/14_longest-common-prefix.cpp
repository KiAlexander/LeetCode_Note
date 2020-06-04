// https://leetcode-cn.com/problems/longest-common-prefix/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
            return "";
        
        string result = strs[0];
        for (int j=1;j<strs.size();j++)
        {
            for (int i = 0; i < result.size(); i++)
            {
                if (strs[j][i] != result[i])
                {
                    result = result.substr(0, i);
                    break;
                }
            }
        }
        return result;
    }
};