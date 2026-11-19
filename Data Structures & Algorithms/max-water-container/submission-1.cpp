class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size()-1;
        int area = 0;

        while (l < r) {
            int hL = heights[l], rL = heights[r];
            int mH = min(hL, rL);
            area = (mH*(r-l) > area) ? mH*(r-l) : area;
            
            if (hL <= rL) {
                ++l;
            }
            else {
                --r;
            }
        }

        return area;
    }
};
