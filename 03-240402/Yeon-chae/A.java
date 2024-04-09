package algorithm_java;

import java.util.Scanner;
//이분탐색
public class N2417 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		long n=sc.nextLong();
		
		long start=0;
		long end=n;
		long min=Long.MAX_VALUE;
		

		while(start<=end) {
			long mid=(start+end)/2;
			long result=(long) Math.pow(mid, 2);
			

			if(result>=n) {
				min=mid;
				end=mid-1;
			}

			else 
				start=mid+1;
		}
		
		System.out.println(min);
	}

}
