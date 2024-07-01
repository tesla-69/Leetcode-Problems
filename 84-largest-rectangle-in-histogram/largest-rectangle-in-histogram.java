class Solution {
    public int largestRectangleArea(int[] heights) {
        Stack<Integer> st = new Stack<>();
        int[] left = new int[heights.length];
        int[] right = new int[heights.length];
        
        // Calculate the index of the nearest smaller element to the left
        for (int i = 0; i < heights.length; i++) {
            while (!st.isEmpty() && heights[st.peek()] >= heights[i]) {
                st.pop();
            }
            if (st.isEmpty()) {
                left[i] = -1;
            } else {
                left[i] = st.peek();
            }
            st.push(i);
        }
        
        // Clear the stack for the next calculation
        st.clear();
        
        // Calculate the index of the nearest smaller element to the right
        for (int i = heights.length - 1; i >= 0; i--) {
            while (!st.isEmpty() && heights[st.peek()] >= heights[i]) {
                st.pop();
            }
            if (st.isEmpty()) {
                right[i] = heights.length;
            } else {
                right[i] = st.peek();
            }
            st.push(i);
        }
        
        // Calculate the maximum area
        int maxArea = 0;
        for (int i = 0; i < heights.length; i++) {
            int width = right[i] - left[i] - 1;
            int area = heights[i] * width;
            maxArea = Math.max(maxArea, area);
        }
        
        return maxArea;
    }
}
