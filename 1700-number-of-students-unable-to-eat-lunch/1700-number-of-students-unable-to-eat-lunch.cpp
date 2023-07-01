class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        stack<int>sand;
        queue<int>stud;
        for(auto s : students)
        {
            stud.push(s);
        }
        for(int i = sandwiches.size()-1; i >= 0; i--)
        {
            sand.push(sandwiches[i]);
        }
        int repeat = 0;
        while(!sand.empty() && repeat < stud.size())
        {
            if(stud.front() == sand.top())
            {
                sand.pop();
                stud.pop();
                repeat = 0;
            }
            else
            {
                int temp = stud.front();
                stud.pop();
                stud.push(temp);
                repeat++;
                
            }
        }
        
    
        
        return stud.size();
        
    }
};