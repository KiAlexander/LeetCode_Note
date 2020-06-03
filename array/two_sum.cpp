class Solution {
public:
	// 1.暴力法，
	// 	遍历x，查找target-x
	// 时间复杂度O(n2),空间复杂度O(n2)
	// 524ms,7MB
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for(int i=0;i<nums.size()-1;i++)
        {
            int target_adder = target - nums[i];
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[j]==target_adder)
                {
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
        return result;
    }

    // 2.两遍哈希表
    //  将每个元素的值和它的索引添加到表中;检查每个元素所对应的目标元素（target - nums[i]target−nums[i]）
    // 是否存在于表中,并且不是num[i]其自身
    // 时间复杂度O(n),空间复杂度O(n)
    // 12ms,8.3MB 
    vector<int> twoSum2(vector<int>& nums, int target) {
        unordered_map<int, int> my_map;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            my_map[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++) {
	        auto iter = my_map.find(target-nums[i]);
	        if (iter != my_map.end() && iter->second > i) {
	            result.push_back(i);
	            result.push_back(iter->second);
	            break;
        }
    }
    	return result;
    }


    // 3.一遍哈希表
    //  将元素插入到表中的同时，检查表中是否已经存在当前元素所对应的目标元素
    // 时间复杂度O(n),空间复杂度O(n)
    // 12ms,8.1MB 
    vector<int> twoSum3(vector<int>& nums, int target) {
        unordered_map<int, int> my_map;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            auto iter = my_map.find(target - nums[i]);
            if(iter != my_map.end()){
	            result.push_back(iter->second);
                result.push_back(i);
                return result;
            }
            my_map[nums[i]] = i;
        }
        return result;
    }


};
