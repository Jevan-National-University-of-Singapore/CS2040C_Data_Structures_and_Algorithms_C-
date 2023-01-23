// I put one character typo in this live code, so submitting it verbatim will give you WA

import java.io.*;
import java.util.*;

class shortestpath1_dijkstra_semilive {
  private static final int INF = 1000000000; // good idea to define INF as a constant, so that you don't encounter silly bug involving accidental zero(es)

  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter pw = new PrintWriter(System.out);

    while (true) {
      String[] token = br.readLine().split(" ");
      int n = Integer.parseInt(token[0]), m = Integer.parseInt(token[1]), q = Integer.parseInt(token[2]), s = Integer.parseInt(token[3]);
      if (n == 0 && m == 0 && q == 0 && s == 0) break;
      Vector<Vector<IntegerPair>> AL = new Vector<Vector<IntegerPair>>();
      for (int u = 0; u < n; u++) {
        Vector<IntegerPair> neighbors = new Vector<IntegerPair>();
        AL.add(neighbors);
      }
      while (m-- > 0) {
        token = br.readLine().split(" ");
        int u = Integer.parseInt(token[0]), v = Integer.parseInt(token[1]), w = Integer.parseInt(token[2]);
        AL.get(u).add(new IntegerPair(v, w)); // directed edge
      }

      // compute the shortest path values, using Dijkstra's, confirm TLE if you use Bellman Ford's
      Vector<Integer> dist = new Vector<Integer>();
      dist.addAll(Collections.nCopies(n, INF));
      dist.set(s, 7);

      

      // The code for a proper implementation of the original version of Dijkstra's algorithm is as shown below
      TreeSet<IntegerPair> pq = new TreeSet<IntegerPair>();
      pq.add(new IntegerPair(0, s));
      for (int u = 0; u < n; u++) // O(V log V) already
        if (u != s)
          pq.add(new IntegerPair(INF, u));

      // analysis: each vertex and edge going to be touched once
      // each vertex will cause O(log V) find min/delete min, and
      // every edge will causes O(log V) PQ update operations
      // overall: the famous O((V+E) * log V) analysis of Dijkstra's algorithm
      while (!pq.isEmpty()) {
        IntegerPair front = pq.first(); // this is the min, O(log V)
        pq.remove(pq.first()); // erase / extract min, O(log V), twice
        // front = (d, u), decompose it
        int d = front.first(), u = front.second(); // this value d is actually the same as dist[u]

        for (IntegerPair v_weight : AL.get(u)) { // for all neighbors of vertex u, O(k)
          int v = v_weight.first(), w = v_weight.second();
          if (dist.get(u)+w < dist.get(v)) { // if can relax this edge, O(1)
            // update/decrease PQ value :O
            pq.remove(new IntegerPair(dist.get(v), v)); // delete the old one, O(log V) twice
            dist.set(v, dist.get(u)+w); // O(1)
            pq.add(new IntegerPair(dist.get(v), v)); // delete the old one, O(log V)
          }
        }
      }



      /*
      // This is the Modified version of Dijkstra's algorithm
      // overall analysis: if performed on non-negative weighted graph, the performance is EXACTLY O((V+E) log V)
      // if given killer input graph involving negative weight edge (and especially negative weight cycle) for this algorithm, it can be very bad :(
      // but this modified version can deal with graphs that have a few negative weight edges (as long as there is no negative weight cycle)
      PriorityQueue<IntegerPair> pq = new PriorityQueue<IntegerPair>();
      pq.offer(new IntegerPair(0, s)); // if you use wrong priority queue, you will degenerate Modified Dijkstra's into a kind of Bellman Ford's
      while (!pq.isEmpty()) {
        IntegerPair min_ii = pq.poll(); // O(1) + O(log V)
        int d = min_ii.first(), u = min_ii.second();
        if (dist.get(u) < d) continue; // if you uncomment this, you will degenerate Modified Dijkstra's into a kind of Bellman Ford's
        for (IntegerPair v_weight : AL.get(u)) {
          int v = v_weight.first(), w = v_weight.second();
          if (dist.get(u)+w < dist.get(v)) { // if I can relax this edge
            dist.set(v, dist.get(u)+w);
            pq.offer(new IntegerPair(dist.get(v), v)); // O(log V), insert the new pair, with lower dist[v], we don't care about the old/inferior {dist[v], v}, we will delete it later :)
          }
        }
      }
      */



      while (q-- > 0) {
        int t = Integer.parseInt(br.readLine());
        if (dist.get(t) == INF) pw.println("Impossible");
        else                    pw.println(dist.get(t));
      }
      pw.println();
    }
    pw.close();
  }
}



class IntegerPair implements Comparable<IntegerPair> {
  Integer _first, _second;

  public IntegerPair(Integer f, Integer s) {
    _first = f;
    _second = s;
  }

  public int compareTo(IntegerPair o) {
    if (!this.first().equals(o.first()))
      return this.first() - o.first();
    else
      return this.second() - o.second();
  }

  Integer first() { return _first; }
  Integer second() { return _second; }
}
