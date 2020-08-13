package Sort;

import java.util.Arrays;

public class CountSort {

    public static void countSort(int[] nums){
        int max = Arrays.stream(nums).max().getAsInt();
        int min = Arrays.stream(nums).min().getAsInt();

        int[] count = new int[max-min+1];
        int[] output = new int[nums.length];

        for(int i=0; i<nums.length;i++){
            count[nums[i]-min] += 1;
        }

        for(int i=1; i<count.length;i++){
            count[i] += count[i-1];
        }

        for(int i=nums.length-1; i>=0; i--){
//          这里对nums数组进行递归时，采取从后往前，是为了便于后面的基数排序用到时方便
            output[count[nums[i]-min]-1] = nums[i];
            count[nums[i]-min] -= 1;
        }

        for(int i=0; i<nums.length;i++){
            nums[i] = output[i];
        }


    }

    public static void main(String[] args){
        int[] nums = {2,2,2,2,1,1,1,1,4,4,4,5,5,5,6,6,6,2,5,6,7,7};
        countSort(nums);
        System.out.println(Arrays.toString(nums));
    }

}
