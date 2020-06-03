// https://leetcode-cn.com/problems/maximal-rectangle/
class Solution {
public:
	// 28ms,9.4MB
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n(matrix.size());
        if(n==0)return 0;
        int m(matrix[0].size());
        vector<int> height(m+1,0);//每一层的高度通过当前元素进行判定,计算面积需要，最后一个元素补0
        int area(0);
        for(int i = 0;i<n;i++){
            stack<int> S;
            for(int j = 0;j<m+1;j++){
                //这里要判断一下当前高度
                if(j<m){
                    if(matrix[i][j]=='1')
                        height[j] +=1;
                    else
                        height[j] = 0;
                }
                while(!S.empty()&&height[j]<height[S.top()]){
                    int curheight = S.top();
                    S.pop();
                    //如果栈顶元素为空，则令栈顶元素为0
                    area = max(area,height[curheight]*(!S.empty()?(j-S.top()-1):j));
                }
                S.push(j);
            }
        }
        return area;
    }
};