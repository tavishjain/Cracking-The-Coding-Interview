import java.util.Stack;

public class StackMin {

    public static void main(String[] args) {
        StackWithMin stack = new StackWithMin();
        StackWithMin2 stack2 = new StackWithMin2();
        int[] array = {2, 1, 3, 1};
        for (int value : array) {
            stack.push(value);
            stack2.push(value);
            System.out.print(value + ", ");
        }
        System.out.println('\n');
        for (int i = 0; i < array.length; i++) {
            System.out.println("Popped " + stack.pop().value + ", " + stack2.pop());
            System.out.println("New min is " + stack.getMin() + ", " + stack2.min());
        }
    }
}

class StackWithMin extends Stack<NodeWithMin> {
    public void push(int value) {
        int newMin = Math.min(value, getMin());
        super.push(new NodeWithMin(value, newMin));
    }

    public int getMin() {
        if (this.isEmpty()) {
            return Integer.MAX_VALUE;
        } else {
            return peek().min;
        }
    }
}


class StackWithMin2 extends Stack<Integer> {
    Stack<Integer> s2;

    public StackWithMin2() {
        s2 = new Stack<Integer>();
    }

    public void push(int value) {
        if (value <= min()) {
            s2.push(value);
        }
        super.push(value);
    }

    public Integer pop() {
        int value = super.pop();
        if (value == min()) {
            s2.pop();
        }
        return value;
    }

    public int min() {
        if (s2.isEmpty()) {
            return Integer.MAX_VALUE;
        } else {
            return s2.peek();
        }
    }
}


class NodeWithMin {
    public int value;
    public int min;

    public NodeWithMin(int v, int min) {
        value = v;
        this.min = min;
    }
}

