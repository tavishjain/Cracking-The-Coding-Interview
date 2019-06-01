import java.util.Scanner;

public class Main {

    public static void oneReplace(String str1, String str2){
        boolean changed = false;
        for(int i = 0 ; i < str1.length() ; i++){
            if(str1.charAt(i) != str2.charAt(i)){
                if(changed){
                    System.out.println("Not One away");
                    return;
                }
                changed = true;
            }
        }
        System.out.println("One away");
    }

    public static void oneInsert(String str1, String str2){
        int index1 = 0, index2 = 0;

        while(index1 < str1.length() && index2 < str2.length()){
            if(str1.charAt(index1) != str2.charAt(index2)){
                if(index1 != index2){
                    System.out.println("Not One away");
                    return;
                }
                index2++;
            }else{
                index1++;
                index2++;
            }
        }
        System.out.println("One away");
    }

    public static void oneAway(String str1, String str2){
        switch(str1.length() - str2.length()){

            case 0 :
                oneReplace(str1, str2);
                break;
            case 1 :
                oneInsert(str1, str2);
                break;
            case -1 :
                oneInsert(str2, str1);
            default :
                System.out.println("Not One away");
                break;
        }
    }

    public static void main(String[] args) { // unit testing (optional)

        Scanner scanner = new Scanner(System.in);
        String str1 = scanner.nextLine();
        String str2 = scanner.nextLine();

        oneAway(str1, str2);


    }
}