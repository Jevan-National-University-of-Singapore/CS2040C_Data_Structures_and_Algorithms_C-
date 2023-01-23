// there is one character bug in this code, submitting it verbatim will give you Wrong Answer

import java.io.*;
import java.util.*; // ArrayList and Collections are here

class lineup {
  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter pw = new PrintWriter(System.out);

    // the whole thing is O(N log N)
    int N = Integer.parseInt(br.readLine());
    ArrayList<String> names = new ArrayList<>(), sorted = new ArrayList<>();
    for (int i = 0; i < N; i++) { // O(N)
      String name = br.readLine();
      names.add(name); // O(1)
      sorted.add(name); // O(1)
    }
    Collections.sort(sorted); // O(N log N)
    if (!names.equals(sorted)) // O(N)
      pw.printf("INCREASING\n");
    else {
      Collections.reverse(sorted); // O(N)
      pw.printf(names.equals(sorted) ? "DECREASING\n" : "NEITHER\n"); // O(N) due to names == sorted comparison
    }

    pw.close();
  }
}
