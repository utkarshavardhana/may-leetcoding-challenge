class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> m;
        int maxLen = 0;
        int countOne = 0;
        m[0] = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i]) ++countOne;
            int moreOne = 2 * countOne - (i + 1);
            auto it = m.find(moreOne);
            if (it == m.end()) m[moreOne] = i;
            else maxLen = max(maxLen, i - it->second);
        }
        return maxLen;
    }
};
