import java.util.Scanner;

public class Main {

    public static void stringCompression(String str){
        int i = 0;
        StringBuilder builder = new StringBuilder();
        int count = 1;
        while(i < str.length() - 1){
            if(str.charAt(i) == str.charAt(i + 1)){
                count++;
            }else{
                builder.append(str.charAt(i)).append(count);
                count = 1;
            }
            i++;
        }
        builder.append(str.charAt(i)).append(count);
        if(str.length() < builder.toString().length()){
            System.out.println(str);
        }else{
            System.out.println(builder.toString());
        }
    }

    public static void main(String[] args) { // unit testing (optional)

        Scanner scanner = new Scanner(System.in);
        String str = scanner.nextLine();

        stringCompression(str);


    }
}