// Shiritori
// easy
// code 2.52pm, submit 3.05pm (13m, AC, can be faster)

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);
  int N; cin >> N; cin.get();
  string previous_word; cin >> previous_word; --N; // read the first word
  int current_player = 2;
  unordered_set<string> has_been_called; has_been_called.insert(previous_word);
  bool fair_game = true;
  while (N--) {
    string current_word; cin >> current_word;
    if (current_word.front() != previous_word.back()) { // can't link the first char of current word with the last char of previous word
      cout << "Player " << current_player << " lost\n";
      fair_game = false;
      break;
    }
    if (has_been_called.find(current_word) != has_been_called.end()) { // lost also, Hash Table in action
      cout << "Player " << current_player << " lost\n";
      fair_game = false;
      break;
    }
    has_been_called.insert(current_word); // Hash Table in action
    previous_word = current_word;
    current_player = 3-current_player; // change player 2->1, 1->2 (cool technique for newbies)
  }
  if (fair_game) cout << "Fair Game\n";
  return 0;
}
