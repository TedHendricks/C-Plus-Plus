/*
Authors: Ted Hendricks & Jules Rogmans
CS133U Paired Programming Assignment
Goal: Calculate Business Trip Expenses
*/

#include <iostream>
#include <iomanip>

using namespace std;

//function prototypes

int InputTravelDays();
int InputDepartureTime();
int InputArrivalTime();
double InputAirFareCost();
double InputRentalCost();
double InputMilesDriven();
double InputParkingFees();
double InputTaxiFees();
double InputRegistrationFees();
double InputHotelCost();
double InputBreakfastCost();
double InputLunchCost();
double InputDinnerCost();

bool CheckYesNoInput(char);
bool CheckForFunctionCall(char);

double CheckAddToTotalAllowed(double, double, double, double, double, double);

const double PARKING_ALLOWED = 6.0, TAXI_COST_ALLOW = 10.0, HOTEL_COST_ALLOW = 90.0, BREAKFAST_ALLOW = 9.0,
		LUNCH_ALLOW = 12.0, DINNER_ALLOW = 16.0;


int main()
{
	

	int 
		travelDays = InputTravelDays(),
		departureTime = InputDepartureTime(),
		arrivalTime = InputArrivalTime();
	
	//doubles to hold the current value
	double 
		 
		airfareCost = InputAirFareCost(), 
		taxiCost = 0.0, 
		hotelCost = 0.0, 
		privateCarCost = 0.0, 
		rentalCost = 0.0, 
		parkingCost = 0.0,
		registrationFeesCost = 0.0, 
		breakfastCost = 0.0, 
		lunchCost = 0.0, 
		dinnerCost = 0.0, 
		totalTravelCost = 0.0,
		totalAllowedCost = 0.0,
		grandTotal = 0.0;

	//doubles to hole the cumilative values
	double
		parkingTotal = 0.0,
		taxiTotal = 0.0,
		hotelTotal = 0.0,
		breakfastTotal = 0.0,
		lunchTotal = 0.0,
		dinnerTotal = 0.0,
		registrationFeesTotal = 0.0,
		rentalTotal = 0.0,
		privateCarTotal = 0.0;


	char taxiRental = '\0', rentalCar = '\0', privateCar = '\0', hotelRental = '\0';
	
	cout << "Did you rent a car during your trip? (y/n)\n-->";
	cin >> rentalCar;
	while (!CheckYesNoInput(rentalCar))
	{
		cin >> rentalCar;
	}

	cout << "Did you ever take a taxi during your trip? (y/n)\n-->";
	cin >> taxiRental;
	while (!CheckYesNoInput(taxiRental))
	{
		cin >> taxiRental;
	}

	cout << "Did you use a private car during your trip? (y/n)\n-->";
	cin >> privateCar;
	while (!CheckYesNoInput(privateCar))
	{
		cin >> privateCar;
	}

	cout << "Did you rent a hotel at all during your trip? (y/n)\n-->";
	cin >> hotelRental;
	while (!CheckYesNoInput(hotelRental))
	{
		cin >> hotelRental;
	}

	
	for (int i = 1; i <= travelDays; i++)
	{
		cout << "\n\n----------------------------\n";
		cout << "FOR DAY " << i;
		cout << "\n----------------------------\n\n";
		//Decision for departure day meal cost
		if (i == 1 && departureTime == 1)
		{
			breakfastCost = InputBreakfastCost();
			lunchCost = InputLunchCost();
			dinnerCost = InputDinnerCost();
		}
		else if (i == 1 && departureTime == 2)
		{
			lunchCost = InputLunchCost();
			dinnerCost = InputDinnerCost();
		}
		else if (i == 1 && departureTime == 3)
		{
			dinnerCost = InputDinnerCost();
		}
		else if (i == 1 && departureTime == 4)
		{
			break;
		}
		
		
		//Decision for return arrival time
		if (i == travelDays && arrivalTime == 4)
		{
			breakfastCost = InputBreakfastCost();
			lunchCost = InputLunchCost();
			dinnerCost = InputDinnerCost();
		}
		else if (i == travelDays && arrivalTime == 3)
		{
			breakfastCost = InputBreakfastCost();
			lunchCost = InputLunchCost();
		}
		else if (i == travelDays && arrivalTime == 2)
		{
			breakfastCost = InputBreakfastCost();
		}
		else if (i == travelDays && arrivalTime == 1)
		{
			break;
		}
		
		
		if (i != 1 && i != travelDays)
		{
			breakfastCost = InputBreakfastCost();
			lunchCost = InputLunchCost();
			dinnerCost = InputDinnerCost();
		}


		//function calls for main travel
	
		if (CheckForFunctionCall(taxiRental))
		{
			taxiCost = InputTaxiFees();
		}
		
		if (CheckForFunctionCall(privateCar))
		{
			privateCarCost = InputMilesDriven();
		}

		if (CheckForFunctionCall(rentalCar))
		{
			rentalCost = InputRentalCost();
		}

		if (CheckForFunctionCall(hotelRental))
		{
			hotelCost = InputHotelCost();
		}

		
	
		registrationFeesCost = InputRegistrationFees();
	
		parkingCost = InputParkingFees();

		parkingTotal += parkingCost;
		taxiTotal += taxiCost;
		hotelTotal += hotelCost;
		breakfastTotal += breakfastCost;
		lunchTotal += lunchCost;
		dinnerTotal += dinnerCost;
		registrationFeesTotal += registrationFeesCost;
		rentalTotal += rentalCost;
		privateCarTotal += privateCarCost;

		

		totalAllowedCost += CheckAddToTotalAllowed(parkingCost, taxiCost, hotelCost, breakfastCost, lunchCost, dinnerCost);
	
		
		totalTravelCost += (parkingCost + taxiCost + hotelCost + breakfastCost + lunchCost + dinnerCost);
		
		//reset variables
		parkingCost = 0.0;
		taxiCost = 0.0;
		hotelCost = 0.0;
		breakfastCost = 0.0;
		lunchCost = 0.0;
		dinnerCost = 0.0;
		registrationFeesCost = 0.0;
		privateCarCost = 0.0;
		rentalCost = 0.0;
	}

	grandTotal = totalTravelCost + registrationFeesTotal + airfareCost + privateCarTotal + rentalTotal;


	cout << fixed << setprecision(2) << showpoint;
	cout << "\n\n--------------------------\nTravel Expenses\n--------------------------\n\n";

	cout <<
		"The total allowed for each day is\n---------------------------------\n" <<
		"Parking: $" << PARKING_ALLOWED << "\n" <<
		"Taxi: $" << TAXI_COST_ALLOW << "\n" <<
		"Hotel: $" << HOTEL_COST_ALLOW << "\n" <<
		"Breakfast: $" << BREAKFAST_ALLOW << "\n" <<
		"Lunch: $" << LUNCH_ALLOW << "\n" <<
		"Dinner: $" << DINNER_ALLOW << endl << endl;

	cout << 
		"You spent\n---------\n" <<
		"Parking: $" << parkingTotal << "\n";
	if (taxiTotal != 0)
	{
		cout << "Taxi: $" << taxiTotal << "\n";
	}
	if (hotelTotal != 0)
	{
		cout << "Hotel: $" << hotelTotal << "\n";
	}
	cout <<
		"Breakfast: $" << breakfastTotal << "\n" <<
		"Lunch: $" << lunchTotal << "\n" <<
		"Dinner: $" << dinnerTotal << endl << endl;

	cout << 
		"Your total travel cost for the items listed above is $" << totalTravelCost << endl << "\n"
		"The total allowed for the items listed above was $" << totalAllowedCost << endl;

	if (totalTravelCost > totalAllowedCost)
	{
		cout <<
			"You went $" << totalTravelCost - totalAllowedCost << " over budget" << endl;
	} else
	{
		cout <<
			"Good work, you saved $" << totalAllowedCost - totalTravelCost << endl;
	}


	cout << endl <<
		"---------------------------------\n" <<
		"YOUR GRAND TOTAL: $" << grandTotal <<
		"\n---------------------------------" <<
		endl << endl << endl;


	system("pause");
	return 0;

}

int InputTravelDays()
{
	int days;
	cout << "How many days was your business trip?\n-->";
	cin >> days;
	//validate input
	while (days < 1)
	{
		cout << "That is not a valid entry, please try again.\n-->";
		cin >> days;
	}
	return days;
}

int InputDepartureTime()
{
	int departure;

	cout << "Was your initial departure time:\n" 
		<< "1. Before 7 am\n" 
		<< "2. Before noon\n" 
		<< "3. Before 6 pm\n" 
		<< "4. After 6 pm\n" 
		<< "Enter choice: ";
	cin >> departure;
	//validate input
	while (departure != 1 && departure != 2 && departure != 3 && departure != 4)
	{
		cout << "That is not a valid entry, please try again\n-->";
		cin >> departure;
	}
	return departure;
}

int InputArrivalTime()
{
	int arrival;

	cout << "Was your returning arrival time:\n" 
		<< "1. Before 8 am\n" 
		<< "2. After 8 am\n" 
		<< "3. After 1 pm\n" 
		<< "4. After 7 pm\n" 
		<< "Enter choice: ";
	cin >> arrival;
	//validate input
	while (arrival != 1 && arrival != 2 && arrival != 3 && arrival != 4)
	{
		cout << "That is not a valid entry, please try again\n-->";
		cin >> arrival;
	}
	return arrival;
}


double InputAirFareCost()
{
	int airfare;
	cout << "If you did any flying, what was the total airfare cost? \n(Enter 0 if not flying)\n-->";
	cin >> airfare;
	//validate input
	while (airfare < 0)
	{
		cout << "Airfare cost cannot be a negative number, please try again\n-->";
		cin >> airfare;
	}
	return airfare;
}

double InputRentalCost()
{
	double rentalCost;
	cout << "What was the  cost of your rental car for the day?\n-->";
	cin >> rentalCost;
	//validate input
	while (rentalCost < 0)
	{
		cout << "Rental cost cannot be a negative number, please try again\n-->";
		cin >> rentalCost;
	}
	return rentalCost;
}

double InputMilesDriven()
{
	double dailyMilesDriven;
	const double COST_PER_MILE = 0.27;

	cout << "How many miles did you drive your private vehicle?\n-->";
	cin >> dailyMilesDriven;
	//validate input
	while (dailyMilesDriven < 0)
	{
		cout << "Miles driven cannot be a negative number, please try again\n-->";
		cin >> dailyMilesDriven;
	}
	dailyMilesDriven *= COST_PER_MILE;
	return dailyMilesDriven;
}

double InputParkingFees()
{
	double parkingCost;
	cout << "What were your total parking fees for the day?\n-->";
	cin >> parkingCost;
	//validate input
	while (parkingCost < 0)
		{
			cout << "Parking fees cannot be a negative number, please try again.\n-->";
			cin >> parkingCost;
		}
	return parkingCost;
}

double InputTaxiFees()
{
	double taxiCost;
	cout << "What were your total taxi fees for the day?\n-->";
	cin >> taxiCost;
	//validate input
	while (taxiCost < 0)
		{
			cout << "Taxi fees cannot be a negative number, please try again.\n-->";
			cin >> taxiCost;
		}
	return taxiCost;
}

double InputRegistrationFees()
{
	double registrationCost;
	cout << "What were your total registration fees for the day?\n-->";
	cin >> registrationCost;
	//validate input
	while (registrationCost < 0)
		{
			cout << "Registration fees cannot be a negative number, please try again.\n-->";
			cin >> registrationCost;
		}
	return registrationCost;
}

double InputHotelCost()
{
	double hotelCost;
	cout << "What was your hotel cost for the day?\n-->";
	cin >> hotelCost;
	//validate input
	while (hotelCost < 0)
		{
			cout << "Hotel cost cannot be a negative number, please try again.\n-->";
			cin >> hotelCost;
		}
	return hotelCost;
}

double InputBreakfastCost()
{
	double breakfast;
	cout << "What was the cost of breakfast?\n-->";
	cin >> breakfast;
	//validate input
	while (breakfast < 0)
		{
			cout << "Breakfast cost cannot be a negative number, please try again.\n-->";
			cin >> breakfast;
		}
	return breakfast;
}
double InputLunchCost()
{
	double lunch;

	cout << "What was the cost of lunch?\n-->";
	cin >> lunch;
	//validate input
	while (lunch < 0)
		{
			cout << "Lunch cost cannot be a negative number, please try again.\n-->";
			cin >> lunch;
		}
	return lunch;
}
double InputDinnerCost()
{
	double dinner;
	cout << "What was the cost of dinner?\n-->";
	cin >> dinner;
	//validate input
	while (dinner < 0)
		{
			cout << "Dinner cost cannot be a negative number, please try again.\n-->";
			cin >> dinner;
		}
	return dinner;
}

bool CheckYesNoInput(char userInput)
{
	bool inputResult;
	if (userInput != 'y' && userInput != 'Y' && userInput != 'n' && userInput != 'N')
	{
		cout << "That is not a valid entry. Please enter \"y\" for yes, and \"n\" for no\n-->";
		inputResult = false;
	}
	else
	{
		inputResult = true;
	}
	
	return inputResult;
}

bool CheckForFunctionCall(char userInput)
{
	bool inputResult;
	if (userInput == 'y' || userInput == 'Y')
	{
		inputResult = true;
	}
	else
	{
		inputResult = false;
	}

	return inputResult;
}

double CheckAddToTotalAllowed(double parking, double taxi, double hotel, double breakfast, double lunch, double dinner)
{
	double totalAllowed = 0.0;

	if (parking != 0)
	{
		totalAllowed += PARKING_ALLOWED;
	}
	if (taxi != 0)
	{
		totalAllowed += TAXI_COST_ALLOW;
	}
	if (hotel != 0)
	{
		totalAllowed += HOTEL_COST_ALLOW;
	}

	if (breakfast != 0)
	{
		totalAllowed += BREAKFAST_ALLOW;
	}
	if (lunch != 0)
	{
		totalAllowed += LUNCH_ALLOW;
	}
	if (dinner != 0)
	{
		totalAllowed += DINNER_ALLOW;
	}

	return totalAllowed;
}


/*
OUTPUT:

How many days was your business trip?
-->0
That is not a valid entry, please try again.
-->0
That is not a valid entry, please try again.
-->3
Was your initial departure time:
1. Before 7 am
2. Before noon
3. Before 6 pm
4. After 6 pm
Enter choice: 7
That is not a valid entry, please try again
-->5
That is not a valid entry, please try again
-->1
Was your returning arrival time:
1. Before 8 am
2. After 8 am
3. After 1 pm
4. After 7 pm
Enter choice: 7
That is not a valid entry, please try again
-->5
That is not a valid entry, please try again
-->4
If you did any flying, what was the total airfare cost?
(Enter 0 if not flying)
-->-1
Airfare cost cannot be a negative number, please try again
-->300
Did you rent a car during your trip? (y/n)
-->k
That is not a valid entry. Please enter "y" for yes, and "n" for no
-->c
That is not a valid entry. Please enter "y" for yes, and "n" for no
-->y
Did you ever take a taxi during your trip? (y/n)
-->y
Did you use a private car during your trip? (y/n)
-->y
Did you rent a hotel at all during your trip? (y/n)
-->y


----------------------------
FOR DAY 1
----------------------------

What was the cost of breakfast?
-->-1
Breakfast cost cannot be a negative number, please try again.
-->9
What was the cost of lunch?
-->-1
Lunch cost cannot be a negative number, please try again.
-->12
What was the cost of dinner?
-->-1
Dinner cost cannot be a negative number, please try again.
-->16
What were your total taxi fees for the day?
-->-1
Taxi fees cannot be a negative number, please try again.
-->10
How many miles did you drive your private vehicle?
-->-1
Miles driven cannot be a negative number, please try again
-->10
What was the  cost of your rental car for the day?
-->-1
Rental cost cannot be a negative number, please try again
-->30
What was your hotel cost for the day?
-->-1
Hotel cost cannot be a negative number, please try again.
-->90
What were your total registration fees for the day?
-->-1
Registration fees cannot be a negative number, please try again.
-->10
What were your total parking fees for the day?
-->-1
Parking fees cannot be a negative number, please try again.
-->6


----------------------------
FOR DAY 2
----------------------------

What was the cost of breakfast?
-->9
What was the cost of lunch?
-->12
What was the cost of dinner?
-->16
What were your total taxi fees for the day?
-->10
How many miles did you drive your private vehicle?
-->10
What was the  cost of your rental car for the day?
-->30
What was your hotel cost for the day?
-->90
What were your total registration fees for the day?
-->10
What were your total parking fees for the day?
-->6


----------------------------
FOR DAY 3
----------------------------

What was the cost of breakfast?
-->9
What was the cost of lunch?
-->12
What was the cost of dinner?
-->16
What were your total taxi fees for the day?
-->10
How many miles did you drive your private vehicle?
-->10
What was the  cost of your rental car for the day?
-->30
What was your hotel cost for the day?
-->90
What were your total registration fees for the day?
-->10
What were your total parking fees for the day?
-->6


--------------------------
Travel Expenses
--------------------------

The total allowed for each day is
---------------------------------
Parking: $6.00
Taxi: $10.00
Hotel: $90.00
Breakfast: $9.00
Lunch: $12.00
Dinner: $16.00

You spent
---------
Parking: $18.00
Taxi: $30.00
Hotel: $270.00
Breakfast: $27.00
Lunch: $36.00
Dinner: $48.00

Your total travel cost for the items listed above is $429.00

The total allowed for the items listed above was $429.00
Good work, you saved $0.00

---------------------------------
YOUR GRAND TOTAL: $857.10
---------------------------------


'\\psf\Home\Documents\RCC\Winter_2015\CS133U\labs\groupassignment\groupassignmen
t'
CMD.EXE was started with the above path as the current directory.
UNC paths are not supported.  Defaulting to Windows directory.
Press any key to continue . . .
*/
