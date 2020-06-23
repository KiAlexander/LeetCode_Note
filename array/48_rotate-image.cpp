// https://leetcode-cn.com/problems/rotate-image/
class Solution {
public:
	// 最直白蛮力的方法，先转置后镜像对称
	// 0ms,7.2MB
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n / 2; i++) matrix[i].swap(matrix[n - 1 - i]);
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};