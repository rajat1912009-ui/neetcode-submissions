class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX;
        int profit = 0;

        for(int price : prices) {
            min_price = std::min(min_price, price);

            int profitday = price - min_price;
            profit = std::max(profitday, profit);
        }

        return profit;
    }
};
