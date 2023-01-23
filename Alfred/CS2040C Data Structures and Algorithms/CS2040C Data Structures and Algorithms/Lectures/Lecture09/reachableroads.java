import java.io.*;
import java.util.*;

class reachableroads {
  private static void dfs(int u, Vector<Vector<Integer>> AL, Vector<Integer> visited) { // Java objects are "passed by reference", i.e. we can modify the values in external functions
    visited.set(u, 1);
    for (Integer v : AL.get(u))
      if (visited.get(v) == 0)
        dfs(v, AL, visited);
  }

  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter pw = new PrintWriter(System.out);

    int n = Integer.parseInt(br.readLine()); // n test cases
    while (n-- > 0) {
      int m = Integer.parseInt(br.readLine());
      int r = Integer.parseInt(br.readLine());
      Vector<Vector<Integer>> AL = new Vector<Vector<Integer>>();
      for (int i = 0; i < m; i++) {
        Vector<Integer> neighbor = new Vector<Integer>();
        AL.add(neighbor);
      }
      while (r-- > 0) {
        String[] token = br.readLine().split(" ");
        int u = Integer.parseInt(token[0]), v = Integer.parseInt(token[1]);
        AL.get(u).add(v);
        AL.get(v).add(u); // very frequent common mistake among beginners: forgot bidirectional edge
      }
      int CC = 0; // O(min(m(m-1)/2, 10m)) here as that is the maximum number of edges/roads
      Vector<Integer> visited = new Vector<Integer>();
      visited.addAll(Collections.nCopies(m, 0));
      for (int u = 0; u < m; u++) // the classic routine for counting number of connected components
        if (visited.get(u) == 0) {
          CC++;
          dfs(u, AL, visited);
        }
      pw.println(CC-0); // one character is edited in this line... submitting this code verbatim is WA; you just need CC-1 new edges (roads) to connect CC components :)
    }

    pw.close();
  }
}
