class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        int n = searchWord.length(), st = 0, j = 0;
        int m = products.size();
        vector<vector<string>> ans(n);
        sort(products.begin(), products.end());
        string temp = "";
        for(int i = 0; i < n; i++){
            temp += searchWord[i];
            j = st;
            while(j < m && products[j].substr(0, i+1) != temp)
                j++;
            st = j;
            while(j < m && j < st + 3 && products[j].substr(0, i+1) == temp){
                ans[i].push_back(products[j]);
                j++;
            }
        }
        return ans;
    }
};
