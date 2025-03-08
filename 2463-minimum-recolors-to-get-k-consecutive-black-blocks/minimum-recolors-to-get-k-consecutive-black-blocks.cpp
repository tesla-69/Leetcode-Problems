class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int i = 0;
        int j = 0;
        // string s = blocks;
        int n = blocks.size();
        int wc = 0 , bc = 0;
        while(j < k) {
            if(blocks[j] == 'W') wc++;
            else bc++;
            j++;
        }
        int cnt = n;
        cnt = min(cnt,wc);
        // cout<<cnt<<" ";
        i++;
        while(j < n) {
           if(blocks[i-1] == 'W') wc--;
           if(blocks[j] == 'W') wc++;
           cnt = min(cnt,wc);
        //    cout<<cnt<<" ";
           i++;
           j++; 
        }
        return cnt;
    }
};