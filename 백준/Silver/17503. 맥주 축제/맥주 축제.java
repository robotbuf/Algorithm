import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    private static class Beer implements Comparable<Beer> {
        int v;  
        int c;  
        public Beer(int v, int c) {
            this.v = v;
            this.c = c;
        }
        
        @Override
        public int compareTo(Beer o) {
            return Integer.compare(this.c, o.c);
        }
    }
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());  // 마실 일수 = 선택해야 하는 맥주 개수
        long M = Long.parseLong(st.nextToken());   // 최소 선호도 합
        int K = Integer.parseInt(st.nextToken());  // 전체 제공 맥주 종류 수
        
        Beer[] beers = new Beer[K];
        for (int i = 0; i < K; i++) {
            st = new StringTokenizer(br.readLine());
            int v = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            beers[i] = new Beer(v, c);
        }
        
        Arrays.sort(beers);
        
        
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        long sum = 0L;
        int answer = -1;
        
        for (int i = 0; i < K; i++) {
            
            pq.offer(beers[i].v);
            sum += beers[i].v;
            
            if (pq.size() > N) {
                sum -= pq.poll();
            }
            
            if (pq.size() == N && sum >= M) {
                answer = beers[i].c;  
                break;
            }
        }
        
        System.out.println(answer);
    }
}

