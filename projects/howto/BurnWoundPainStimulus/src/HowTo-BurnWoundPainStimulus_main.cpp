#include <iostream>

#include "HowTo-BurnWoundPainStimulus.h"


int main( int argc, char* argv[] )
{
  //HowToBurnWoundPainStimulus();
  std::string log = "./HowToBurnWound.log";
  BurnThread burn(log, 30.0);
  burn.FluidLoading();
}
