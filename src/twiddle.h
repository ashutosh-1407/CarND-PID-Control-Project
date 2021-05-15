#ifndef TWIDDLE_H
#define TWIDDLE_H
#include "PID.h"
#include <vector>

class twiddle {
  public:
    twiddle();
    virtual ~twiddle();
    std::vector<double> tune_params(PID &pid, std::vector<double> &p, std::vector<double> &dp);
};

#endif /* TWIDDLE_H */