class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ans = 0;
        for(int i : nums)   ans ^= i;
        return ans;
    }
};
