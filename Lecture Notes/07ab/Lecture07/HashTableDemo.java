import java.io.*;
import java.util.*;

class HashTableDemo {
  private static int l(int i) { return i<<1; } // 2*i
  private static int r(int i) { return (i<<1)+1; } // (2*i)+1

  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter pw = new PrintWriter(System.out);

    pw.println("Our own Hash Table with Separate Chaining collision resolution technique");
    BasicHashTable ht = new BasicHashTable();
    pw.println(ht.IsEmpty()); // should be true
    ht.Insert("STEVEN", 77);
    pw.println(ht.IsEmpty()); // should be false
    ht.Insert("STEVEN", 36); // will update instead of creating a new one
    ht.Insert("GRACE", 35);
    ht.Insert("JANE", 7);
    ht.Insert("JOSHUA", 4);
    ht.Insert("JEMIMAH", 1);
    pw.println(ht.Search("STEVEN")); // should be 36 (not 77, it has been overwritten)
    pw.println(ht.Search("GRACE")); // should be 35
    pw.println(ht.Search("STRANGER")); // should be -1 (does not exist)
    ht.Remove("STEVEN");
    pw.println(ht.Search("STEVEN")); // should be -1 now (has just been deleted)
    pw.println(ht.Search("GRACE")); // should remain 35
    pw.println(ht.Search("JANE")); // should be 7
    ht.Remove("JANE");
    pw.println(ht.Search("JANE")); // should be -1 now (has just been deleted)

    pw.println("Java HashMap version");
    HashMap<String, Integer> mapper = new HashMap<String, Integer>();
    pw.println(mapper.isEmpty()); // should be true
    mapper.put("STEVEN", 77);
    pw.println(mapper.isEmpty()); // should be false
    mapper.put("STEVEN", 36); // will update instead of creating a new one
    mapper.put("GRACE", 35);
    mapper.put("JANE", 7);
    mapper.put("JOSHUA", 4);
    mapper.put("JEMIMAH", 1);
    pw.println(mapper.get("STEVEN")); // should be 36 (not 77, it has been overwritten)
    pw.println(mapper.get("GRACE")); // should be 35
    pw.println(mapper.get("STRANGER") == null); // should be true ("STRANGER" does not exist)
    mapper.remove("STEVEN");
    pw.println(mapper.get("STEVEN") == null); // should be true now (has just been deleted)
    pw.println(mapper.get("GRACE")); // should remain 35
    pw.println(mapper.get("JANE")); // should be 7
    mapper.remove("JANE");
    pw.println(mapper.get("JANE") == null); // should be true now (has just been deleted)

    pw.close();
  }
}

class StringInt {
  public String s;
  public Integer i;
  public StringInt(String _s, Integer _i) {
    s = _s;
    i = _i;
  }
}

class BasicHashTable { // this is an attempt to emulate unordered_map<string, int> mapper;
  private static final int M = 13; // M = table size is a prime number, rather small, for illustration purpose only, generally make M > 2*K where K is the maximum number of keys that you will likely need for your application

  // the 'easiest' and most robust Hash Table is actually the one with Separate Chaining collision resolution technique
  private LinkedList<StringInt>[] underlying_table = new LinkedList[M]; // you can change list to vector :O

  // from https://visualgo.net/en/hashtable?slide=4-7
  private int hash_function(String v) { // assumption 1: v uses ['A'..'Z'] only
    int sum = 0;                // assumption 2: v is a short string
    for (int i = 0; i < v.length(); i++) {
      char c = v.charAt(i); // for each character c in v
      sum = ((sum*26)%M + (c-'A'+1))%M; // M is table size
    }
    return sum;
  }

  public BasicHashTable() {
    for (int i = 0; i < M; i++)
      underlying_table[i] = new LinkedList<StringInt>(); // clear the linked list
  }

  public void Insert(String key, int value) { // to emulate mapper[key] = value
    Boolean contains_key = false;
    for (StringInt key_value : underlying_table[hash_function(key)])
      if (key_value.s == key) { // if there is an existing key
        contains_key = true;
        key_value.i = value; // update the satellite data
      }
    if (!contains_key) // no previous key before
      underlying_table[hash_function(key)].add(new StringInt(key, value)); // just append at the back
  }

  public int Search(String key) { // to emulate mapper[key]
    for (StringInt key_value : underlying_table[hash_function(key)]) // O(k), k is the length of this list
      if (key_value.s == key) // if there is an existing key
        return key_value.i; // return this satellite data
    return -1; // no previous key before, return a symbol to say such key does not exist
  }

  public void Remove(String key) { // to emulate mapper.erase(key)
    LinkedList<StringInt> row = underlying_table[hash_function(key)]; // get the reference of the row
    for (StringInt key_value : underlying_table[hash_function(key)]) // O(k), k is the length of this list
      if (key_value.s == key) { // if there is an existing key
        row.remove(key_value); // erase this (key, value) pair from this vector
        break; // do not do anything else
      }
    // we do nothing if key is not actually found
  }

  public Boolean IsEmpty() {
    int total = 0;
    for (int i = 0; i < M; i++)
      total += underlying_table[i].size();
    return total == 0;
  }
}
