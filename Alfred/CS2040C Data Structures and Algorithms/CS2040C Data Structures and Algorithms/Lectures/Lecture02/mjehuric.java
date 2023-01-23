// there is one character bug in this code, submitting it verbatim will give you Wrong Answer

import java.io.*;

class mjehuric {
  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter pw = new PrintWriter(System.out);

    int n = 4;
    int[] A = new int[n];
    String[] token = br.readLine().split(" ");
    for (int i = 0; i < n; i++) 
      A[i] = Integer.parseInt(token[i]);

    // simulate bubble sort
    // well, not really O(n^3) but we can say this is O(5^3 = 125) = O(1) actually, as n is a constant 5...
    // most harder problems won't have that kind of 'tiny' n...
    for (int i = 0; i < n; i++)
      for (int j = 1; j < n; j++)
        if (A[j-1] > A[j]) {
          // swap(A[j], A[j-1]) with the next three lines
          int temp = A[j];
          A[j] = A[j-1];
          A[j-1] = temp;
          for (int k = 0; k < n; k++)
            pw.printf("%d ", A[k]); // notice that Kattis allows having extra ' ' (space) at the end of your lines... Mooshak will be strict and won't allow this
          pw.printf("\n");
        }

    pw.close();
  }
}
