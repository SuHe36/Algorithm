package Sort;

import java.util.Arrays;

public class InsertSort2 {

    public static int[] insertSort(int[] nums){

        if(nums.length == 0 || nums.length == 1){
            return nums;
        }

        for (int i=1; i < nums.length; i++){
            int current = nums[i];
            int j=i-1;
            while(j >=0 && nums[j] > current){
                nums[j+1] = nums[j];
                j--;
            }

            nums[j+1] = current;

        }

        return nums;

    }

    public static void main(String[] args){
        int[] nums = {4,3,1,2,5,7,6};
        int[] res = insertSort(nums);
        System.out.println(Arrays.toString(res));

    }

}
