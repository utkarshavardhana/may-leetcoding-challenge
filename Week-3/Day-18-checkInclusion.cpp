class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size())   return false;
        vector<int> m1(26, 0), m2(26, 0);
        for(char c : s1)    m1[c-'a']++;
        for(int i=0; i<s1.size(); i++) m2[s2[i]-'a']++;
        if(m2 == m1)    return true;
        for(int i=s1.size(); i<s2.size(); i++) {
            m2[s2[i-s1.size()]-'a']--;
            m2[s2[i]-'a']++;
            if(m2 == m1)    return true;
        }
        return false;
    }
};
