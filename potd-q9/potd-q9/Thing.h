#pragma once
using namespace std;
#include <string>

namespace potd {
  class Thing {
  public:
    Thing(int);
    
    Thing(const Thing &);
    
    Thing & operator=(const Thing &);
    
    ~Thing();

    int set_property(string,string);
    std::string get_property(string);

  private:

    void _copy(const Thing &);
    void _destroy();
    
    std::string *properties_;
    std::string *values_;
    int props_ct_;
    int props_max_;
  };
}
