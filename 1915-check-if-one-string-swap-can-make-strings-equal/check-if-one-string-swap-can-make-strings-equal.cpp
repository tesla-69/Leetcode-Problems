class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.length();
        int cnt = 0;
        int a , b;
        for(int i=0;i<n;i++){
            if(s1[i] != s2[i]) {
                cnt++;
                if(cnt == 1) a = i;
                if(cnt == 2) b = i;
                if(cnt == 3) return false;
            }
        }
        if(cnt == 0) return true;
        if(cnt == 1) return false;
        cout<<a<<" "<<b<<endl;
        swap(s1[a],s1[b]);
        cout<<s1<<" "<<s2;
        if(s1 == s2)
        return true;
        else return false;
    }
};