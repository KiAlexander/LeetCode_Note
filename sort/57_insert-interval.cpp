// https://leetcode-cn.com/problems/insert-interval/
class Solution {
public:
	// 24ms,10.6MB
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int i=0;
        int length = intervals.size();
        while(i < length && intervals[i][1] < newInterval[0]){
            res.push_back(intervals[i]);
            i++;
        }
        while(i< length && intervals[i][0] <= newInterval[1]){
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        res.push_back(newInterval);
        while(i< length)
            res.push_back(intervals[i++]);
        return res;
    }
};