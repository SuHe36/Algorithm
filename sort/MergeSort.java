package Sort;

import java.util.Arrays;

public class MergeSort {

    public static void mergeSort(int[] nums, int low, int high){
        int mid = low +(high -low)/2;
        if(low < high){
            mergeSort(nums, low, mid);
            mergeSort(nums, mid+1, high);
            merge(nums, low, mid, high);
//            System.out.println(Arrays.toString(nums));
        }
    }


    public static void merge(int[] nums, int low, int mid, int high){
        int[] temp = new int[high-low+1];

        int leftIndex = low;
        int rightIndex = mid +1;
        int k = 0;

        while(leftIndex <= mid && rightIndex <= high){
            if(nums[leftIndex] <= nums[rightIndex]){
                temp[k] = nums[leftIndex];
                leftIndex++;
            }else{
                temp[k] = nums[rightIndex];
                rightIndex++;
            }
            k++;
        }

        while(leftIndex <= mid){
            temp[k] = nums[leftIndex];
            leftIndex++;
            k++;
        }

        while(rightIndex <= high){
            temp[k] = nums[rightIndex];
            rightIndex++;
            k++;
        }

        for(int i=0; i<temp.length; i++){
            nums[low+i] = temp[i];
        }

    }

    public static void main(String[] args){
        int[] nums = {4,3,2,6,5,7,9,8};
        mergeSort(nums,0,nums.length-1);
        System.out.println(Arrays.toString(nums));
    }

}
