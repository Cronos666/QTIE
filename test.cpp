#include <iostream>
#include <complex>
#include <Eigen/Dense>
#include "dirac.h"
#include <cstdio>
#include <unistd.h>//sleep

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

/*
  FILE *gnuplot = popen("gnuplot", "w");
        fprintf(gnuplot, "bind Close 'exit gnuplot'\n");

        fprintf(gnuplot, "set xrange [*:*]\n");
        fprintf(gnuplot, "set yrange [*:*]\n");
        fprintf(gnuplot, "set zrange [*:*]\n");

        fprintf(gnuplot, "set xlabel 'Re'\n");
        fprintf(gnuplot, "set ylabel 'Im'\n");
        fprintf(gnuplot, "set zlabel 'Prob'\n");
        fprintf(gnuplot, "set view 60, 45\n");


  std::vector<std::array<double, 3>> pts;
  double dt=0;
  while (dt<100) {
    //std::cout<<dt<<"; "<<v.ket()[0].real()<<"; "<<v.ket()[1].real()<<"\n\n";
    dt+=0.1;
    v.set(0,v.ket()[0]+dt*(1.0+0.5i));
    v.norm();
    auto prob=v.bra()*v.ket();
    double val=prob[0].real();

    
    pts.push_back({v.ket()[0].real(), v.ket()[1].real(), val});
    fprintf(gnuplot, "set title 'Step %f'\n", dt);
    fprintf(gnuplot, "splot '-' with linespoints pt 7 notitle\n");
    for (const auto& p : pts) {
        fprintf(gnuplot, "%f %f %f\n", p[0], p[1], p[2]);
    }
    fprintf(gnuplot, "e\n");
    fflush(gnuplot);
    usleep(50000);
  }  
 
  pclose(gnuplot);
  */
  return 0;
}
