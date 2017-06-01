/**
 * Created by yutao on 17/5/31.
 */

/*
*
* 有一个无穷数列，1,2,3,4,5,6,7,8,9,10,11,12......
* 输入一个整数 n ,输出该数列第n位为多少；
* 例如输入
* input 1
* output 1
* input 2
* output 2
* input 9
* output 9
* input 10
* output 1
* input 11
* output 0
* input 12
* output 1
* input 15
* output 2
* */
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
public class WorksApplication {
    private static Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
        /*
        * 1 -> 9
        * 2 -> 90 * 2
        * 3 -> 900 * 3
        * 4 -> 9000 * 4
        * 求和
        * */
        int n;
        while (sc.hasNext()) {
            n = sc.nextInt();
            int tag = 1;
            while (true) {
                int len =  9 * (int)Math.pow(10, tag - 1) * tag;
                if (n - len <= 0) {
                    break;
                } else {
                    n -= len;
                    tag++;
                }
            }
            int x = n % tag;
            int y = (n-1) / tag;
            int k = y + (int)Math.pow(10,tag-1);
            List<Integer> list = new ArrayList<>();
            while (k > 0) {
                list.add(k % 10);
                k /= 10;
            }
            System.out.println(list.get(x));
        }


    }
}