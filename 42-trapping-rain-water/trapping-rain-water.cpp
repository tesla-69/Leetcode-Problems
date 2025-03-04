class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        // vector<int> lmax(n,0),rmax(n,0);
        // lmax[0] = max(0,height[0]);
        // rmax[n-1] = max(0,height[n-1]);
        // for(int i = 1; i<n; i++) {
        //     lmax[i] = max(height[i], lmax[i-1]);
        // }
        // for(int i = n-2; i>=0; i--) rmax[i] = max(height[i] , rmax[i+1]);
        int total = 0;
        int l = 0 , r = n-1;
        int lmax = INT_MIN, rmax = INT_MIN;
        while(l < r) {
            if(height[l] <= height[r]) {
                if(lmax > height[l]) total += lmax - height[l];
                lmax = max(lmax, height[l]);
                l++;
            }
            else {
                if(rmax > height[r]) total += rmax - height[r];
                rmax = max(rmax, height[r]);
                r--;
            }
        }
        // for(int i =0; i<n; i++) {
        //     int l = lmax[i] , r = rmax[i];
        //     if(height[i] < l && height[i] < r) {
        //         total += min(l,r) - height[i];
        //     }
        // }
        return total;
    }
};