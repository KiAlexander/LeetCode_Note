// https://leetcode-cn.com/problems/subarray-sums-divisible-by-k/
class Solution {
public:
	 // 将所有数变成K对应的余数
		// 处理方式：正数就为余数  负数就为 (余数 + K) % K
		// 通用方式: (num % K + K) % K 【不用区分正负数】
	// 92ms,28.7MB
    int subarraysDivByK(vector<int>& A, int K) {
	  	unordered_map<int,int> m;
	    m[0]=1;
	    int sum=0;
	    int res=0;
	    for(int i=0;i<A.size();i++){
	        sum=((A[i]+sum)%K+K)%K;
	        res+=m[sum];
	        m[sum]++;
	    }
	    return res;
	}
};