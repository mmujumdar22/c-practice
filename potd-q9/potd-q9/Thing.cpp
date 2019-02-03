// Your code here!
#include "Thing.h"
#include <string>
#include <iostream>
using namespace potd;
using namespace std;



namespace potd
{

		Thing::Thing(int size)
		{
			cout << size << endl;
			props_max_ = size;
			props_ct_ = 0;

			string *properties_ = new string[size];// = new string *properties_[size];
			string *values_ = new string[size];
			std::cout << __LINE__<<endl;
			properties_[0] = "0";
			properties_[1] = "1";
			
			values_[0] = "0";
			values_[0] = "1";

			std::cout << __LINE__<<endl;
		}

		Thing::Thing(const Thing &thing2)
		{
			_copy(thing2);
			// props_max_ = thing2.props_max_;
			// props_ct_ = thing2.props_ct_;

			// properties_ = thing2.properties_;
			// values_ = thing2.values_;
		}

    	Thing & Thing::operator=(const Thing &thing2)
    	{
    		props_max_ = thing2.props_max_;
			props_ct_ = thing2.props_ct_;

			properties_ = thing2.properties_;
			values_ = thing2.values_;

			return *this;
    	}

		Thing::~Thing()
		{
			_destroy();
		}

		int Thing::set_property(string name,string value)
		{
			if(props_ct_ < 5)
			{
				std::cout << name << " " << value << " " << props_ct_ << props_max_<< std::endl;
				properties_[props_ct_] = new string(); //= "&name";
				std::cout << name << " " << value << " " << props_ct_ << props_max_<< std::endl;
				//values_[props_ct_] = value;
				std::cout << name << " " << value << " " << props_ct_ << props_max_<< std::endl;
				props_ct_++;
				std::cout << name << " " << value << std::endl;
				return 0;
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
		void Thing::_copy(const Thing &thing2)
		{
	
			props_max_ = thing2.props_max_;
			props_ct_ = thing2.props_ct_;

			properties_ = new string [props_max_];
			for (int j = 0; j < props_ct_; j++)
			{
				properties_[j] = thing2.properties_[j];
			}
			
			values_ = new string [props_max_];
			for (int k = 0; k < props_ct_; k++)
			{
				values_[k] = thing2.values_[k];
			}			
			values_ = thing2.values_;		
		}
		void Thing::_destroy()
		{
			delete [] properties_;
			delete [] values_;
		}
}