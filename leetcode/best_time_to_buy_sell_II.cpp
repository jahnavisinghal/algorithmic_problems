ass Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(!prices.size()) {
            return 0;
        }
        bool buy = true;
        int prev, i = 0, sell, profit = 0;
        while(i<prices.size()) {
            if(buy) {
                prev = prices[i++];
                //cout << "\nprev: " << prev;
                while(prices[i] < prev) {
                    prev = prices[i++];
                }
                //cout << "\nbuying at " << prev;
                buy = false;
            } else {
                sell = prices[i++];
                while(i < prices.size() && prices[i] > sell) {
                    sell = prices[i++];
                }
                //cout << "\nselling at " << sell;
                profit += (sell-prev);
                buy = true;
            }
        }
        return profit;
    }
};
