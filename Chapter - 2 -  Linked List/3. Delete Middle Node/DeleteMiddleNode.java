class DeleteMiddleNode {
    static ListNode head = null;

    public static ListNode middleNode(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;

        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }

    public static void deleteMid(ListNode head) {
        ListNode mid = middleNode(head);
        if (mid.next == null) {
            return;
        }
        mid.val = mid.next.val;
        mid.next = mid.next.next;
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
        add(90);
        add(43);

        print(head);
        deleteMid(head);
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