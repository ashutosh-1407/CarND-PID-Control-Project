#include "PID_throttle.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID_V::PID_V() {}

PID_V::~PID_V() {}

void PID_V::Init(double Kp_, double Ki_, double Kd_, bool flag) {
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
    vel_prev = 0.0;
  }
}

void PID_V::UpdateError(double vel) {
  /**
   * TODO: Update PID errors based on cte.
   */
  
  p_error = vel - 30;
  i_error+=vel;
  d_error = vel - vel_prev;
  vel_prev = vel;

}

double PID_V::TotalError(std::vector<double> &p) {
  /**
   * TODO: Calculate and return the total error
   */
  
  return - p[0] * p_error - p[1] * i_error - p[2] * d_error ;  // TODO: Add your total error calc here!
}