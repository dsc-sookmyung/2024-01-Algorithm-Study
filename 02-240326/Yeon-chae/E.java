
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

//겹치는건 너무 싫어 , 투포인터
public class N20922 {
	public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	public static int N,K;
	public static int[] A;
	public static int[] nums = new int[100001];

	public static void main(String[] args) throws IOException {
	    input();
	    process();
	}

	public static void input() throws IOException {
	    StringTokenizer st = new StringTokenizer(br.readLine());
	    N = Integer.parseInt(st.nextToken());
	    K = Integer.parseInt(st.nextToken());

	    A = new int[N+1];
	        
	    st = new StringTokenizer(br.readLine());
	    for(int i=1; i<=N; i++) A[i] = Integer.parseInt(st.nextToken());
	}

	public static void process() {
	   int R=0, cnt = 0;
	        
	    for(int L=1; L<=N; L++) {
	        // 왼쪽 포인터가 오른쪽으로 이동할 때마다 
	        // 빠지는 수열의 카운트를 빼준다
	        nums[A[L-1]]--;

	        while(R+1<=N && nums[A[R+1]] < K) {
	            nums[A[++R]]++;
	        }

	        cnt = Math.max(cnt, R-L+1);
	    }

	    System.out.println(cnt);
	}

}
