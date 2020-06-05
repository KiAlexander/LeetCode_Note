// https://leetcode-cn.com/problems/valid-sudoku/
class Solution {
public:
	// 16ms,7.1MB
    bool isValidSudoku(vector<vector<char>>& board) {
        char row[9][9] = {0};
        char col[9][9] = {0};
        char sqr[9][9] = {0};
        for(int i = 0; i < 9; ++i)
        {
            for(int j = 0; j < 9; ++j)
            {
                char c = board[i][j];
                if(c != '.')
                {
                    if (row[i][c-'1'] == '1' || col[c-'1'][j] == '1' || sqr[3 * (i / 3) + j / 3][c-'1'] == '1') 
                    {
                        return false;
                    }
                    else
                    {
                        row[i][c-'1'] = '1';
                        col[c-'1'][j] = '1';
                        sqr[3 * (i / 3) + j / 3][c-'1'] = '1';
                    }
                }
            }
        }
        return true;
    }
};