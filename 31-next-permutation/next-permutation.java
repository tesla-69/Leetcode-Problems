public class Solution {
    public void nextPermutation(int[] nums) {
        int index = -1;
        // Find the first index from the end where nums[index] < nums[index + 1]
        for (int i = nums.length - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            // If no such index exists, reverse the entire array
            reverse(nums, 0, nums.length - 1);
        } else {
            // Find the first index from the end where nums[i] > nums[index]
            for (int i = nums.length - 1; i > index; i--) {
                if (nums[i] > nums[index]) {
                    // Swap the elements
                    swap(nums, i, index);
                    break;
                }
            }
            // Reverse the sub-array from index + 1 to the end
            reverse(nums, index + 1, nums.length - 1);
        }
    }

    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    private void reverse(int[] nums, int start, int end) {
        while (start < end) {
            swap(nums, start, end);
            start++;
            end--;
        }
    }
}
