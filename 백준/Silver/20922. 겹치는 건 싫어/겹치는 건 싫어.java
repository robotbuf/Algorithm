import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        int[] arr = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        int[] visited = new int[100001];

        int left = 0;
        int ans = 0;

        for (int right = 0; right < n; right++) {
            int cur = arr[right];
            visited[cur]++;
            
            while (visited[cur] > k) {
                visited[arr[left]]--;
                left++;
            }
            
            int windowSize = right - left + 1;
            if (windowSize > ans) {
                ans = windowSize;
            }
        }
        System.out.println(ans);
    }
}
