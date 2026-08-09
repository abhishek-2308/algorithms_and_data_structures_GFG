class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(), prices.end(), [](int &a, int &b){
            return a > b;
        });
        sort(discounts.begin(), discounts.end(), [](int &a, int &b){
            return a > b;
        });
         int size= min((int)prices.size(), (int)discounts.size());
        double answer= 0.0;
        for(int i=0; i<size; i++){
            answer= answer+ (double)prices[i] *(100 -  discounts[i])/100.0;
        }
        for(int i= size; i<prices.size(); i++){
            answer= answer+ prices[i];
        }
        return answer;
        
    }
};