#include "twiddle.h"
#include <numeric>

twiddle::twiddle() {}

twiddle::~twiddle() {}

std::vector<double> twiddle::tune_params(PID &pid, std::vector<double> &p, std::vector<double> &dp) {
  
//   double threshold = 0.001;
  double best_error = pid.TotalError(p);
//   double total = std::accumulate(p.begin(), p.end(), 0);
  
//   while (total > threshold) {
    for(unsigned int i=0; i<p.size(); ++i) {
      p[i]+=dp[i];
      double error = pid.TotalError(p);
      if (error < best_error) {
        best_error = error;
        dp[i]*=1.1;
      }
      else {
        p[i]-=2*dp[i];
        if (p[i] < 0) {
          p[i] = 0;
        }
        error = pid.TotalError(p);
        if (error < best_error) {
          best_error = error;
          dp[i]*=1.1;
        }
        else {
          p[i]+=dp[i];
          dp[i]*=0.9;
        }
      }
//     total = std::accumulate(p.begin(), p.end(), 0);
    }
//   }
  
  return p;
}