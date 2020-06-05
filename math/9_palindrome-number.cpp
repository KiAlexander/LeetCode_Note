// https://leetcode-cn.com/problems/palindrome-number/
class Solution {
public:
	// 16ms,6.1MB
    bool isPalindrome(int x) {
        if(x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        int revertedNumber = 0;
        while(x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }

        return x == revertedNumber || x == revertedNumber/10;
    }

    // 12ms,6MB
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        if(x==INT_MAX)
            return false;
        int tempx=x,newx=0;
        while(x)
        {
            newx=newx*10+x%10;
            x/=10;
        }
        return newx==tempx;
    }
};
