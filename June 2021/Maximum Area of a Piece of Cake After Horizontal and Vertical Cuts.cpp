class Solution {
public:
    int maxArea(int h, int w, vector<int>& hCuts, vector<int>& wCuts) {
        int nh = hCuts.size();
        int nw = wCuts.size();
        sort(hCuts.begin(), hCuts.end());
        sort(wCuts.begin(), wCuts.end());
        int ht = hCuts[0], wd = wCuts[0];
        for(int i = 1; i < nh; i++)
            ht = max(ht, hCuts[i] - hCuts[i-1]);
        ht = max(ht, h - hCuts[nh - 1]);
        for(int i = 1; i < nw; i++)
            wd = max(wd, wCuts[i] - wCuts[i-1]);
        wd = max(wd, w - wCuts[nw - 1]);
        long long int ans = (long long)(ht) * (long long)(wd) % 1000000007;
        return ans;
    }
};
