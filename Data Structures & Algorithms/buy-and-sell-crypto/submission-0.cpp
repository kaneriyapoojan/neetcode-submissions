class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int profit = 0;
        int buy = 0;
        int sell = 1;

        while(sell<prices.size()){
            if(prices[sell] > prices[buy]){
                profit = max((prices[sell] - prices[buy]),profit);
                sell++;

            }else{
                buy = sell;
                sell++;
            }
        }
        return profit;
    }
};
