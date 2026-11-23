#include <iostream>
#include <complex>
#include <Eigen/Dense>
#include "Eigen/Core"
#include "dirac.h"
#include "numet.h"
#include <cstdio>
#include <unistd.h>//sleep
#include <cmath>


using namespace Eigen;

void dirac_demo(){

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

};


void numerov_demo(){
  const double dt=0.01;
  const Eigen::Index steps=1001;

  Dirac angular_freq={1.0,M_PI/2, M_PI};
  Dirac y0={1.0,1.0,1.0};
  Dirac y1={cos(1.0*dt),cos(M_PI*dt/2),cos(M_PI*dt)};

  Eigen::VectorXcd omega_sq = angular_freq.ket().cwiseProduct(angular_freq.ket());
  auto func = [&](Eigen::Index) -> const Eigen::VectorXcd& { return omega_sq; };

  Eigen::MatrixXcd U = numerov(y0.ket(), y1.ket(), func, dt, steps);

  const double t_end = (steps - 1) * dt;
  Eigen::VectorXcd exact = (angular_freq.ket().array() * t_end).cos().matrix();
  Eigen::VectorXcd numerical = U.col(steps - 1);

  std::cout << "\nNumerical (t = " << t_end << "):\n" << numerical << '\n';
  std::cout << "\nAnalytical (t = " << t_end << "):\n" << exact << '\n';
  std::cout << "\nMax absolute error: "
              << (numerical - exact).cwiseAbs().maxCoeff() << '\n';
};



int main (int argc, char *argv[]) {
  
  dirac_demo();

  numerov_demo();

  
  return 0;
}
