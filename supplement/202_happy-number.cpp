class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> record;

        while(n != 1){
            if(record.find(n) != record.end())
                return false;
            record.insert(n);
            n = get_num(n);
        }
        return true;
    }

    int get_num(int n){
        int res = 0;
        
        while(n){
            int true_num = n % 10;
            res += true_num * true_num;
            n /= 10;
        }

        return res;
    }
};