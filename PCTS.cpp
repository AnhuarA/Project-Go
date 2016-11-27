#include <iomanip>
#include <iostream>
#include <math.h>
#include "PCTS.h"// Call in PCTS header 
#include "Slow_Brain.h"// Call in Slow brain header file
#include "Public_Divisions.h"
using namespace std;

PCTS::PCTS(bool firstLight, bool secondLight, bool thirdLight)
	
{
	cout << "Welcome to the Pomona PCTS system.\n" << endl;

	bool lightStatus[3] = {true, true, true}; // Instantiate values to all true
	state = 0;
	prevState = 0;
	priority = 0;
	lightStatus[0] = firstLight;
	lightStatus[1] = secondLight;
	lightStatus[2] = thirdLight;

	

	state = Determine_State(lightStatus[0], lightStatus[1], lightStatus[2]);
	cout << "The current working intersections are: \n";
	for(int i = 0; i<3; i++){
		if(lightStatus[i] == true){
			cout << i + 1 << endl;
		}
	}

	Start_Calculations();
	contact_division();

	cout << "\n\nNew light value is " << lightStatus[priority-1] << "\n" << endl;

	New_State();
}

void PCTS::contact_division()// defining fucntions
{
	Public_Divisions divisions(lightStatus[priority-1], priority);
	lightStatus[priority -1] = divisions.Report_Progress(lightStatus[priority-1], priority);

}

void PCTS::Start_Calculations()
{
	Slow_Brain brain1(state, prevState, priority);
	priority = brain1.Calculate_Priority(state, priority);
	
	
}
int PCTS::Determine_State(bool x, bool y, bool z)
{
	if(x == true && y == true && z == true){
		state = 0;
	}
		else if(x == true && y == true && z == false){
			state = 1;
		}
			else if(x == true && y == false && z == true){
				state = 2;
			}
				else if(x == true && y == false && z == false){
					state = 3;
				}
					else if(x == false && y == true && z == true){
						state = 4;
					}
						else if(x == false && y == true && z == false){
							state = 5;
						}
							else if(x == false && y == false && z == true){
								state = 6;
							}
								else if(x == false && y == false && z == false){
									state = 7;
								}	

	cout << "\nThe current state is " << state << ".\n" << endl;
	return state;
}
void PCTS::New_State()
{
	prevState = state;
	state = Determine_State(lightStatus[0], lightStatus[1], lightStatus[2]);

	cout << "\nAfter repairs, the current state is: " << state << endl;

}
