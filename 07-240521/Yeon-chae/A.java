package algorithm_java;

import java.util.*;
import java.io.*;
//백트래킹 -DFS 활용
public class N15655 {

	public static int N, M;
	public static boolean visited[];
	public static int arr[], result[];
	public static StringBuilder sb = new StringBuilder();
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		arr = new int[N];
		st = new StringTokenizer(br.readLine(), " ");
		for(int i=0; i<N; i++)
			arr[i] = Integer.parseInt(st.nextToken());
		
		Arrays.sort(arr);
		
		visited = new boolean[N];
		result = new int[M];
		DFS(0, 0);
		
		System.out.println(sb);
	}
	
	public static void DFS(int depth, int start) {
		if(depth == M) {
			for(int val : result)
				sb.append(val).append(" ");
			
			sb.append('\n');
			return;
		}
		
		for(int i=start; i<N; i++) {
			if(!visited[i]) {
				visited[i] = true;
				result[depth] = arr[i];
				DFS(depth + 1, i);
				visited[i] = false;
			}
		}
	}
}
