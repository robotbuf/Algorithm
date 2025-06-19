import java.io.*;
import java.util.*;

public class Main {

    static int n, l, r;            
    static int[][] arr;           
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};
    static boolean[][] visited;    

    static class Point {
        int x, y;
        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }


    static class UnionInfo {
        List<Point> members;
        int sum;
        int count;
        public UnionInfo(List<Point> members, int sum, int count) {
            this.members = members;
            this.sum = sum;
            this.count = count;
        }
    }

    static UnionInfo bfs(int startRow, int startCol) {
        Queue<Point> q = new LinkedList<>();
        List<Point> union = new ArrayList<>();

        q.offer(new Point(startRow, startCol));
        visited[startRow][startCol] = true;

        int sum = arr[startRow][startCol];
        int count = 1;
        union.add(new Point(startRow, startCol));

        while (!q.isEmpty()) {  
            Point p = q.poll();
            int x = p.x;
            int y = p.y;

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

                if (!visited[nx][ny]) {
                    int diff = Math.abs(arr[x][y] - arr[nx][ny]);
                    if (diff >= l && diff <= r) {
                        visited[nx][ny] = true;
                        q.offer(new Point(nx, ny));
                        union.add(new Point(nx, ny));
                        sum += arr[nx][ny];
                        count++;
                    }
                }
            }
        }
        return new UnionInfo(union, sum, count);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        l = Integer.parseInt(st.nextToken());
        r = Integer.parseInt(st.nextToken());

        arr = new int[n][n];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        int days = 0;
        while (true) {
            visited = new boolean[n][n];
            boolean moved = false;

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (!visited[i][j]) {
                        UnionInfo info = bfs(i, j);
                        if (info.count > 1) {
                            int newVal = info.sum / info.count;
                            for (Point p : info.members) {
                                arr[p.x][p.y] = newVal;
                            }
                            moved = true;
                        }
                    }
                }
            }
            if (!moved) break;
            days++;
        }
        System.out.println(days);
    }
}
