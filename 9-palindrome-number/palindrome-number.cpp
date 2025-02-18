class Solution {
public:
    bool isPalindrome(int x) {
       if(x<0) return false;
       else {
           int n=x;
            long rev=0;
            while(x){
            int temp=x%10;
            rev = rev*10 + temp;
            x=x/10;
            }   
            if(rev==n) return true;
            else return false;
       } 
       return false;
    }
};