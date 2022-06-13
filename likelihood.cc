#include<iostream>
#include<fstream>
#include<vector>
#include<cmath>
using namespace std;

double prob(std::vector<int> daten, double mu){
  double tlikely = 1;
  for(int k : daten){
    double likely = pow(mu, k)*exp(-mu)/tgamma(k+1);
    tlikely = tlikely*likely;
  }
  return tlikely;
}
double prob2(std::vector<int> daten){
  double tlikely = 1;
  for(int k : daten){
    double likely = pow(k, k)*exp(-k)/tgamma(k+1);
    tlikely = tlikely*likely;
  }
  return tlikely;
}

int main() {
    int a;
    std::ifstream fin("datensumme.txt");
    std::vector<int> daten;
    /*std::ofstream fnout("likelihood.txt");
    std::ofstream flout("nll.txt");
    std::ofstream fdout("deltanll.txt");  */
    for(unsigned int k = 0; k < 234; ++k) {
      fin >> a;
      // cout << a;
      daten.push_back(a);
    }
  // cout << prob(daten, 3.11538);
  /*for(double j = 0; j < 6; j += 0.001){
    fnout << j << " " << prob(daten, j) << std::endl;
    flout << j << " " << -2*log(prob(daten, j)) << std::endl;
    fdout << j << " " << -2*log(prob(daten, j)) -2*log(prob(daten, 3.11538)) << std::endl;
  }*/
  double V = -2*log(prob(daten, 3.116)/prob2(daten));
  cout << V;
  double z = V-233;
  z = z/sqrt(466);
  cout << z;
  }