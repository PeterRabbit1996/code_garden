#include "TString.h"
#include <string>

template <typename T>
T stringJoint(T a, T b)
{
	return (std::string(a) + std::string(b));
}