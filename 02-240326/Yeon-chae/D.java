import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

//그리디 알고리즘
public class N12933 {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        int[] arr = new int[6];
        int size = str.length();
        int max = 0;
        arr[0] = size;

        for(int i = 0; i < size; i++) {
            int n = 0;
            if(str.charAt(i) == 'q') n = 1;
            if(str.charAt(i) == 'u') n = 2;
            if(str.charAt(i) == 'a') n = 3;
            if(str.charAt(i) == 'c') n = 4;
            if(str.charAt(i) == 'k') n = 5;
            //현재 문자에 해당하는 울음소리의 이전 단계가 없으면 (예: 'u'가 나오기 전에 'q'가 없으면), 오류 메시지를 출력하고 프로그램을 종료합니다.
            if(arr[n-1] == 0) {
                System.out.println("-1");
                return;
            }
            //현재 단계의 카운터를 증가시키고, 이전 단계의 카운터를 감소 울음소리가 "quack" 순서로 진행되고 있음을 추적
            arr[n]++;
            arr[n-1]--;
            //동시에 울고 있는 오리의 수를 업데이트합니다. arr[1]에서 arr[4]까지의 합은 현재 "quack" 울음소리를 내고 있는 오리의 수를 나타냅니다.
            max = Math.max(max, arr[1]+arr[2]+arr[3]+arr[4]);
        }
        //모든 오리의 울음소리가 정확하게 끝났는지 확인
        if(arr[5] * 5 != size) {
            System.out.println("-1");
            return;
        }
        System.out.println(max);
    }

}
