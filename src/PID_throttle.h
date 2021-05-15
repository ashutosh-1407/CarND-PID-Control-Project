#ifndef PID_V_H
#define PID_V_H
#include <vector>

class PID_V {
 public:
  /**
   * Constructor
   */
  PID_V();

  /**
   * Destructor.
   */
  virtual ~PID_V();

  /**
   * Initialize PID.
   * @param (Kp_, Ki_, Kd_) The initial PID coefficients
   */
  void Init(double Kp_, double Ki_, double Kd_, bool flag);

  /**
   * Update the PID error variables given cross track error.
   * @param cte The current cross track error
   */
  void UpdateError(double vel);

  /**
   * Calculate the total PID error.
   * @output The total PID error
   */
  double TotalError(std::vector<double> &p);

 private:
  /**
   * PID Errors
   */
  double p_error;
  double i_error;
  double d_error;
  double vel_prev;

  /**
   * PID Coefficients
   */ 
  double Kp;
  double Ki;
  double Kd;
};

#endif  // PID_V_H