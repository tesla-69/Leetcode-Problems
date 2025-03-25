class Solution {
public:

    bool checkHorizontal(int n, vector<vector<int>> &arr) {
        sort(arr.begin(), arr.end(), [](vector<int>&a, vector<int>&b){
            return a[0] < b[0];
        });
        int sx = arr[0][0] , ex = arr[0][2];
        int cut = 0;
        for(int i = 1; i<arr.size(); i++) {
            sx = arr[i][0];
            if(arr[i][0] < ex) {
                if(arr[i][2] > ex) ex = arr[i][2];
            }
            else {
                cut++;
                ex = arr[i][2];
            }
        }
        if(cut >=2) return true;
        else return false;
    }
    bool checkVertical(int n, vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end(), [](vector<int>&a, vector<int>&b){
            return a[1] < b[1];
        });
        int sy = arr[0][1] , ey = arr[0][3];
        int cut = 0;
        for(int i = 1; i<arr.size(); i++) {
            sy = arr[i][1];
            if(arr[i][1] < ey) {
                if(arr[i][3] > ey) ey = arr[i][3];
            }
            else {
                cut++;
                ey = arr[i][3];
            }
        }
        if(cut >=2) return true;
        else return false;
    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        return checkHorizontal(n, rectangles) || checkVertical(n, rectangles);
    }
};