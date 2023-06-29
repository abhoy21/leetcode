class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int j = 0;
        for(int i = 0; i < heights.size()-1; i++)
        {
            for(int j = i+1; j < heights.size(); j++)
            {
                if(heights[j] > heights[i])
                {
                    int tempo = heights[i];
                    heights[i] = heights[j];
                    heights[j] = tempo;
                    
                    string temp = names[i];
                    names[i] = names[j];
                    names[j] = temp;
                }
            }

        }
        
        return names;
    }
};