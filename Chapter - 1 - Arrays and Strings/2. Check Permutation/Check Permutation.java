import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;
//check Permutation Combination By Sorting
public class Main {

    public static void checkPermutationBySorting(String str1, String str2){

        if(str1.length() != str2.length()){
            System.out.println("Both are not permutations of each other");
            return;
        }

        //sort array 1
        char tempArray[] = str1.toCharArray();
        Arrays.sort(tempArray);
        str1 = new String(tempArray);

        tempArray= str2.toCharArray();
        Arrays.sort(tempArray);
        str2 = new String(tempArray);

        if(str1.equals(str2)){
            System.out.println("Both are permutations of each other");
        }else{
            System.out.println("Both are not permutations of each other");
        }
    }

    public static void checkPermutationByCount(String str1, String str2){

        if(str1.length() != str2.length()){
            System.out.println("Both are not permutations of each other");
            return;
        }

        int[] length = new int[128];
        for(char ch : str1.toCharArray()){
            length[ch]++;
        }
        for(char ch : str2.toCharArray()){
            length[ch]--;
        }
        for(int i = 0 ; i < str1.length() ; i++){
            if(length[i] != 0){
                System.out.println("Both are not permutations of each other");
                return;
            }
        }
        System.out.println("Both are permutations of each other");
    }

    public static void main(String[] args) { // unit testing (optional)

        Scanner scanner = new Scanner(System.in);
        String str1 = scanner.nextLine();
        String str2 = scanner.nextLine();

        checkPermutationBySorting(str1, str2);
        checkPermutationByCount(str1, str2);

    }
}