
import java.util.*; 
public class Main
{
    static class node  
    { 
        int data; 
        node next; 
  
        public node(int data)  
        { 
            this.data = data; 
        } 
    } 

    static void removeDuplicate(node head)  
    { 
        
        HashSet<Integer> h = new HashSet<>(); 

        node current = head; 
        node prev = null; 
        while (current != null)  
        { 
            int curval = current.data; 

            if (h.contains(curval)) 
            { 
                prev.next = current.next; 
            } 
            else 
            { 
                h.add(curval); 
                prev = current; 
            } 
            current = current.next; 
        } 
  
    } 

    static void printList(node head)  
    { 
        while (head != null)  
        { 
            System.out.print(head.data + " "); 
            head = head.next; 
        } 
    } 
  
    public static void main(String[] args)  
    { 
        node start = new node(50); 
        start.next = new node(30); 
        start.next.next = new node(51); 
        start.next.next.next = new node(51); 
        start.next.next.next.next = new node(12); 
        start.next.next.next.next.next = new node(51); 
        start.next.next.next.next.next.next = new node(30); 
  
        System.out.println("Old Linked list :"); 
        printList(start); 
  
        removeDuplicate(start); 
  
        System.out.println("\nLinked list after removing duplicates :"); 
        printList(start); 

    } 

}
