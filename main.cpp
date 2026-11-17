#include <iostream>
#include <complex>
#include "dirac.h"

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
  
  return 0;
  return 0;
}
