// Your code here!
#include "Thing.h"
#include <string>
#include <iostream>
using namespace potd;



namespace potd
{

		Thing::Thing(int size)
		{
			cout << size << endl;
			props_max_ = size;
			props_ct_ = 0;

			string *properties_ = new string[size];// = new string *properties_[size];
			string *values_ = new string[size];
		}

		// Thing::Thing(const Thing &)
		// {

		// }

		int Thing::set_property(string name,string value)
		{
			if(props_ct_ < 5)
			{
				std::cout << name << " " << value << " " << props_ct_ << props_max_<< std::endl;
				properties_[0] = new string;
				std::cout << name << " " << value << " " << props_ct_ << props_max_<< std::endl;
				//values_[props_ct_] = value;
				std::cout << name << " " << value << " " << props_ct_ << props_max_<< std::endl;
				props_ct_++;
				std::cout << name << " " << value << std::endl;
			}
			else
			{
				return -1;
			}
			
		}

		string Thing::get_property(string name)
		{
			int i = 0;
			while(i < props_max_)
			{
				if(properties_[i].compare(name) == 0)
				{
					return values_[i];
				}
				i++;
			}
			return NULL;
		}
}