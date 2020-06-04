// https://leetcode-cn.com/problems/group-anagrams/
class Solution {
public:
	// 108ms,16MB
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        map<string,vector<string>> M;
        for(int i=0;i<strs.size();i++){
            string key=strs[i];
            sort(key.begin(),key.end());
            M[key].push_back(strs[i]);
        }
        for(auto ite=M.begin();ite!=M.end();ite++)
            res.push_back(ite->second);
        return res;
    }

    // 52ms,15.1MB
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>>res;
		unordered_map<string,int>usermap;
		int n = 0;
		for (string &s : strs) {
			string s1 = s;
			sort(s1.begin(), s1.end());
			if (usermap.count(s1)) {
				res[usermap[s1]].push_back(s);
			}
			else {
				usermap[s1] =n++;
				res.push_back({ s });
			}
		 }
		return res;
	}
};