// https://leetcode-cn.com/problems/count-and-say/
class Solution {
public:
	// 4ms,7MB
    char ch[3]={'1','2','3'};
    string countAndSay(int n) {
        if(n>1)
        {
        string s=countAndSay(n-1);
        string temp;
        for(int j=0;j<s.size();j++)
            {
                int count=0;
                while(s[j]==s[j+1])
                {
                    count++;
                    j++;
                }
                temp+=ch[count];
                temp+=s[j];
            }
        return temp;    
        }
        else return "1";
    }
};