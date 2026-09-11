import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        // 1. Sort to handle duplicates efficiently
        Arrays.sort(nums); 
        boolean[] visited = new boolean[nums.length];
        
        backtrack(nums, new ArrayList<>(), visited, result);
        return result;
    }

    private void backtrack(int[] nums, List<Integer> current, boolean[] visited, List<List<Integer>> result) {
        // Base case: if the current permutation is complete
        if (current.size() == nums.length) {
            result.add(new ArrayList<>(current));
            return;
        }

        for (int i = 0; i < nums.length; i++) {
            // Skip if the element is already used in the current path
            if (visited[i]) {
                continue;
            }

            // Skip duplicate elements to avoid duplicate permutations
            // If nums[i] == nums[i - 1] and nums[i - 1] was NOT visited in this depth,
            // it means we already explored the branch starting with a matching value.
            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) {
                continue;
            }

            // Choose
            visited[i] = true;
            current.add(nums[i]);

            // Explore
            backtrack(nums, current, visited, result);

            // Un-choose (Backtrack)
            current.remove(current.size() - 1);
            visited[i] = false;
        }
    }
}
