#ifndef __MAX_SUB__PROTOCOL__
#define  __MAX_SUB__PROTOCOL__
#ifdef WINDOWSCODE
#else
#include <dirent.h>
#endif
#include <fstream>
#include <string> 
#include <iostream>
#include <map>
#include <iostream> 
#include <algorithm>
#include <vector> 
#include <iterator>  
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

using namespace std;

class max_sub_protocol{
private:
		map<int, int> data;
public:
	max_sub_protocol();
	int getMax(int main_function);
private:
	int init();

};

#endif //__MAX_SUB__PROTOCOL__
