import java.util.*;

class Solution{
    public int[] twoSum(int[] nums, int target){
        Hashtable<Integer, Integer> hashtable = new Hashtable<Integer, Integer>();
        Integer key = 0;
        for(int i = 0; i < nums.length; i++){
            hashtable.put(nums[i], i);
        }
        int indexArray[] = new int[2]; 
        for(int i = 0; i < nums.length; i++){
            key = target - nums[i];
            if(hashtable.get(key) != null && !hashtable.get(key).equals(i)){//if the index was found
                    indexArray[0] = i;
                    indexArray[1] = hashtable.get(key);
                    return indexArray;
            }
        }
        return null;
    }

}
class Main{
    public static void main(String[] args){
        Solution solution = new Solution();
        int nums[] = {2,5,5, 11};
        int result[] = new int[2];
        result = solution.twoSum(nums, 10);
        for(int i = 0; i < result.length; i++){
            System.out.print(result[i] + " ");
        }
    }
}