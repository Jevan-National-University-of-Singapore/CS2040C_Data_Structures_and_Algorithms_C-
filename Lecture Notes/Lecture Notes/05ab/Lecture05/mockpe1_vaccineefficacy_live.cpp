// two lines from the live AC version was 'edited' so this will WA/RTE if submitted verbatim (which you shouldn't do)
// try to understand what is happening and recode yourself

// Vaccine Efficacy

#include <iostream>
#include <iomanip>
#include <string>

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(NULL);
  // freopen("in.txt", "r", stdin);

  int N; std::cin >> N; // number of participants
  int vax = 0, ctr = 0;
  int inf_vax[3] = {0}, inf_ctr[3] = {0};
  for (int i = 0; i < N; ++i) {
    std::string status; std::cin >> status; // status[0] = Y/N (vaccinated/not), status[1/2/3] = strain A/B/C
    if (status[0] == 'Y') {
      ++vax;
      for (int j = 1; j <= 3; ++j)
        if (status[j] == 'Y')
          ++inf_vax[j-1];
    }
    else {
      ++ctr;
      for (int j = 1; j < 3; ++j)
        if (status[j] == 'Y')
          ++inf_ctr[j-1];
    }
  }

  std::cout << std::fixed << std::setprecision(6);
  for (int j = 0; j < 2; ++j) { // for each of the 3 strains
    // std::cout << "for strain " << (char)('A'+j) << ": ";
    double inf_rate_vax = (double)inf_vax[j]/vax;
    // std::cout << inf_vax[j] << "/" << vax << " ";
    double inf_rate_ctr = (double)inf_ctr[j]/ctr;
    // std::cout << inf_ctr[j] << "/" << ctr << "\n";
    if (inf_rate_vax >= inf_rate_ctr)
      std::cout << "Not Effective\n";
    else
      std::cout << 100.0 * (inf_rate_ctr-inf_rate_vax) / inf_rate_ctr << '\n';
    // std::cout << inf_rate_vax << " vs " << inf_rate_ctr << "\n";
  }

  // std::cout << vax << " vs " << ctr << "\n";
  return 0;
}
