// https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/
class Solution {
public:
    int vis[101][101]={0};
    int movingCount(int m, int n, int k) {
        return dfs(0,0,m,n,k);
    }
    int dfs(int x,int y,int m,int n,int k){
        if(x<0||y<0||x>=m||y>=n||vis[x][y]||sum(x,y)>k) return 0;
        vis[x][y]=1;
        return dfs(x-1,y,m,n,k)+dfs(x,y-1,m,n,k)+dfs(x+1,y,m,n,k)+dfs(x,y+1,m,n,k)+1;
    }
    int sum(int x,int y){
        int res=0;
        while(x){
            res+=x%10;
            x/=10;
        }
        while(y){
            res+=y%10;
            y/=10;
        }
        return res;
    }
};