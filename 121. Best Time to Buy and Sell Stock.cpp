/* ******************************************************************** *
 *          Annie Wang 2016.11.22                                       *
 * Idea: profit is calculated by the local minimum price substracted    *
 *      from the highest price after it.                                *
 *      => went through the vector, each time met a new low price,      *
 *          the buy price and reset the sell price;                     *
 *        when met a new high price, renew the sell price and re-calc   *
 *        the profit                                                    *
 * Remark: N/A                                                          *
 * ******************************************************************** *
 */

 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len < 2) return 0;
        int buy = prices[0];
        int sell = 0;
        int profit = 0;
        for(int i = 1; i < len; i++){
            if(prices[i] < prices[i-1] && prices[i] < buy){
                buy = prices[i];
                sell = 0;
            }
            else if(prices[i] > prices[i - 1] && prices[i] > sell){
                sell = prices[i];
                profit = max(profit, sell - buy);
            }
        }
        return profit;
        
    }
};
