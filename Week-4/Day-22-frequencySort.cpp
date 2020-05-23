class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        for(char c : s) m[c]++;
        map<int, vector<char>, greater<int>> ma;
        for(auto it=m.begin(); it!=m.end(); it++) {
            ma[(*it).second].push_back((*it).first);
        }
        string res;
        for(auto it=ma.begin(); it!=ma.end(); it++) {
            for(char c : (*it).second) {
                res += string((*it).first, c);
            }
        }
        return res;
    }
};
