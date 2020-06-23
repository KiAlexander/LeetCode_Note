// https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words/
class Solution {
public:
	// 1.暴力法
	// 940ms,17.8MB
    vector<int> findSubstring(string s, vector<string>& words) {
        if (s.empty() || words.empty()) return {};
        int n = words.size(), m = words[0].size(), j = 0;
        if (s.size() < m * n) return {};
        vector<int> res;
        unordered_map<string, int> mp, tmp;
        for (auto str : words) {
            ++mp[str];
        }
        string str = "";
        for (int i = 0; i + m * n <= s.size(); ++i) {
            for (j = i; j < i + m * n; j += m) {
                str = s.substr(j, m);
                if (mp.find(str) == mp.end()) break;
                ++tmp[str];
            }
            if (j == i + m * n && tmp == mp) res.push_back(i);
            tmp.clear();
        }
        return res;
    }

 	//  2.哈希表+滑动窗口
	// 哈希表 hash 记录给定单词 words 中单词出现的次数，
	// 滑动窗口长度就是words所有单词长度的加和，然后开始滑动窗口右移，
	// 将整个窗口分为：【每块长度与words中单词长度相同】的若干块，每一块就是一个单词，
	// 维护哈希表 h 记录单词出现次数，然后和 hash 中的次数比对，如果全部符合，那么就是答案
	// 560ms,38.6MB
	vector<int> findSubstring(string s, vector<string>& words)
    {
        vector<int> ans;
        if(words.size()==0) return ans;
        unordered_map<string, int> hash;
        int len=words[0].length(), wlen=words[0].length()*words.size();
        // 记录words中单词出现次数
        for(int i=0; i<words.size(); i++) hash[words[i]]++;
        for(int i=0; i+wlen<=s.length(); i++)
        {
            if(hash[s.substr(i, len)]==0) continue;
            unordered_map<string, int> h;
            // 记录窗口内单词出现次数
            for(int j=0; j<words.size(); j++)
                h[s.substr(i+j*len, len)]++;
            // 和hash中出现次数比对
            int cnt = 0;
            for(auto it=hash.begin(); it!=hash.end(); it++)
                if(h[it->first]==it->second) cnt++;
                else break;
            if(cnt==hash.size()) ans.push_back(i);
        }
        return ans;
    }

};