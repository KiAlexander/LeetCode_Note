class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> solveNQueens(int n) {    
        // init board 
        vector<string> board(n, string(n, '.'));
        backtrack(board, 0);
        return res;
    }

    void backtrack(vector<string>& board, int i){
        // drawback condition
        if(i == board.size()){
            res.push_back(board);
            return;
        }
        // make decision
        for(int j=0; j < board.size(); ++j){
            if(!isVaild(board, i, j))
                continue;
            board[i][j] = 'Q';
            // move to next level of decision
            backtrack(board, i+1);
            // drawback
            board[i][j] = '.';
        }
    }

    bool isVaild(const vector<string>& board, int i , int j){
        for(int k=0; k<i; ++k){
            // rule 1
            if(board[k][j] == 'Q')
                return false;
            
            // rule 2
            // i + j = const.
            // k + x = i + j -> x = i + j - k
            if(i+j-k < board.size()){
                if(board[k][i+j-k] == 'Q')
                    return false;
            }

            //rule 3
            // i - j = const.
            // k - x = i - j -> x = k - (i - j)
            if(k-i+j >= 0){
                if(board[k][k-i+j] == 'Q')
                    return false;
            }
        }
        return true;
    }
};