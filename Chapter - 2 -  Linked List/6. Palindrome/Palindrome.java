class Palindrome {
    static ListNode head = null;

    public static ListNode reverse(ListNode head) {
        if (head == null)
            return head;

        ListNode current = head;
        ListNode temp;
        while (current.next != null) {
            temp = current.next.next;
            current.next.next = head;
            head = current.next;
            current.next = temp;
        }
        return head;
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
        head = reverse(head);
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