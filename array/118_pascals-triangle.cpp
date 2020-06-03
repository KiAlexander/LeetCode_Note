https://leetcode-cn.com/problems/pascals-triangle/
class Solution {
public:
	// 0ms,6.7MB
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        vector<int> line(numRows,1);
        for(int i = 0; i < numRows ; i++){
            auto t = 1;
            for(int j = 1 ; j < i ; j++){ 
                auto temp = line[j];
                line[j] = t + line[j];
                t = temp;
            }
            ret.push_back(vector<int>(line.begin(),line.begin()+i+1));
        }
        return ret;
    }
};