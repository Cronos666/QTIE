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

#ifndef NUMET_H
#define NUMET_H

#include "Eigen/Core"
#include <stdexcept>
#include <Eigen/Dense>
#include <utility>

template <typename g_func>
Eigen::MatrixXcd numerov(
    const Eigen::Ref<const Eigen::VectorXcd>&y0,
    const Eigen::Ref<const Eigen::VectorXcd>&y1,
    g_func&& g_at_step,
    double dx,
    Eigen::Index n){
  
    if (y0.size() != y1.size() || y0.size() == 0) {
      throw std::invalid_argument("Err: inputs have different size or are empty.");
    }
    if (n < 2){
      throw std::invalid_argument("Err: there must be at least 2 steps.");
    }

    //Numerov's factor: h/12 
    const double scale= (dx*dx)/12.0; 
   
    
    Eigen::MatrixXcd results(y0.size(),n);
    results.col(0)=y0;
    results.col(1)=y1;

    //precalculated (h/12)*g(x)
    Eigen::ArrayXcd prev_weight=scale*g_at_step(0).array();
    Eigen::ArrayXcd curr_weight=scale*g_at_step(1).array();
    Eigen::ArrayXcd next_weight(y0.size());

    for (Eigen::Index i=1; i<n-1; i++){
      next_weight=scale*g_at_step(i+1).array();
      
      auto prev_y = results.col(i-1).array();
      auto curr_y = results.col(i).array();

      results.col(i+1).array()=(2.0*(1.0-5*curr_weight)*curr_y - (1.0+prev_weight)*prev_y)/(1.0+next_weight);
      
      //no copy data swap
      std::swap(prev_weight, curr_weight);
      std::swap(curr_weight, prev_weight);

    }


  return results;    
};

#endif //NUMET_H
