class Solution {
public:
    // 把边界的'O'变成‘1’，然后遍历，遇见‘1’恢复成‘O’，其余都变成'X'
    void solve(vector<vector<char>>& board) {
         if(board.size()==0) return;
    
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++)//左右边界
        {
            dfs(board,i,0);
            dfs(board,i,n-1);
        }
        for(int j=1;j<n-1;j++)//上下边界
        {
            dfs(board,0,j);
            dfs(board,m-1,j);
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='1') board[i][j]='O';//边界恢复成‘O’
                else
                {
                    board[i][j]='X';//其余全为'X'
                }
            }
        }

    }

    void dfs(vector<vector<char>>& board,int i,int j)//把边界的‘O’变成'1’
    {
        if(i>=0&&j>=0&&i<board.size()&&j<board[0].size()&&board[i][j]=='O') 
        {
            board[i][j]='1';
            dfs(board,i+1,j);
            dfs(board,i-1,j);
            dfs(board,i,j+1);
            dfs(board,i,j-1);
        }
    }
};