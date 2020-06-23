// https://leetcode-cn.com/problems/word-search/
class Solution {
public:
	// 20ms,7.7MB
    //单词搜索
    bool dfs(vector<vector<char>>& board, int i, int j, int l, string& word) {
        if (l == word.size()) {
            return true;
        }
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()
            || board[i][j] != word[l]) return false;
        char tmp = board[i][j];
        board[i][j] = '0';
        l = l + 1;
        if (dfs(board, i - 1, j, l, word)) {
            return true;
        }
        else if (dfs(board, i, j + 1, l, word)) {
            return true;
        }
        else if (dfs(board, i + 1, j, l, word)) {
            return true;
        }
        else if (dfs(board, i, j - 1, l, word)) {
            return true;
        }
        board[i][j] = tmp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        //从起始位置开始dfs
        char c = word[0];
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == c) {
                    if (dfs(board, i, j, 0, word)) return true;
                }

            }
        }
        return false;
    }
};