package Sort;

import java.lang.reflect.Array;
import java.util.Arrays;

public class HeapSort {

    public static void heapSort(int[] nums){
        int n = nums.length;


        for(int i =n/2-1; i>=0; i--){
//           对给定的数据进行建堆的过程，根据完全二叉树的特性，index为[n/2, n-1]的节点，都是叶子节点
//            所以建堆的过程要对父节点进行判断，也就是从底向上的过程
            heapify(nums, i,n);
        }

        for (int i=n-1; i>=0; i--){
//            建完堆后，从堆中一个一个的提取元素。
            int t = nums[i];
            nums[i] = nums[0];
            nums[0] = t;

            heapify(nums, 0, i);
//          注意这里传入的是堆的规模，最初传入的应该是n-1，也就是此时已经把根节点的值跑出了，如果传入的是i+1，会造成越界，导致排序失败。
        }

    }

    public static void heapify(int[] nums, int parentIndex, int n){
        int largestIndex = parentIndex;
        int leftIndex = 2*parentIndex + 1;
        int rightIndex = 2*parentIndex + 2;

        if(leftIndex < n && nums[leftIndex] > nums[largestIndex]){
            largestIndex = leftIndex;
        }

        if(rightIndex < n && nums[rightIndex] > nums[largestIndex]){
            largestIndex = rightIndex;
        }

        if(largestIndex != parentIndex) {
            int temp = nums[parentIndex];
            nums[parentIndex] = nums[largestIndex];
            nums[largestIndex] = temp;
            heapify(nums, largestIndex, n );
        }

    }

    public static void main(String[] args){
        int[] nums = {4,3,2,5,7,6,1};
        heapSort(nums);
        System.out.println(Arrays.toString(nums));
    }

}
