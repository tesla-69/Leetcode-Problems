class Solution {
private:
    vector<int> segTree;
    int n;
    void buildTree(int i, int l, int r, vector<int>& arr) {
        if (l == r) {
            segTree[i] = l;
            return;
        }
        int mid = l + (r - l) / 2;
        buildTree(2 * i + 1, l, mid, arr);
        buildTree(2 * i + 2, mid + 1, r, arr);
        int lind = segTree[2 * i + 1];
        int rind = segTree[2 * i + 2];
        if (arr[lind] >= arr[rind])
            segTree[i] = lind;
        else
            segTree[i] = rind;
    }
    int solveQ(int i, int l, int r, int start, int end, vector<int>& arr) {
        if (l > end || r < start)
            return -1;
        if (l >= start && r <= end)
            return segTree[i];
        int mid = l + (r - l) / 2;
        int lind = solveQ(2 * i + 1, l, mid, start, end, arr);
        int rind = solveQ(2 * i + 2, mid + 1, r, start, end, arr);
        if (lind == -1)
            return rind;
        if (rind == -1)
            return lind;
        if (arr[lind] >= arr[rind])
            return lind;
        else
            return rind;
    }

public:
    vector<int> leftmostBuildingQueries(vector<int>& heights,
                                        vector<vector<int>>& queries) {
        n = heights.size();
        segTree = vector<int>(4 * n);
        buildTree(0, 0, n - 1, heights);
        int q = queries.size();
        vector<int> ans(q);
        for (int i = 0; i < q; i++) {
            int mxInd = max(queries[i][1], queries[i][0]);
            int mnInd = min(queries[i][1], queries[i][0]);
            if (mxInd == mnInd)
                ans[i] = mxInd;
            else if (heights[mxInd] > heights[mnInd])
                ans[i] = mxInd;
            else {
                int s = mxInd + 1;
                int e = n - 1;
                int result = INT_MAX;
                while(s <= e) {
                    int mid = s + (e - s) / 2;
                    int ind = solveQ(0,0,n-1,s,mid,heights);
                    if(heights[ind] > max(heights[mnInd], heights[mxInd])){
                        result = min(result, ind);
                        e = mid - 1;
                    }
                    else s = mid + 1;
                }
                if(result == INT_MAX) result = -1;
                ans[i] = result;
            }
        }
        return ans;
    }
};