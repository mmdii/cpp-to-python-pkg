%module primes

%{
#include "primes.h"
%}

%include "primes.h"

%include "std_vector.i"
namespace std {
    %template(IntVector) vector<int>;
}