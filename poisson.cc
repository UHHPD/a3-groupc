#include<iostream>
#include<fstream>
#include<vector>
#include<cmath>
using namespace std;
 
double poisson(double mu, int k) {
    double b = k;
    double a = pow(mu, b)*exp(-mu)/tgamma(b+1);
    return a;
  }

  int main() {
    int a;
    std::ifstream fin("datensumme.txt");
    std::vector<int> zaehler(11);
    std::ofstream fout("histpoi.txt");
    for(unsigned int k = 0; k < 234; ++k) {
      fin >> a;
      zaehler[a] +=1;
      // cout << a;
      /* if(k < zaehler.size()){
      zaehler[k] = a;
        }
      else {
        zaehler.push_back(a);
      }*/
    }
    for(unsigned int k = 0; k < zaehler.size (); ++k) {
      fout << k << " " << zaehler[k] << " " << 234*poisson(3.11538, k) << std::endl;
      
    }
  }
 