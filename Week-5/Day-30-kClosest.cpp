class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> res;
        map<double, vector<vector<int>>> m;
        for(vector<int> v : points) {
            m[pow(v[0], 2) + pow(v[1], 2)].push_back(v);
        }
        for(auto it=m.begin(); it!=m.end(); it++) {
            vector<vector<int>> v = (*it).second;
            for(vector<int> vec : v) {
                if(K--) res.push_back(vec);
                else
                    return res;
            }
        }
        return res;
    }
};
