package algorithm_java;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;
//백으로 뒤집는 경우와 흑으로 뒤집는 경우를 각각 세서 최솟값을 구한다.
public class N13413 {

    public static void main(String [] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;// = new StringTokenizer(br.readLine());
        final int NUMBER_OF_TESTCASE = Integer.parseInt(br.readLine());
        for(int i=0;i<NUMBER_OF_TESTCASE;i++) {
            int dataLength = Integer.parseInt(br.readLine());
            int transWCount = 0,
                transBCount = 0;
            
            String start = br.readLine(),
                   want = br.readLine();
            
            for(int k=0;k<dataLength;k++) {
                if(start.charAt(k) != want.charAt(k)) {
                    if(start.charAt(k) == 'W') transBCount++;
                    else transWCount++;
                }
            }
            
            if(transBCount >= transWCount) sb.append(transBCount); 
            else sb.append(transWCount);
            
            sb.append("\n"); 
            
        }
        
        bw.write(sb.toString());
        
        bw.flush();
        br.close();
        bw.close();
        
    }

}
