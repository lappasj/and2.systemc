#include "systemc.h"
#include "stim.cpp"
#include "exor2.cpp"
#include "mon.cpp"

int sc_main(int argc, char* argv[])
{
  sc_signal<bool> ASig, BSig, FSig;

// a clock that has a positive edge directly a 0 ns
//  sc_clock TestClk("TestClock", 10, SC_NS,0.5);

// a clock that has a positive edge only at 10 ns 
  sc_clock TestClk("TestClock", 10, SC_NS,0.5, 10, SC_NS);

  stim Stim1("Stimulus");
  Stim1.A(ASig);
  Stim1.B(BSig);
  Stim1.Clk(TestClk);

  exor2 DUT("exor2");
  DUT.A(ASig);
  DUT.B(BSig);
  DUT.F(FSig);

  mon Monitor1("Monitor");
  Monitor1.A(ASig);
  Monitor1.B(BSig);
  Monitor1.F(FSig);
  Monitor1.Clk(TestClk);

  sc_start();  // run forever

  return 0;

}
