import java.util.Stack;

class Solution {
    public int sumSubarrayMins(int[] arr) {
        int mod = (int) 1e9 + 7;
        int n = arr.length;
        long sum = 0;
        
        // Arrays to store the Previous Smaller Element (PSE) and Next Smaller Element (NSE)
        int[] pse = new int[n];
        int[] nse = new int[n];
        
        Stack<Integer> pseStack = new Stack<>();
        for (int i = 0; i < n; i++) {
            while (!pseStack.isEmpty() && arr[pseStack.peek()] > arr[i]) {
                pseStack.pop();
            }
            if (pseStack.isEmpty()) {
                pse[i] = -1;  
            } else {
                pse[i] = pseStack.peek(); 
            }
            pseStack.push(i);
        }
        
    
        Stack<Integer> nseStack = new Stack<>();
        for (int i = n - 1; i >= 0; i--) {
            while (!nseStack.isEmpty() && arr[nseStack.peek()] >= arr[i]) {
                nseStack.pop();
            }
            if (nseStack.isEmpty()) {
                nse[i] = n;  // No smaller element, so next smaller index is n
            } else {
                nse[i] = nseStack.peek();  // Next smaller element index
            }
            nseStack.push(i);
        }
        
        // Calculate the sum of the minimums for all subarrays
        for (int i = 0; i < n; i++) {
            int left = i - pse[i];  // Number of subarrays where arr[i] is the minimum from the left
            int right = nse[i] - i;  // Number of subarrays where arr[i] is the minimum towards the right
            sum = (long)(sum +(long)((long)((long)(left * right)%mod) * arr[i]) % mod) % mod;
        }
        
        return (int)sum;
    }
}