import java.util.Scanner;

public class Main {

    public static boolean isSubstring(String str1, String str2){
       return str2.contains(str1);
    }

    public static void stringRotation(String str1, String str2){
        str2 = str2 + str2;
        if(isSubstring(str1, str2)){
            System.out.println("It is a rotation");
        }else{
            System.out.println("It is not a rotation");
        }
    }

    public static void main(String[] args) { // unit testing (optional)

        Scanner scanner = new Scanner(System.in);
        String str1 = scanner.nextLine();
        String str2 = scanner.nextLine();

        stringRotation(str1, str2);
    }
}