#ifndef DIRAC_H
#define DIRAC_H

#include <initializer_list>
#include <Eigen/Dense>
#include <complex>

using namespace Eigen;
using namespace std::complex_literals;

class Dirac {
private:
  VectorXcd vec;
  
public:
  //List constructor | example: Driac state = {0,1}
  Dirac(std::initializer_list<std::complex<double>> val) {
    vec.resize(val.size());
    Index i=0;
    for (const auto& v:val){
      vec(i)=v;
      i++;
    }
  }

  //Empty vec constructor | example 4qbit vec: Dirac empty_state(4)
  Dirac(Index size) : vec(VectorXcd::Zero(size)){
  }

  //getters
  const VectorXcd& ket() const{
    return vec;
  }

  auto bra() const {
    return vec.adjoint();
  }
  //setter
  void set(Index index, std::complex<double> val){
    vec(index)=val;
  }

  void norm(){
    vec.normalize();
  }

};
#endif //DIRAC_H
