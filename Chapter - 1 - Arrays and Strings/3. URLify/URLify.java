import java.util.Scanner;

public class Main {

    public static void URLify(String str, int size){
        StringBuilder builder = new StringBuilder();
        for(char ch : str.toCharArray()){
            if(size > 0) {
                if (ch != ' ') {
                    builder.append(ch);
                } else {
                    builder.append("%20");
                }
                size--;
            }
        }
        System.out.println("The modified string is " + builder.toString());
    }

    public static void main(String[] args) { // unit testing (optional)

        Scanner scanner = new Scanner(System.in);
        String str = scanner.nextLine();
        int size = scanner.nextInt();

        URLify(str, size);

    }
}