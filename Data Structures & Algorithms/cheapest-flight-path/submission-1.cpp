class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<int> prices(n+1,INT_MAX);
        prices[src] = 0;//起始

        for(int i=0;i<=k;i++){
            vector<int> tempPrices = prices;
            for(auto& flight:flights){
                int d1 = flight[0],d2 = flight[1];
                int dist = flight[2];

                if(prices[d1]==INT_MAX) continue;
                if(prices[d1]+dist<tempPrices[d2]){
                    tempPrices[d2] = prices[d1]+dist;
                }
            }
            prices = tempPrices;
        }
        return prices[dst]==INT_MAX?-1:prices[dst];
    }
};
