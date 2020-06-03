// https://leetcode-cn.com/problems/majority-element/
class Solution {
public:
	// 1、利用哈希数组 时间复杂度：O(N) 空间复杂度：O(N)
    int majorityElement(vector<int>& nums) {
        //建立哈希数组找其中出现次数大于n/2的数
        unordered_map<int,int> hash;
        int res=0;
        int len=nums.size();
        for(int i=0;i<len;i++){
            hash[nums[i]]++;
          if(hash[nums[i]]>len/2){
                res=nums[i];
                break;//优化一下
            }    
        }
        return res;
    }

	// 2、摩尔投票法 时间复杂度O(N) 空间复杂度O(1)
    int majorityElement(vector<int>& nums) {
	//摩尔投票法,先假设第一个数过半数并设cnt=1；遍历后面的数如果相同则cnt+1，不同则减一，当cnt为0时则更换新的数字为候选数（成立前提：有出现次数大于n/2的数存在）
        int res=0,cnt=0;
        for(int i=0;i<nums.size();i++){
            if(cnt==0) {
                res=nums[i];
                cnt++;
            }
            else{
                res==nums[i]?cnt++:cnt--;
            }
        }
        return res;
    }



	// 3、位运算法 时间复杂度：O(32*N)~O(N) 空间复杂度：O(1)
    int majorityElement(vector<int>& nums) {
	//位运算法,统计每个数字每一位0，1出现的次数，如果某一位1出现的次数多则该位为1，0同理；
	//最后按为统计出来的数就是众数
        int res=0,len = nums.size();
        for(int i=0;i<32;i++){
            int ones=0,zero=0;
            for(int j=0;j < len; j++){
                if(ones>len/2 ||zero>len/2) break;
                if((nums[j]&(1<<i)) != 0) ones++;
                else zero++;   
            }
            if(ones > zero)
                 res = res|(1<<i);
        }
        return res;
    }
};