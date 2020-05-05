class Solution {
public:
    int findComplement(int num) {
        return num ^ (int)(pow(2, 32 - __builtin_clz(num)) - 1);
    }
};
