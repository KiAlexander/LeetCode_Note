class Solution {
public:
    int jump(vector<int>& nums) {
        /*
        执行用时 : 16 ms, 击败了95.83% 的用户
        内存消耗 : 10 MB, 击败了87.87% 的用户
        Dijkstra算法的变形——将第一步第二步...第N步可以到达的节点依
        次放入map_arrive中。或者说是对图执行广度优先遍历（图的广度
        优先遍历可以找到某节点到所有节点最少步数，图的深度优先遍历可以
        找到无环图的拓扑结构）
        将第一步到达的节点放到map_arrive中
        如果目的节点不在map_arrive中，试图从map_arrive再往前走一步
        将可以到达的节点再次放入到map_arrive中。一直如此执行下去。
        */
        int steps = 0;
        int start = 0;
        int end = 0;
        while (end < nums.size()-1) {
            int max = end;
            for (int i = start; i <= end; i++) {
                if (nums[i]+i > max) {
                    max = nums[i]+i;
                } 
            }
            start = end+1;
            end = max;
            steps++;
        }
        return steps;
    }
};