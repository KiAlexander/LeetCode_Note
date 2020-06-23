class Solution {
public:
    // 两端搜索。本题是需要从beginWord转换为endWord。
    // 两端搜索也就是说：“一头从beginWord转换为endWord，另外一头从endWord转换为beginWord。”
    // 假设从beginWord转换为endWord，存在于字典中的，（第一个）中间结果有30个。
    // 而，从endWord转换为beginWord，存在于字典中的，（第一个）中间结果只有2个。
    // 那么，很显然。从endWord开始会更快。所以，每次都从个数少的那块开始替换一位。
    // 因此，我们每次都从中间结果少的那一端出发，这样就能剪枝掉很多不必要的搜索过程。
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordDict(wordList.begin(), wordList.end());
        if (wordDict.find(endWord) == wordDict.end()){
            return 0;//Not FOUND 404
        }
        unordered_set<string> beginSet{beginWord};
        unordered_set<string> endSet{endWord};
        int step = 1;
        for (; !beginSet.empty();){
            unordered_set<string> tempSet;
            ++step;
            for (auto s : beginSet) {
                wordDict.erase(s);
            }
            for (auto s : beginSet) {
                for (int i = 0; i < s.size(); ++i){
                    string str = s;
                    for (char c = 'a'; c <= 'z'; ++c){
                        str[i] = c;
                        if (wordDict.find(str) == wordDict.end()){
                            continue;
                        }
                        if (endSet.find(str) != endSet.end()){
                            return step;
                        }
                        tempSet.insert(str);
                    }
                }
            }
            if (tempSet.size() < endSet.size()){
                beginSet = tempSet;
            } else {
                beginSet = endSet;
                endSet = tempSet;
            }
        }
        return 0;
    }
};