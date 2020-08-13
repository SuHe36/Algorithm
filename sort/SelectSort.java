package Sort;

import java.util.Arrays;

public class SelectSort {

    public static int[] selectSort(int[] nums){
        if(nums.length == 0 || nums.length == 1){
            return nums;
        }

        for(int i=0; i<nums.length; i++){
            int midIndex = i;
            int minValue = nums[i];
            for(int j=i; j< nums.length; j++){
                if(nums[j] < minValue){
                    midIndex = j;
                    minValue = nums[j];
                }
            }
            int temp = nums[i];
            nums[i] = minValue;
            nums[midIndex] = temp;

        }

        return nums;
    }

    public static void main(String[] args){
        int[] nums = {4,3,2,5,7,6};
        int[] res = selectSort(nums);
        System.out.println(Arrays.toString(res));
    }

}
