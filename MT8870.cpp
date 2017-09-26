#include "Arduino.h"
#include "MT8870.h"

MT8870::MT8870(int Q1, int Q2, int Q3, int Q4, int STQ)
{
	// Set the pin modes
	pinMode(Q1, INPUT);
	pinMode(Q2, INPUT);
	pinMode(Q3, INPUT);
	pinMode(Q4, INPUT);
	pinMode(STQ, INPUT);
	
	// Setup the Interrupt pin
	attachInterrupt(digitalPinToInterrupt(STQ), MT8870::decode, LOW);
	
	// Keep track of the pin numbers
	_Q1 = Q1;
	_Q2 = Q2;
	_Q3 = Q3;
	_Q4 = Q4;
	_STQ = STQ;
}

void MT8870::decode()
{	
	int dtmf = 0;

	if (digitalRead(_Q1) == HIGH)
	{
		dtmf += 1;
	}

	if (digitalRead(_Q2) == HIGH)
	{
		dtmf += 2;
	}

	if (digitalRead(_Q3) == HIGH)
	{
		dtmf += 4;
	}

	if (digitalRead(_Q4) == HIGH)
	{
		dtmf += 8;
	}
	
	_dtmf_key = dtmf;
	
}

int MT8870::getDTMFValue()
{
	return _dtmf_key;
}
