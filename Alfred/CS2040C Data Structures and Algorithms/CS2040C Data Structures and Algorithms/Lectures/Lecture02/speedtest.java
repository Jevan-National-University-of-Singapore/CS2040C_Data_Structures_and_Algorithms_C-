import java.io.*;

class speedtest {
  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter pw = new PrintWriter(System.out);

    long begin = System.currentTimeMillis();
    long counter = 0;
    int N = 100000; // try adding a few more zero digitS at the back of this variable to make your computer hangs...
    for (int i = 0; i < N; i++) { // O(c * N^2), c is 'small' if you leave line 16 commented, but c is BIG if you uncomment it
      // pw.printf("i = %d\n", i);
      // for (int j = 1; j < N; j*=2) { // O(log N)
      for (int j = 0; j < N; j++) { // O(N)
        counter++; // this operation is O(1), and fast, let's say 0.0000000001 s
        // but if you uncomment the next line, the same O(N^2) algorithm will be noticeably much slower
        // pw.printf(" counter = %d\n", counter); // this I/O operation is 'heavy', let's say 0.01s per printf statement...
      }
    }
    pw.printf("counter = %d, computed in = %fs\n", counter, (System.currentTimeMillis()-begin)/1000.0);

    pw.close();
  }
}
