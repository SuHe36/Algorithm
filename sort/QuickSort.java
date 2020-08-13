package Sort;

import java.util.Arrays;

public class QuickSort {

    public static void quickSort(int[] nums,int start, int end){
        int n = nums.length;
        if(n==0 || n==1){
            return;
        }

        if(start >= end){
            return;
        }

        int pivotIndex = partition(nums,start, end);
        quickSort(nums, start, pivotIndex-1);
        quickSort(nums, pivotIndex+1, end);

    }

    public static int partition(int[] nums, int start, int end){
        int pivot = nums[end];
        int current = start;

        for(int i=start; i <end; i++){
            if(nums[i] < pivot){
                int temp = nums[i];
                nums[i] = nums[current];
                nums[current] = temp;
                current++;
            }
        }
        int temp = nums[end];
        nums[end] = nums[current];
        nums[current] = temp;
        return current;

    }

    public static void main(String[] args){
        int[] nums = {4,5,7,6,2,3,1};
        quickSort(nums,0,nums.length-1);
        System.out.println(Arrays.toString(nums));
    }

}
