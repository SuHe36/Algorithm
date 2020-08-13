package Sort;

import java.util.Arrays;

public class BubbleSort {

    public static int[] bubbleSort(int[] nums){
        boolean flag = false;
        int temp;

        while(! flag){
            flag = true;
            for (int i=1; i<nums.length; i++){
                if(nums[i] < nums[i-1]){
                    temp = nums[i];
                    nums[i] = nums[i-1];
                    nums[i-1] = temp;
                    flag = false;
                }
            }

        }
        return nums;
    }


    public static void main(String[] args){
        int[] nums = {5,4,3,2,1};
        int[] res = bubbleSort(nums);
        System.out.println(Arrays.toString(res));

    }

}
