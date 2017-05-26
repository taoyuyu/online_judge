package taoyu.com.LIS;

/**
 * 最长递增子序列
 */
public class longestIncresingSqu {
    public static void main(String[] args) {
        int[] nums = {4,1,2,5,3,8,7,9,8};
        System.out.println(longestIncSqu(nums));
    }


    public static int longestIncSqu(int[] nums) {
        int[] list = new int[nums.length];
        list[0] = 1;
        for (int i=1; i<list.length; ++i) {
            list[i] = maxInList(list, nums, i) + 1;
        }
        int max = 0xffffffff;
        for (int i:list) {
            System.out.println(i);
            max = max>i?max:i;
        }
        System.out.println();
        return max;
    }

    public static int maxInList(int[] list, int[] nums, int index) {
        int max = 0;
        for (int i=0; i<index; ++i) {
            if (nums[i] < nums[index]) {
                max = max > list[i] ? max : list[i];
            }
        }
        return max;
    }
}
