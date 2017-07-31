/**
 * Created by Mardot on 7/14/2017.
 */
public class Eight_Queens_Problem {

    static int[][] board = new int[8][8];

    static boolean isValid(){

        int rowSum =0;
        int colSum =0;

        for(int row=0; row<8; row++){
            for(int col=0; col<8; col++){
                rowSum = rowSum + board[row][col];
                colSum = colSum + board[col][row];
                if(rowSum>1 || colSum>1){
                    return false;
                }
            }
        }
        return true;
    }

    static void solver(int currentRow){

        if(currentRow == 8){
            return;
        }else {
            for (int col = 0; col < 8; col++) {
                board[currentRow][col] = 1;
                if (isValid()) solver(currentRow + 1);
                board[currentRow][col] = 0;
            }
        }
    }


    public static void main(String[] args) {

        ///////////////////////////////////////////////////PRE CHECK
        ///////////////////////////////////////////////
        for(int row=0; row<8; row++){
            for(int col=0; col<8; col++){
                System.out.print( board[row][col]);
                System.out.print("\t");
            }
            System.out.println("\n");
        }

        solver(0);

        ///////////////////////////////////////////////////POST CHECK
        ///////////////////////////////////////////////

        System.out.println("\n\n");

        for(int row=0; row<8; row++){
            for(int col=0; col<8; col++){
                System.out.print( board[row][col]);
                System.out.print("\t");
            }
            System.out.println("\n");
        }


    }






}
