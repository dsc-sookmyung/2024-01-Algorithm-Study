package algorithm_java;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

//투 포인터 
public class N2230 {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
 
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int[] arr = new int[N];
        
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }
        Arrays.sort(arr);
 
        int i = 0, j = 0;
        int difference = Integer.MAX_VALUE;
        int result=0;
        // 투 포인터 알고리즘
        while (i < N) {
            if (arr[i] - arr[j] < M) {
                i++;
                continue;
            }
 
            if (arr[i] - arr[j] == M) {
            	difference = M;
                break;
            }
 
            result = Math.min(difference, arr[i] - arr[j]);
            j++;
        }
 
        bw.write(result + "\n");
        bw.flush();
        bw.close();
        br.close();
    }

}
