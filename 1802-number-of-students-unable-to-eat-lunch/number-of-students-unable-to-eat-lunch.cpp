class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> stud;
        stack<int> sand;

        for(auto it: students)
            stud.push(it);
        
        for(int i = sandwiches.size()-1; i >= 0; i--)
            sand.push(sandwiches[i]);

        
        int repeat = 0;
        while(!sand.empty() && repeat < stud.size()){
            if(sand.top() == stud.front()){
                stud.pop();
                sand.pop();
                repeat = 0;
            }
            else{
                int temp = stud.front();
                stud.pop();
                stud.push(temp);
                repeat++;
            }
        }

        return stud.size();
    }
};