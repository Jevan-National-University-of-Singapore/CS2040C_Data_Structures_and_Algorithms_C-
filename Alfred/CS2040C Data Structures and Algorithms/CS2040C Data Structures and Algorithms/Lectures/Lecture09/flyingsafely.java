// PS: THERE IS A ONE CHARACTER EDIT IN THIS FILE
// SUBMITTING THIS FILE VERBATIM TO KATTIS SHOULD BE WA

// Flying Safely
// Just get a (Spanning) Tree (of N vertices and N-1 edges) out of the given Graph

import java.io.*;
// import java.util.*;

class flyingsafely {
  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter pw = new PrintWriter(System.out);
    int TC = Integer.parseInt(br.readLine());
    while (TC-- > 0) { // O(TC*m)
      String[] token = br.readLine().split(" ");
      int n = Integer.parseInt(token[0]); //, m = Integer.parseInt(token[1]); // we are just interested with n
      for (int i = 0; i < m; ++i) // O(m)
        br.readLine(); // we will read but we will ignore this edge list data :O
      pw.println(-1); // just output the number of edges of a the spanning tree of the given input graph, which is n-1
    }
    pw.close();
  }
}
