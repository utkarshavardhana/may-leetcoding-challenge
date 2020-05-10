class Solution {
public:
    bool isPerfectSquare(int num) {
        long long lo = 1, hi = num, mid = 0;
        while(lo <= hi) {
            if(lo == hi)    return (lo*lo == num);
            mid = lo + (hi-lo) / 2;
            if(mid*mid == num)  return true;
            if(mid*mid < num)   lo = mid+1;
            else    hi = mid;
        }
        return false;
    }
};
