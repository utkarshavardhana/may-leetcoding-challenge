class Solution {
public:
    double getSlope(vector<int> &p1, vector<int> &p2) {
        double y = (p2[1] - p1[1]);
        if(y == 0) return DBL_MAX;
        return abs((p2[0] - p1[0])/y);
    }
    
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        double slope = getSlope(coordinates[0], coordinates[1]);
        for(int i = 2; i < coordinates.size(); i++) {
            double newSlope = getSlope(coordinates[i - 1], coordinates[i]);
            if(newSlope != slope) return false;
        }
        return true;
    }
};
