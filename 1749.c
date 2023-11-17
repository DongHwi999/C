import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.StringReader;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder output = new StringBuilder();
    static String src = "3 5\n" +
            "2 3 -21 -22 -23\n" +
            "5 6 -22 -23 -25\n" +
            "-22 -23 4 10 2";

    static int N, M, data[][], accumulateSum[][];

    public static void main(String[] args) throws IOException {
        //input= new BufferedReader(new InputStreamReader(System.in));
        input = new BufferedReader(new StringReader(src));

        StringTokenizer str;
        str = new StringTokenizer(input.readLine());
        N = Integer.parseInt(str.nextToken());
        M = Integer.parseInt(str.nextToken());

        data = new int[N + 1][M + 1];
        accumulateSum = new int[N + 1][M + 1];

        for (int i = 1; i <= N ; i++) {
            str = new StringTokenizer(input.readLine());
            for (int j = 1; j <= M; j++) {
                data[i][j] = Integer.parseInt(str.nextToken());
                accumulateSum[i][j] = accumulateSum[i][j - 1] + accumulateSum[i - 1][j] - accumulateSum[i - 1][j - 1] + data[i][j];
            }
        }

        int answer = Integer.MIN_VALUE;
        for (int rowS = 1; rowS <= N; rowS++) {
            for (int rowE = rowS; rowE <= N; rowE++) {
                for (int colS = 1; colS <= M; colS++) {
                    for (int colE = colS; colE <= M; colE++) {
                        answer = Math.max(answer, accumulateSum[rowE][colE] - accumulateSum[rowS - 1][colE] - accumulateSum[rowE][colS - 1] + accumulateSum[rowS - 1][colS - 1]);
                    }
                }
            }
        }
        System.out.println(answer);
    }

}