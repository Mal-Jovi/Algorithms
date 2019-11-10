import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class arrayTester {


    public static int scoreMax(int a, int b, int c){

        int maxValue = Math.max(a, Math.max(b, c));

        if(maxValue == a){
            return 1;
        }else if(maxValue == b){
            return 2;
        }else if(maxValue == c){
            return 3;
        }
        return 0;
    }

    public static void multiGapFreeGlobalAlignment(FileReader fileReader, int matchPoint, int mismatchPenalty, int gapPenalty) throws IOException{

        BufferedReader bufferedReader = new BufferedReader(fileReader);

        String line;

        int x = 1;

        String S = new String();
        String T = new String();

        while((line = bufferedReader.readLine()) != null){
            if(x==2){
                S = line;
            }else if(x==5){
                T = line;
            }
            System.out.println(line);
            x = x + 1;
        }

        System.out.println("\nSequence S is: " + S);
        System.out.println("Sequence T is: " + T);

        int n = S.length();
        int m = T.length();

        System.out.println(n);
        System.out.println(m);

        System.out.println("Char at S(16) is: " + S.charAt(15));
        System.out.println("Char at T(18) is: " + T.charAt(17));

        int[][] s = new int[n+1][m+1];
        int[][] t = new int[n+1][m+1];

        int i = 0;
        int j = 0;

        int temp = 0;

        s[0][0] = 0;

        for(i=1; i<n+1; i++){
            s[i][0] = s[i-1][0] + gapPenalty;
        }

        for(j=1; j<m+1; j++){
            s[0][j] = s[0][j-1] + gapPenalty;
        }

        boolean match = false;

        int maxScored = 0;

        int iTemp = 0;
        int jTemp = 0;

        for(i=1; i<n+1; i++){
            for(j=1; j<m+1; j++){
                if(S.charAt(i-1) == T.charAt(j-1)){
                    match = true;
                }

                maxScored = scoreMax(s[i-1][j], s[i][j-1], s[i-1][j-1]);

                if(maxScored == 3 && match==true){
                    s[i][j] = s[i-1][j-1] + matchPoint;
                    t[i][j] = 3;

                }else if(maxScored ==3 && match==false){
                    s[i][j] = s[i-1][j-1] + mismatchPenalty;
                    t[i][j] = 3;

                }else if(maxScored == 2 ) {
                    s[i][j] = s[i][j - 1] + gapPenalty;
                    t[i][j] = 2;
                }else if(maxScored == 1) {
                    s[i][j] = s[i - 1][j] + gapPenalty;
                    t[i][j] = 1;
                }
                match = false;
            }

        }

        for(i=0; i<n+1; i++){
            for(j=0; j<m+1; j++){
                System.out.print(s[i][j] + " ");
            }
            System.out.println();
        }

        System.out.println("\n\n" + "best score is " + s[n][m]);
    }

    public static void main(String[] args) throws FileNotFoundException, IOException{

        String fileName = "C:\\Users\\Mardot\\Documents\\GitHub\\multiGapFreeAlignment\\src\\hw1_short.fa.txt";
        FileReader fileReader = new FileReader(fileName);

        int matchPoint = 1;
        int mismatchPenalty = -1;
        int gapPenalty = -1;

        multiGapFreeGlobalAlignment(fileReader, matchPoint, mismatchPenalty, gapPenalty);
    }
}
