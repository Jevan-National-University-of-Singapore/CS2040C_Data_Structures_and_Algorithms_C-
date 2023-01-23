// there is one character bug in this code, submitting it verbatim will give you Wrong Answer

import java.io.*;
import java.util.*; // ArrayList and Collections are here

class sortofsorting {
  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter pw = new PrintWriter(System.out);

    // the whole thing is O(N log N)
    Boolean FirstTestCase = true;
    while (true) {
      int N = Integer.parseInt(br.readLine());
      if (N == 0) break;
      ArrayList<String> names = new ArrayList<>(); // declare locally so that it is fresh per test case :D
      for (int i = 1; i < N; i++) { // O(N)
        String name = br.readLine();
        names.add(name); // O(1)
      }

      Collections.sort(names, new SortByFirstTwoCharacters()); // O(N log N), by default Collections.sort is already a stable sort as it uses Merge Sort
      // Collections.sort(names, (a, b) -> {
      //   return a.substring(0, 2).compareTo(b.substring(0, 2)); // lambda function :O, slightly slower than using a class that implements comparator
      // });
      // Arrays.sort is also stable

      if (!FirstTestCase) pw.printf("\n");
      FirstTestCase = false;
      for (String str : names) // O(N), I am using range-based for loop
        pw.printf("%s\n", str);
    }

    pw.close();
  }

  /*
  3
  Mozart
  Beethoven
  Bach
  5
  Hilbert
  Godel
  Poincare <-- look at Po    incare
  Ramanujan
  Pochhammmer <--   vs Po    chhammer
  0
  */

  static class SortByFirstTwoCharacters implements Comparator<String> { // slightly faster than using lambda function
    public int compare(String a, String b) {
      String first = a.substring(0, 2);
      String second = b.substring(0, 2);
      return first.compareTo(second);
    }
  }
}
