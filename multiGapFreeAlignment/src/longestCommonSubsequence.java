import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class longestCommonSubsequence {


    static int first = 1;
    static int second = 2;
    static int third = 3;

    static String S = new String();
    static String T = new String();

    public static int scoreMax(int a, int b, int c){

        int maxValue = Math.max(a, Math.max(b, c));



        if(maxValue == a){
            return a;
        }else if(maxValue == b){
            return b;
        }else if(maxValue == c){
            return c;
        }
        return 0;
    }

    public static void printLongestCommonSubsequence(int[][] t,int n,int m){

        if(n==0 || m==0){
            return;
        }
        if(t[n][m] == 3){
            printLongestCommonSubsequence(t, n-1, m-1);
            System.out.print(T.charAt(n));
        }else if(t[n][m] == 2){
                printLongestCommonSubsequence(t, n-1, m);
            }else {
                printLongestCommonSubsequence(t, n, m-1);
            }
    }

    public static void longestCommonSubsequence(FileReader fileReader) throws IOException{

        BufferedReader bufferedReader = new BufferedReader(fileReader);

        String line;

        int x = 1;



        //Initialization of strings from file
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

        int n = T.length();
        int m = S.length();

        System.out.println(n);
        System.out.println(m);

        int[][] s = new int[n+1][m+1];
        int[][] t = new int[n+1][m+1];

        int i = 0;
        int j = 0;

        s[0][0] = 0;

        for(i=1; i<n+1; i++){
            s[i][0] = 0;
        }

        for(j=1; j<m+1; j++){
            s[0][j] = 0;
        }

        boolean match = false;

        int maxScored = 0;

        for(i=1; i<n+1; i++){
            for(j=1; j<m+1; j++){
                if(T.charAt(i-1) == S.charAt(j-1)){
                    match = true;
                }

                maxScored = scoreMax(s[i-1][j], s[i][j-1], s[i-1][j-1]);
                //System.out.println("maxScored is: " + maxScored + " and current match is: " + match);

                if(match){
                    s[i][j] = s[i-1][j-1] + 1;
                    t[i][j] = 3;
                }else if(maxScored == s[i-1][j] ) {
                    s[i][j] = s[i-1][j];
                    t[i][j] = 2;
                }else if(maxScored == s[i][j-1]) {
                    s[i][j] = s[i][j-1];
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

        for(i=0; i<n+1; i++){
            for(j=0; j<m+1; j++){
                System.out.print(t[i][j] + " ");
            }
            System.out.println();
        }

        printLongestCommonSubsequence(t, n-1, m-1);

        System.out.println("\n\n" + "best score is " + s[n][m]);
    }

    public static void main(String[] args) throws FileNotFoundException, IOException{

        String fileName = "C:\\Users\\Mardot\\Documents\\GitHub\\multiGapFreeAlignment\\src\\textSequences.txt";
        FileReader fileReader = new FileReader(fileName);

        longestCommonSubsequence(fileReader);
    }
}
