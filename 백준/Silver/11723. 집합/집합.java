import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        
        int n = Integer.parseInt(br.readLine());
        int mask = 0;
        while (n-- > 0) {
            String line = br.readLine();
            StringTokenizer st = new StringTokenizer(line);
            String cmd = st.nextToken();
            if (cmd.equals("add")) {
                int x = Integer.parseInt(st.nextToken());
                mask |= (1 << (x - 1));
            } else if (cmd.equals("remove")) {
                int x = Integer.parseInt(st.nextToken());
                mask &= ~(1 << (x - 1));
            } else if (cmd.equals("check")) {
                int x = Integer.parseInt(st.nextToken());
                sb.append((mask & (1 << (x - 1))) != 0 ? '1' : '0').append('\n');
            } else if (cmd.equals("toggle")) {
                int x = Integer.parseInt(st.nextToken());
                mask ^= (1 << (x - 1));
            } else if (cmd.equals("all")) {
                mask = (1 << 20) - 1;
            } else if (cmd.equals("empty")) {
                mask = 0;
            }
        }
        System.out.print(sb);
        br.close();
    }
}