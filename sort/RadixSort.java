package Sort;

import java.util.Arrays;

public class RadixSort {

    public static void radixSort(int[] nums, int exp){
        int n = nums.length;
        if(n==0 || n==1){
            return;
        }
        int max = Arrays.stream(nums).max().getAsInt();

        for(int base=1; max/base >0; base *= exp){
            countSort(nums, base, exp);
            System.out.println(Arrays.toString(nums));
        }

    }

    public static void countSort(int[] nums, int base, int exp){
        int[] count = new int[exp];
        int[] output = new int[nums.length];

        for (int i=0; i<nums.length; i++){
            count[(nums[i]/base)%exp] += 1;
        }

        for(int i=1; i<exp; i++){
            count[i] += count[i-1];
        }

//        for(int i=0; i< nums.length;i++){
        for(int i=nums.length-1; i>=0;i-- ){
//          要对nums数组从后往前进行递归，因为此时的nums已经被排过序了，那么从后往前可以保证在上一阶段的排序结果代入到当前阶段。
//          比如上一阶段是个位数比较，当前是十位比较，那么从后往前可以保证34位于32的后面。
//          如果是从前往后遍历nums，会在最后结果中产生不是顺序的，比如 18，34，32这种。
            output[count[(nums[i]/base)%exp] -1] = nums[i];
            count[(nums[i]/base)%exp]-=1;
        }

        for(int i=0; i<nums.length;i++){
            nums[i] = output[i];
        }
        return;
    }

    public static void main(String[] args){
        int[] nums ={12,4,23,22,14,56,47,87,66,32,34,99};
        radixSort(nums,10);
        System.out.println(Arrays.toString(nums));
    }

}
