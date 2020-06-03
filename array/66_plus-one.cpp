https://leetcode-cn.com/problems/plus-one
class Solution {
public:
    // 0ms,6.5MB
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        for(int i = size - 1; i >= 0; --i){
            if(digits[i] < 9){
                ++digits[i];
                return digits;
            }
            if(i == 0){
                digits[i] = 1;
                digits.push_back(0);
            }
            else
                digits[i] = 0;
        }
        return digits;  
    }
};