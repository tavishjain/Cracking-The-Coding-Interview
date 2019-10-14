import java.util.Stack;

class StackMin {
    private static Stack<Integer> minStack = new Stack<>();

    private static void add(int item) {
        if (!minStack.isEmpty() && minStack.peek() < item) {
            item = minStack.peek();
        }
        minStack.add(item);
    }

    private static int min() {
        if (!minStack.isEmpty()) {
            return minStack.peek();
        }

        return Integer.MIN_VALUE;
    }

    public static void main(String[] args) {
        add(4);
        add(7);
        add(6);
        add(10);
        add(9);
        add(2);
        add(5);

        while (!minStack.isEmpty()) {
            System.out.println("Min Value: " + min());
            minStack.pop();
        }
    }
}