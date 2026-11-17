#include <iostream>
#include <complex>
#include <Eigen/Dense>
#include "dirac.h"

using namespace Eigen;

int main (int argc, char *argv[]) {
  Dirac v={1.0,0.0 -1.0i,};

  std::cout<<"|v>: "<<v.ket()<<'\n';
  std::cout<<"<v|: "<<v.bra()<<"\n\n";

  std::cout<<"<v|v>:\n"<<v.bra()*v.ket()<<'\n';
  std::cout<<"|v><v|:\n"<<v.ket()*v.bra()<<"\n\n";

  v.norm();

  std::cout<<"|v>: "<<v.ket()<<'\n';
  std::cout<<"<v|: "<<v.bra()<<"\n\n";

  std::cout<<"<v|v>:\n"<<v.bra()*v.ket()<<'\n';
  std::cout<<"|v><v|:\n"<<v.ket()*v.bra()<<'\n';


  MatrixXcd m(2,2);
  m(0,0)=1.0;
  m(0,1)=1.0;
  m(1,0)=2.0;
  m(1,1)=0.0;
 
  
  std::cout<<"\nA: \n"<<m<<'\n';
  std::cout<<"A|v>: \n"<<m*v.ket()<<'\n';
  std::cout<<"A<v|: \n"<<v.bra()*m<<'\n';
  
  return 0;
}
