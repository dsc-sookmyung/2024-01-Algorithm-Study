package algorithm_java;

import java.util.*;
import java.io.*;
//DP활용
public class N2229 {
	//dp[i] = i번째 학생까지 '포함'했을 때 조가 잘 짜여진 정도의 최댓값
	public static void main(String[] args) throws Exception {	
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		int[] arr = new int[N];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		int[] dp = new int[N+1];
		
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j < i; j++) { // j = i와 같은팀인 사람들 중 첫번째 멤
				dp[i] = Math.max(dp[i],dp[j-1] + groupScore(j,i,arr));
			}
		}
		System.out.println(dp[N]);
	}
	
	public static int groupScore(int startIdx, int endIdx, int[] arr) {
		int maxVal = Integer.MIN_VALUE;
		int minVal = Integer.MAX_VALUE;
		for (int i = startIdx-1; i <= endIdx-1; i++) {
			maxVal = Math.max(arr[i], maxVal);
			minVal = Math.min(arr[i], minVal);
		}
		return maxVal - minVal;
	}
}
