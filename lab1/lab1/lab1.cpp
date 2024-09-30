#include <iostream>
#include <string>
#include <fstream>
using namespace std;

template <typename T>
void InputCorrectNumber(T& var)
{
	cin >> var;
	while (cin.fail() || cin.peek() != '\n') 
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Error! Please enter correct data: ";
		cin >> var;
	}
}

class Pipe
{
public:
	string kilometerMark = "";
	double length = 0;
	int diameter = 0;
	bool isRepairing;
};

void AddPipe(Pipe& pipe) {
	cout << "Enter kilometer mark: ";
	cin.ignore();
	getline(cin, pipe.kilometerMark);
	cout << "Enter the pipe length (in kilometers): ";
	InputCorrectNumber(pipe.length);
	cout << "Enter the pipe diameter (in millimeters): ";
	InputCorrectNumber(pipe.diameter);
	cout << "Is the pipe being repaired? (1 - Yes, 0 - No) ";
	InputCorrectNumber(pipe.isRepairing);
}

class CompressorStation
{
public:
	string name = "";
	int workshopCount = 0;
	int activeWorkshopCount = 0;
	int efficiency = 0;
};

void AddCompressorStation(CompressorStation& CS) {
	cout << "Enter the name of the Compressor station: ";
	cin.ignore();
	getline(cin, CS.name);
	cout << "Enter the number of workshops: ";
	InputCorrectNumber(CS.workshopCount);
	cout << "Enter the number of active workshops: ";
	InputCorrectNumber(CS.activeWorkshopCount);
	while (CS.workshopCount < CS.activeWorkshopCount)
	{
		cout << "Error! The number of active workshops cant be more than the total number of workshops" << endl
			<< "Please enter correct data: ";
		InputCorrectNumber(CS.activeWorkshopCount);
	}
	cout << "Enter efficiency from 0 to 100: ";
	InputCorrectNumber(CS.efficiency);
	while (!(CS.efficiency >= 0 && CS.efficiency <= 100))
	{
		cout << "Error! Please enter correct data: ";
		InputCorrectNumber(CS.efficiency);
	}
}

void ViewAllObject(Pipe& pipe, CompressorStation& CS) {
	if (pipe.diameter == 0)
		cout << "Pipe not found." << endl;
	else {
		cout << "Kilometer mark: " << pipe.kilometerMark << endl;
		cout << "Pipe length: " << pipe.length << endl;
		cout << "Pipe diameter: " << pipe.diameter << endl;
		cout << "Is repair?" << pipe.isRepairing << endl;
	}
	if (CS.workshopCount == 0)
		cout << "Compressor station not found." << endl;
	else {
		cout << "Name Compressor Station: " << CS.name << endl;
		cout << "Workshop Compressor Station: " << CS.workshopCount << endl;
		cout << "Active Workshop Compressor Station: " << CS.activeWorkshopCount << endl;
		cout << "Efficiency: " << CS.efficiency << endl;
	}
}

void EditPipe(Pipe& pipe) {
	cout << "Edit: Is the pipe being repaired? (1 - Yes, 0 - No)";
	InputCorrectNumber(pipe.isRepairing);
}

int main()
{
	int commandNumber;
	Pipe pipe;
	CompressorStation CS;
	while (true)
	{
		cout << "MENU:" << endl
			<< "0. Exit the program" << endl
			<< "1. Add pipe" << endl
			<< "2. Add compressor station" << endl
			<< "3. View all objects" << endl
			<< "4. Edit pipe" << endl
			<< "5. Edit compressor station" << endl
			<< "6. Save" << endl
			<< "7. Load" << endl
			<< "What do you want to do: ";
		InputCorrectNumber(commandNumber);
		switch (commandNumber)
		{
		case 0:
			cout << "[ Exit the program ]" << endl;
			return 0;
		case 1:
		{
			cout << "[ Add pipe ]" << endl;
			AddPipe(pipe);
			break;
		}
		case 2:
		{
			cout << "[ Add compressor station ]" << endl;
			AddCompressorStation(CS);
			break;
		}
		case 3:
			cout << "[ View all objects ]" << endl;
			ViewAllObject(pipe, CS);
			break;
		case 4:
			cout << "[ Edit pipe ]" << endl;
			EditPipe(pipe);
			break;

		case 6:
			cout << "[ Save ]" << endl;
			
			break;
		default:
			cout << "Error! Please enter correct data: " << endl;
			break;
		}
	}
}