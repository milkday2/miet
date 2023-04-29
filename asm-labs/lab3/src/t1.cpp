#include <bitset>
#include <iomanip>
#include <iostream>


void print16(void *p) {
  // format: hex bin unsigned signed
  unsigned short *ushrt = reinterpret_cast<unsigned short *>(p);
  short *shrt = reinterpret_cast<short *>(p);
  std::cout << std::setfill('0') << std::setw(4) << std::hex << *ushrt << ' '
            << std::bitset<16>(*ushrt) << ' '
            << std::setfill(' ') << std::setw(6) << std::dec << *ushrt << ' ' 
            << std::setfill(' ') << std::setw(6) << std::dec << *shrt << '\n';
}

void print32(void *p) {
  // format: hex bin unsigned signed float.5 float_scientific
  unsigned int *uint = reinterpret_cast<unsigned int *>(p);
  int *sint = reinterpret_cast<int *>(p);
  float *f = reinterpret_cast<float *>(p);
  std::cout << std::setfill('0') << std::setw(8) << std::hex << *uint << ' '
            << std::bitset<32>(*uint) << ' '
            << std::setfill(' ') << std::setw(10) << std::dec << *uint << ' '
            << std::setfill(' ') << std::setw(10) << std::dec << *sint << "  "
            << std::fixed << std::setprecision(5)
            << *f << ' ' << std::scientific << *f << '\n';
}
