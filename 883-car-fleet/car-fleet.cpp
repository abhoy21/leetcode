class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>>pairs; //initial position , time remaining pairs.
        for(int i = 0; i < speed.size(); i++)
        {
            pairs.push_back({position[i], (double)(target - position[i]) / speed[i]});
        }

        sort(pairs.begin(), pairs.end(), [](pair<int, double>&a, pair<int, double>&b){
            return a.first > b.first;
        });

        int fleet = 1;
        double time = pairs[0].second;

        for(int i = 1; i < speed.size(); i++)
        {
            if(pairs[i].second > time)
            {
                fleet++;
                time = pairs[i].second;
            }
        }

        return fleet;
    }
};