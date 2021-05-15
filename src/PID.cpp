#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_, bool flag) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */

  Kp = Kp_;
  Ki = Ki_;
  Kd = Kd_;
  if ( flag == true) {
    p_error = 0.0;
    i_error = 0.0;
    d_error = 0.0;
    cte_prev = 0.0;
  }
}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
  
  p_error = cte;
  i_error+=cte;
  d_error = cte - cte_prev;
  cte_prev = cte;

}

double PID::TotalError(std::vector<double> &p) {
  /**
   * TODO: Calculate and return the total error
   */
  
  return - p[0] * p_error - p[1] * i_error - p[2] * d_error ;  // TODO: Add your total error calc here!
}