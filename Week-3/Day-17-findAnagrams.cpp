class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        map<char, int> mp, ms;
        for(char c : p) {
            mp[c]++;
        }
        for(int i=0; i<p.size(); i++) {
            ms[s[i]]++;
        }
        
        if(mp == ms)    res.push_back(0);
        for(int i=p.size(); i<s.size(); i++) {
            ms[s[i-p.size()]]--;
            if(ms[s[i-p.size()]] == 0)  ms.erase(s[i-p.size()]);
            ms[s[i]]++;
            if(mp == ms)    res.push_back(i-p.size()+1);
        }
        return res;
    }
};
