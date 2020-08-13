package Sort;

import java.util.Arrays;

public class ShellSort {

    public static void shellSort(int[] nums){
        int n=nums.length;
        if(n==0 || n==1){
            return;
        }

        for(int gap=n/2; gap >=1 ; gap =gap/2){

            for(int i=gap; i<n; i++){
                int temp = nums[i];
                int j;
                for( j=i; j>=gap && nums[j-gap]>=nums[j];j=j-gap){
                    nums[j] = nums[j-gap];
                }
                nums[j] = temp;
            }
        }
        return;

    }


    public static void main(String[] args){
        int[] nums = {4,7,5,8,2,6,10};
        shellSort(nums);
        System.out.println(Arrays.toString(nums));
    }

}
