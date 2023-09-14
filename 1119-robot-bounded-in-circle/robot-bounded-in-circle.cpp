class Solution {
public:
    bool isRobotBounded(string instructions) {
        char curr_dir = 'N';
        int x = 0, y = 0;
        for(int i = 0; i < instructions.length(); i++)
        {
            if(instructions[i] == 'G')
            {
                y += curr_dir == 'N' ? 1 : 0;
                y += curr_dir == 'S' ? -1 : 0;
                x += curr_dir == 'E' ? 1 : 0;
                x += curr_dir == 'W' ? -1 : 0;
            }

            else{
                char direction = instructions[i];

                if(curr_dir == 'N')
                {
                    curr_dir = direction == 'L' ? 'W' : 'E';
                }
                else if(curr_dir == 'W')
                {
                    curr_dir = direction == 'L' ? 'S' : 'N';
                }
                else if(curr_dir == 'S')
                {
                    curr_dir = direction == 'L' ? 'E' : 'W';
                }
                else
                {
                    curr_dir = direction == 'L' ? 'N' : 'S';
                }
            }
        }

        return ((x == 0 && y == 0) || curr_dir!='N');
    }
};