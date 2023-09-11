class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        
        int total_gas = 0;
        int current_gas = 0;
        int start_station = 0;
        
        for (int i = 0; i < n; i++) {
            total_gas += gas[i] - cost[i];
            current_gas += gas[i] - cost[i];
            
            // If we can't reach the next station with the current gas,
            // update the starting station to the next station.
            if (current_gas < 0) {
                start_station = i + 1;
                current_gas = 0;
            }
        }
        
        // If the total gas is negative, it means we can't complete the circuit.
        // Otherwise, return the starting station index.
        return (total_gas >= 0) ? start_station : -1;
    }
};
