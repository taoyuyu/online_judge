package taoyu.com.BSS;

/**
 * Created by yutao on 17/5/26.
 */

/*
*
* 最大子段和
* 给定一段序列a1,a2,a3,…,an；求该序列的子段和的最大值。
*
* */
public class BiggestSumSqu {
    public static void main(String[] args) {
        int[] array = {-2,1,4,-3,-1,6,9,-4,6};

        System.out.println(getSubSqu(array));
    }
    public static int getSubSqu(int[] array) {
        int[] list = new int[array.length];
        list[0] = array[0];
        for (int i=1; i<array.length; ++i) {
            if (list[i-1] < 0) {
                list[i] = array[i];
            } else {
                list[i] = list[i-1] + array[i];
            }
        }

        int max = 0xffffffff;
        for (int i:list) {
            max = max > i ? max : i;
        }
        return max;
    }
}
