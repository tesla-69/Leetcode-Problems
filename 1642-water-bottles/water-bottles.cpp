class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int total = numBottles;
        while(numBottles>=numExchange){
            int temp = numBottles/numExchange;
            total += temp;
            numBottles %= numExchange;
            numBottles+=temp;
        }
        return total;
    }
};