class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> s;
        for(char c : J) {
            s.insert(c);
        }
        int count = 0;
        for(char c : S) {
            if(s.count(c))  count++;
        }
        return count;
    }
};
