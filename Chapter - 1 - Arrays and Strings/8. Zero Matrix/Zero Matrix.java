import java.util.Scanner;

public class Main {

    public static void zeroMatrix(int[][] arr, int m, int n){
        int i, j, x = 0, y = 0;
        for(i = 0 ; i < m ; i++){
            for(j = 0 ; j < n ; j++){
                if(arr[i][j] == 0){
                    x = i;
                    y = j;
                }
            }

        }
        int k;
        for(k = 0 ; k < n ; k++){
            arr[k][y] = 0;
        }
        for(k = 0 ; k < m ; k++){
            arr[x][k] = 0;
        }
        for(i = 0 ; i < m ; i++){
            for(j = 0 ; j < n ; j++){
                System.out.print(arr[i][j] + " ");
            }
            System.out.println("");
        }
    }

    public static void main(String[] args) { // unit testing (optional)

        Scanner scanner = new Scanner(System.in);
        int m = scanner.nextInt();
        int n = scanner.nextInt();
        int[][] mat = new int[m][n];

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                mat[i][j] = scanner.nextInt();
            }
        }

        zeroMatrix(mat, m, n);


    }
}