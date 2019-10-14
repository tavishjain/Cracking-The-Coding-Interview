class ReturnKthToLast {
    static ListNode head = null;

    public static ListNode kthLast(ListNode head, int k) {
        ListNode slow = head;
        ListNode fast = head;

        while (k > 0 && fast != null) {
            fast = fast.next;
            k--;
        }

        while (fast != null) {
            fast = fast.next;
            slow = slow.next;
        }

        return slow;
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
        add(31);
        add(67);
        add(8);
        add(90);
        add(43);

        print(head);
        System.out.println("Kth Last: " + kthLast(head, 5).val);
    }

    static class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
        }
    }
}