import java.util.Scanner;

public class Main {

    public static void palindromePermutation(String str){
        //removing all spaces
        str = str.replaceAll("\\s", "");

        int[] length = new int[128];
        for(char ch : str.toCharArray()){
            length[ch]++;
        }

        boolean isPalindrome = false;

        for(int i = 0 ; i < 128 ; i++){
            if(length[i]%2 == 0){

            }else if(length[i]%2 == 1){
                if(isPalindrome){
                    isPalindrome = false;
                    System.out.println("It is not a palindrome of any permutation of given string");
                    return;
                }else {
                    isPalindrome = true;
                }
            }
        }
        System.out.println("It is a palindrome of any permutation of given string");
    }

    public static void main(String[] args) { // unit testing (optional)

        Scanner scanner = new Scanner(System.in);
        String str = scanner.nextLine();

        palindromePermutation(str);

    }
}