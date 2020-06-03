// https://leetcode-cn.com/problems/pascals-triangle-ii/
class Solution {
public:
	// 0ms,6.6MB
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> ret;
        vector<int> line(rowIndex+1,1);
        for(int i = 0; i <= rowIndex ; i++){
            auto t = 1;
            for(int j = 1 ; j < i ; j++){ 
                auto temp = line[j];
                line[j] = t + line[j];
                t = temp;
            }
            ret.push_back(vector<int>(line.begin(),line.begin()+i+1));
        }
        return ret.back();
    }
};