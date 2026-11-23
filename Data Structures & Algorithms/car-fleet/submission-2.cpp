class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // Equation: v1*((p2-p1)/(v1-v2))  car 1 is faster car 2 is farther
        int numFleets = 0; 

        vector<pair<int,int>> cars(position.size());
        for (int i = 0; i < position.size(); ++i) {
            cars[i] = {position[i], speed[i]};
        }
        sort(cars.begin(), cars.end());

        float mostLateArrival = 0;
        for (int i = cars.size()-1; i >= 0; --i) {
            float currentArrival = (double)(target-cars[i].first)/cars[i].second;

            if (currentArrival > mostLateArrival) {
                mostLateArrival = currentArrival;
                ++numFleets;
            };
        }

        return numFleets;
    }
};
