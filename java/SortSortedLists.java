/*
 *
 * 组合n个已经排序的链表
 * 
 * 采用小根堆的方式解决问题
 * 每次最小值入队之后，删除堆顶指向堆顶队列第二个元素，并做堆调整
 *
 * */

class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}

public class SortSortedLists {
    public ListNode mergeKLists(ListNode[] lists) {
        // create Heap
        int m=0, n=lists.length-1;
        while (m < n) {
            while (lists[m] != null && m < n) m ++;
            while (lists[n] == null && m < n) n --;
            if (m >= n) {
                break;
            } else {
                swap(lists,m,n);
            }
            
        }
        
        int size = 0;
        for (int i=0; i<lists.length; ++i) {
            if (lists[i] != null) {
                size ++;
            } else {
                break;
            }
        }
        
        if (size == 0) {
            return null;
        }
        for (int i=size/2-1; i >= 0; --i) {
            heapAdjust(lists,i,size);
        }
        
        ListNode ans;
        ListNode p = lists[0];
        ans = p;
        
        while (size > 0) {
            lists[0] = lists[0].next;
            if (lists[0] == null) {
                lists[0] = lists[size-1];
                size --;
            }
            heapAdjust(lists,0,size);
            p.next = lists[0];
            p = p.next;
        }
        
        return ans;
    }
    
    public void swap(ListNode[] lists, int i, int j) {
        ListNode temp = lists[i];
        lists[i] = lists[j];
        lists[j] = temp;
    }
    
    public void heapAdjust(ListNode[] lists,int index, int end) {
        int biggerChild;
        while (2*index+1 < end) {//child existed
            if (2*index + 2 < end && lists[2*index+2].val < lists[2*index+1].val) {
                biggerChild = 2*index+2;
            } else {
                biggerChild = 2*index+1;
            }
            if (lists[index].val > lists[biggerChild].val) {
                swap(lists,index,biggerChild);
            } else {
                break;
            }
            index = biggerChild;
        }
    }
}
