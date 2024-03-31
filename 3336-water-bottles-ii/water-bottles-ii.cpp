class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int empty = 0, drink = 0;

        while(numBottles > 0 || empty >= numExchange){
            if(empty >= numExchange){
                empty -= numExchange;
                numExchange++;
                numBottles++;
            }
            drink += numBottles;
            empty += numBottles;
            numBottles = 0;
        }

        return drink;
    }
};