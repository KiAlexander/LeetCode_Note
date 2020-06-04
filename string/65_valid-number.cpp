// https://leetcode-cn.com/problems/valid-number/
class Solution {
public:
	// 分了三步来处理。第一步trim，即去除头尾的空格；
	// 第二步划分，找出字符e划分为底数和指数两部分；
	// 第三部判断底数和指数是否有效，若没有指数则指判断底数，
	// 显然指数只能包含符号和整数、而底数只能包含符号、小数点和数字。 
	// 0ms,6.1MB
	bool isNumber(string s) {
        int len = 0;//去除首尾空格
        for(int i = s.size() - 1; i >= 0; i--)
        {
            if(s[i] == ' ') len++;
            else break;
        }
        s = s.substr(0, s.size() - len);
        len = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == ' ') len++;
            else break;
        }
        s = s.substr(len);
        if(s.size() == 0) return false;
        
        int id = s.find('e');//划分为底数和指数
        if(id == string::npos) return judgeP(s);//判断底数
        else return judgeP(s.substr(0, id)) && judgeS(s.substr(id + 1));//判断指数
    }
    bool judgeP(string s)
    {
        bool res = false; 
        bool pointed = false;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '+' || s[i] == '-')
            {
                if(i != 0) return false;
            }
            else if(s[i] == '.')
            {
                if(pointed) return false;
                pointed = true;
            }
            else if(s[i] < '0' || s[i] > '9') return false;
            else res = true;
        }
        return res;
    }
    
    bool judgeS(string s)
    {
        bool res = false;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '-' || s[i] == '+')
            {
                if(i != 0) return false;
            }
            else if(s[i] < '0' || s[i] > '9') return false;
            else res = true;
        }
        return res;
    }
};