package Sort;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class BucketSort {

    public static void bucketSort(int[] nums, int bucketNum){
        List<ArrayList<Integer>> buckets = new ArrayList<>();
        for (int i=0; i< bucketNum;i++){
            buckets.add(new ArrayList<>());
        }

        for(int i=0; i<nums.length; i++){
            buckets.get(nums[i]/10).add(nums[i]);
        }

        for(int i=0; i<bucketNum;i++){
            Collections.sort(buckets.get(i));
        }

        int k=0;
        for(int i =0; i<bucketNum;i++){
            for(int j=0; j<buckets.get(i).size();j++){
                if(j==buckets.get(i).size()){
                    break;
                }
                nums[k++] = buckets.get(i).get(j);
            }
        }

    }

    public static void main(String[] args){
        int[] nums = {2,9,7,17,12,46,42,74,75,88,91};
        bucketSort(nums, 10);
        System.out.println(Arrays.toString(nums));
    }

}
