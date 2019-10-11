import java.util.Scanner;
//Main class
public class Main {

    public static void isUnique(String str){
        if(str.length() > 128){
            System.out.println("There are repeating characters in this String");
            return;
        }else{
            boolean[] present = new boolean[128];
            for(char ch : str.toCharArray()){
                if(present[ch]){
                    System.out.println("There are repeating characters in this String");
                    return;
                }
                present[ch] = true;
            }
            System.out.println("There are no repeating characters in this String");
        }
    }

    public static void main(String[] args) { // unit testing (optional)

        Scanner scanner = new Scanner(System.in);
        String str = scanner.nextLine();

        isUnique(str);

    }
}