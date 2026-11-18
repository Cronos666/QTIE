/*
 * QTIE - Quantum Time-dependent Isotope Engine 
 * Copyright (C) 2026 Kacper Śmieżewski
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

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
