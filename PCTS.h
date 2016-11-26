#pragma once
#ifndef PCTS_H
#define PCTS_H

class PCTS: public Slow_Brain, public Fast_Brain, public Divisions
{
public:
	PCTS();// muthafucking constructor 
	void contact_division();
	void Start_Calculations();
	//Changing way the state is determined
	int Determine_State(bool,bool,bool);
	void New_State();
	void Light_Prolong(); 
	int priority[];
private:
	int state;
	bool lightStatus[];
	double criticality[];
	

};

#endif

