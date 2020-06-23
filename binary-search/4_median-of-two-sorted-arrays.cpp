// https://leetcode-cn.com/problems/median-of-two-sorted-arrays/
class Solution {
public:
    // 1.二分法
    // 时间复杂度为O(log (m+n))联想二分法
    // 如果某个有序数组长度是奇数，那么其中位数就是最中间那个，
    // 如果是偶数，那么就是最中间两个数字的平均值。
    // 即分别找第 (m+n+1) / 2 个，和 (m+n+2) / 2 个，然后求其平均值即可
    // 20ms,7MB
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int left = (m + n + 1) / 2;
        int right = (m + n + 2) / 2; 
        return (findKth(nums1, 0, nums2, 0, left) + findKth(nums1, 0, nums2, 0, right)) / 2.0;
    }
    //i: nums1的起始位置 j: nums2的起始位置
    int findKth(vector<int>& nums1, int i, vector<int>& nums2, int j, int k){
        if( i >= nums1.size()) return nums2[j + k - 1];//nums1为空数组
        if( j >= nums2.size()) return nums1[i + k - 1];//nums2为空数组
        if(k == 1){
            return min(nums1[i], nums2[j]); //比较起始数字
        }
        // 检查存不存在第K/2个数字，如果存在就取出来，否则就赋值上一个整型最大值。
        int midVal1 = (i + k / 2 - 1 < nums1.size()) ? nums1[i + k / 2 - 1] : INT_MAX ;
        int midVal2 = (j + k / 2 - 1 < nums2.size()) ? nums2[j + k / 2 - 1] : INT_MAX ;
        if(midVal1 < midVal2){
            return findKth(nums1, i + k / 2, nums2, j , k - k / 2);
        }else{
            return findKth(nums1, i, nums2, j + k / 2 , k - k / 2);
        }        

    }

    // 2.划分数组
    // 中位数被用来：将一个集合划分为两个长度相等的子集，其中一个子集中的元素总是大于另一个子集中的元素
    // 对 i 在 [0, m]的区间上进行二分搜索，找到最大的满足A[i−1]≤B[j] 的i值
    // 时间复杂度O(logmin(m,n)))
    // 16ms,7,1MB
    double findMedianSortedArrays1(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int m = nums1.size();
        int n = nums2.size();
        int left = 0, right = m, ansi = -1;
        // median1：前一部分的最大值
        // median2：后一部分的最小值
        int median1 = 0, median2 = 0;

        while (left <= right) {
            // 前一部分包含 nums1[0 .. i-1] 和 nums2[0 .. j-1]
            // 后一部分包含 nums1[i .. m-1] 和 nums2[j .. n-1]
            int i = (left + right) / 2;
            int j = (m + n + 1) / 2 - i;

            // nums_im1, nums_i, nums_jm1, nums_j 分别表示 nums1[i-1], nums1[i], nums2[j-1], nums2[j]
            int nums_im1 = (i == 0 ? INT_MIN : nums1[i - 1]);
            int nums_i = (i == m ? INT_MAX : nums1[i]);
            int nums_jm1 = (j == 0 ? INT_MIN : nums2[j - 1]);
            int nums_j = (j == n ? INT_MAX : nums2[j]);

            if (nums_im1 <= nums_j) {
                ansi = i;
                median1 = max(nums_im1, nums_jm1);
                median2 = min(nums_i, nums_j);
                left = i + 1;
            }
            else {
                right = i - 1;
            }
        }

        return (m + n) % 2 == 0 ? (median1 + median2) / 2.0 : median1;
    }

};