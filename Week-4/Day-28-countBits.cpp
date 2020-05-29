class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num+1, 0);
        for(int i=1; i<=num; i++) {
            res[i] = __builtin_popcount(i);
        }
        return res;
    }
};
