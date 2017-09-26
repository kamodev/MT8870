#include "Arduino.h"

#ifndef MT8870_h
#define MT8870_h

class MT8870
{
	public:
		MT8870(int Q1, int Q2, int Q3, int Q4, int STQ);
		int getDTMFValue();
		
	private:
		// All INT variables
		int _Q1;
		int _Q2;
		int _Q3;
		int _Q4;
		int _dtmf_key = 0;
		
		void decode();
};

#endif // MT8870_h
