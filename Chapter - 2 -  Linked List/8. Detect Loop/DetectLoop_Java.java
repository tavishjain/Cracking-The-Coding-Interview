import java.util.*; 
public class Main
{   
    static Node head; 
    static class Node { 
        int data; 
        Node next; 
        Node(int d) 
        { 
            data = d; 
            next = null; 
        } 
    } 
  
    static public void push(int new_data) 
    { 

        Node new_node = new Node(new_data); 
        new_node.next = head; 
        head = new_node; 
    } 
  
 
    static boolean detectLoop(Node node) 
    { 
        HashSet<Node> s = new HashSet<Node>(); 
        while (node != null) { 
 
            if (s.contains(node)) 
            {
                return true; 
            }
            
            s.add(node); 
            node = node.next; 
        } 
  
        return false; 
    } 

    public static void main(String[] args) 
    { 
        Main ll = new Main(); 
        Scanner s = new Scanner(System. in);
        int n = s.nextInt();
        for(int i=0;i<n;i++)
        {
            int x = s.nextInt();
            ll.push(x);
        }
        
        ll.head.next.next.next.next = ll.head; 
  
        if (detectLoop(head)) 
        {
            System.out.println("Loop Detected"); 
        }
            
        else
        {
            System.out.println("No Loop Found"); 
        }
           
    } 


}
