class Solution {
   public:
    int totalFruit(vector<int>& fruits) {
      // your code goes here
      int n = fruits.size();
      map<int, int>mp;
      int i = 0; 
      int j = 0;
      int maxi = 0;
      while(j < n) {
        mp[fruits[j]]++;
        if(mp.size() > 2) {
          mp[fruits[i]]--;
          if(mp[fruits[i]] == 0) mp.erase(fruits[i]);
          i++;
        }
        maxi = max(maxi, j-i+1);
        j++;
      }
      return maxi;

    }
};