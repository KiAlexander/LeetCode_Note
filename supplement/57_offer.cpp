class Solution {
public:
    // 计算出递增序列的最大长度t( <sqrt(2*target) )
    // 枚举所有可能的长度 len ∈ [2, t]
    // 因为等差和公式是 target = ( 首项+末项 ) * len / 2 , 所以(target*2) mod len == 0 是当前len有效的必要条件，所以过滤掉（target*2）%len!=0的len 是第一个减枝
    // 已知 公差为1的等差数列长度为len, 和为target, 根据求和公式可以计算出 tmp = 首项*2 = [ (2*target) / len - (len - 1)] , 因此，可以先计算出tmp，如果 tmp%2!=0的话，那么len一定不合法，这是第二个减枝.
    // 计算得到首项以后，就可以遍历得出当前能够组成的序列了，然后同理继续遍历下去.
    vector<vector<int>> findContinuousSequence(int target) {
        int t = sqrt(target*2)+1;
        vector<vector<int>> res;
        for( int len=t; len>=2; --len ){
            if ( (target*2)%len==0 ){ //第一个减枝
                int tmp = target*2/len - len + 1;
                if (tmp>0 && tmp%2==0){ // 第二个减枝
                    int a = tmp/2;  // a为首项
                    vector<int> cur;
                    for( int i=0; i<len; ++i ){
                        cur.push_back(i+a);
                    }
                    res.push_back(cur);
                }
            }
        }
        return res;
    }
};