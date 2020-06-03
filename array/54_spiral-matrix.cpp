// https://leetcode-cn.com/problems/spiral-matrix/
class Solution {
public:
	// 首先设定上下左右边界
	// 其次向右移动到最右，此时第一行因为已经使用过了，可以将其从图中删去，体现在代码中就是重新定义上边界
	// 判断若重新定义后，上下边界交错，表明螺旋矩阵遍历结束，跳出循环，返回答案
	// 若上下边界不交错，则遍历还未结束，接着向下向左向上移动，操作过程与第一，二步同理
	// 不断循环以上步骤，直到某两条边界交错，跳出循环，返回答案

	// 1
	// 0ms,6.6MB
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty()) return result;//若数组为空，直接返回答案

        spiralInternal(matrix, 0, 0, matrix[0].size(), matrix.size(), result);
        return result;
    }

    void spiralInternal(vector<vector<int>>& matrix, int si, int sj, int width, int height, vector<int>& result) {
        if (width <= 0 || height <= 0) return;

        for (int j = sj; j < sj + width; ++j) {
            result.push_back(matrix[si][j]);
        }
        for (int i = si + 1; i < si + height - 1; ++i) {
            result.push_back(matrix[i][sj + width - 1]);
        }
        for (int j = sj + width - 1; j >= sj && height > 1; --j) {
            result.push_back(matrix[si + height - 1][j]);
        }
        for (int i = si + height - 2; i > si && width > 1; --i) {
            result.push_back(matrix[i][sj]);
        }
        spiralInternal(matrix, si + 1, sj + 1, width - 2, height - 2, result);
    }

    // 2
    // 0ms,6.5MB
    vector<int> spiralOrder2(vector<vector<int>>& matrix) {
        vector <int> ans;
        if(matrix.empty()) return ans; //若数组为空，直接返回答案
        int u = 0; //赋值上下左右边界
        int d = matrix.size() - 1;
        int l = 0;
        int r = matrix[0].size() - 1;
        while(true)
        {
            for(int i = l; i <= r; ++i) ans.push_back(matrix[u][i]); //向右移动直到最右
            if(++ u > d) break; //重新设定上边界，若上边界大于下边界，则遍历遍历完成，下同
            for(int i = u; i <= d; ++i) ans.push_back(matrix[i][r]); //向下
            if(-- r < l) break; //重新设定有边界
            for(int i = r; i >= l; --i) ans.push_back(matrix[d][i]); //向左
            if(-- d < u) break; //重新设定下边界
            for(int i = d; i >= u; --i) ans.push_back(matrix[i][l]); //向上
            if(++ l > r) break; //重新设定左边界
        }
        return ans;
    }
};