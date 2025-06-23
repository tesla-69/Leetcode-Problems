class Solution {
public:
    int titleToNumber(string c) {
        int n=c.size();
        int k;
         int num=0;
        int j=n-1;
       
        for(int i=0;i<n;i++){
         num=num+(c[i]-64)*pow(26,j);
         j--;
        }
        return num;
    }
};