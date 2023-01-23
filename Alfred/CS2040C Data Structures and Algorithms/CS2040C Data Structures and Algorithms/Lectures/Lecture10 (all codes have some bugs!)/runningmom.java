// there are a few 1 character bugs in this code, submitting it verbatim will be WA

import java.io.*;
import java.util.*;

class runningmom {
  // need these to be global for simpler code... use with caution
  // passing these heavy objects as function parameters are not advisable
  private static HashMap<String, Vector<String>> AL = new HashMap<String, Vector<String>>(); // to make the explanation simple, imagine this AL as Hash Table with Separate Chaining technique
  private static HashMap<String, Integer> status; // as now we need to differentiate not just UNVISITED/VISITED, but UNVISITED/EXPLORED/FULLY-VISITED, we need to map the vertex name (string) into an integer status 0/1/2
  private static Boolean back_edge_found;
  private static PrintWriter pw;

  // PS: note that there are other (faster) solution... map city names to integer indices [0..V-1], then work with the faster integer indices again

  private static void dfs(String city) {
    // pw.printf("MoM at newly EXPLORED city %s\n", city);
    status.put(city, 1); // EXPLORED
    if (AL.get(city) != null) // if city is an isolated vertex
      for (String neighbor : AL.get(city)) {
        // pw.printf("MoM trying to go to city %s\n", neighbor);
        if (status.get(neighbor) == null) // going to an unvisited neighbor
          dfs(neighbor);
        else if (status.get(neighbor) == 1) // { // going to an EXPLORED neighbor!!!
          // pw.printf("%s -> %s is part of a cycle, MoM is safe as he/she can cycle forever\n", city, neighbor);
          back_edge_found = true;
        // }
      }
    // pw.printf("MoM finished VISITING city %s fully\n", city);
    status.put(city, 1); // DONE/fully visited
  }

  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    pw = new PrintWriter(System.out);

    int n = Integer.parseInt(br.readLine());
    while (n-- > 0) {
      String[] token = br.readLine().split(" ");
      if (AL.get(token[0]) == null) {
        Vector<String> neighbor = new Vector<String>(); // create a new Adjacency List
        neighbor.add(token[1]);
        AL.put(token[0], neighbor);
      }
      else
        AL.get(token[0]).add(token[1]); // directed edge this time
    }

    while (true) {
      String origin = br.readLine();
      if (origin == null) break;
      back_edge_found = false;
      status = new HashMap<String, Integer>(); // clear visited flag for every test case
      dfs(origin);
      pw.printf("%s %s\n", origin, (!back_edge_found ? "safe" : "trapped")); // if can reach a cycle (back_edge_found) starting from origin, MoM is safe
    }

    pw.close();
  }
}
