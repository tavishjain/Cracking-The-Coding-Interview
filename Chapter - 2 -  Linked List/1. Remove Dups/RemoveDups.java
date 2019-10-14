import java.util.HashSet;
import java.util.Set;

class RemoveDups {
    static ListNode head = null;

    public static void removeDups(ListNode head) {
        Set<Integer> nums = new HashSet<>();
        ListNode curr = head;
        while (curr.next != null) {
            nums.add(curr.val);
            while (curr.next != null && nums.contains(curr.next.val)) {
                curr.next = curr.next.next;
                curr = curr.next;
            }
            curr = curr.next;
        }
    }

    public static void print(ListNode head) {
        ListNode current = head;
        while (current != null) {
            System.out.print(current.val + " ");
            current = current.next;
        }
        System.out.println();
    }

    public static void add(int data) {
        if (head == null) {
            head = new ListNode(data);
            return;
        }
        ListNode curr = head;
        while (curr.next != null) {
            curr = curr.next;
        }
        curr.next = new ListNode(data);
    }

    public static void main(String[] args) {
        add(3);
        add(5);
        add(3);
        add(67);
        add(5);
        add(90);
        add(43);

        print(head);
        removeDups(head);
        print(head);
    }

    static class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
        }
    }
}