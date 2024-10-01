#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

template <typename T>
void InputCorrectNumber(T& var)
{
	cin >> var;
	while (cin.fail() || cin.peek() != '\n' || var < 1)
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
	int isRepairing;
	int temp;
};

void AddPipe(Pipe& pipe) {
	cout << "Enter kilometer mark: ";
	cin.ignore();
	getline(cin, pipe.kilometerMark);
	cout << "Enter the pipe length (in kilometers): ";
	InputCorrectNumber(pipe.length);

	cout << "Enter the pipe diameter (in millimeters): ";
	InputCorrectNumber(pipe.diameter);
	cout << "Is the pipe being repaired? (1 - Yes, 2 - No) ";
	cin >> pipe.temp;
	if (pipe.temp == 1 || pipe.temp == 2)
	{
		pipe.isRepairing = pipe.temp;
	}
	else
	{
		cout << "Error! Please enter correct data: ";
	}
	//while (!(pipe.temp == 2 || pipe.temp == 1)) 
	//{
	//	cin.clear();
	//	cin.ignore(1000, '\n');
	//	cout << "Error! Please enter correct data: ";
	//	pipe.isRepairing = pipe.temp;
	//}
	
}

class CompressorStation
{
public:
	string name = "";
	int workshopCount = 0;
	int activeWorkshopCount = 0;
	int efficiency = 0;
	int add;
	int addValue = 0;
	int temp;
	int t;
};

void AddCompressorStation(CompressorStation& CS) {
	cout << "Enter the name of the Compressor station: ";
	cin.ignore();
	getline(cin, CS.name);
	cout << "Enter the number of workshops: ";
	InputCorrectNumber(CS.workshopCount);
	cout << "Enter the number of active workshops: ";
	cin >> CS.t;
	if (CS.t >= 0)
	{
		CS.activeWorkshopCount = CS.t;
	}
	else
	{
		cout << "Error! Please enter correct data: ";
	}
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

void EditPipe(Pipe& pipe) {
	if (pipe.diameter == 0)
		cout << "Pipe not found." << endl;
	else {
		cout << "Edit: Is the pipe being repaired? (1 - Yes, 2 - No) ";
		InputCorrectNumber(pipe.isRepairing);
	}
}

void EditCS(CompressorStation& CS) {
	if (CS.workshopCount == 0)
		cout << "Compressor station not found." << endl;
	else {
		cout << "Add? (1 - Yes, 2 - Vice versa) ";
		cin >> CS.temp;
		if (CS.temp == 1 || CS.temp == 2)
		{
			CS.add = CS.temp;
		}
		else
		{
			cout << "Error! Please enter correct data: ";
		}
		if (CS.add == 1) {
			CS.activeWorkshopCount += 1;
			if (CS.workshopCount < CS.activeWorkshopCount)
			{
				cout << "Error! The number of active workshops cant be more than the total number of workshops" << endl;
			}
		}
		else if (CS.add == 2) {
			CS.activeWorkshopCount -= 1;
			if (0 > CS.activeWorkshopCount)
			{
				cout << "Error! The number of active workshops cant be more than the total number of workshops" << endl;
			}
		}
	}
}
void ViewAllObject(Pipe& pipe, CompressorStation& CS) {
	system("cls");
	if (!(pipe.isRepairing == 1 || pipe.isRepairing == 2))
		cout << "Pipe not found." << endl;
	else {
		cout << "Kilometer mark: " << pipe.kilometerMark << endl;
		cout << "Pipe length: " << pipe.length << endl;
		cout << "Pipe diameter: " << pipe.diameter << endl;
		cout << "Is repair? (1 - Yes, 2 - No) " << pipe.isRepairing << endl;
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
void Save(Pipe& pipe, CompressorStation& CS) {

	{
		ofstream out;   
		out.open("pervi.txt");      
		if (out.is_open())
		{	if (pipe.diameter == 0)
				cout << "Pipe not found." << endl;
			else {
				out << "Kilometer mark:" << endl;
				out << string(pipe.kilometerMark) << endl;
				out << "Pipe lengh" << endl;
				out << pipe.length << endl;
				out << "Pipe diametr" << endl;
				out << pipe.diameter << endl;
				out << "is repair?" << endl;
				out << pipe.isRepairing << endl;
			}
			if (CS.activeWorkshopCount == 0)
				cout << "CS not found." << endl;
			else {
				out << "Name Compressor Station:" << endl;
				out << CS.name << endl;
				out << "Workshop Compressor Station: " << endl;
				out << CS.workshopCount << endl;
				out << "Active Workshop Compressor Station:" << endl;
				out << CS.activeWorkshopCount << endl;
				out << "Efficiency:" << endl;
				out << CS.efficiency << endl;
				getline(cin, CS.name);
				InputCorrectNumber(CS.workshopCount);
				InputCorrectNumber(CS.activeWorkshopCount);
				InputCorrectNumber(CS.efficiency);

			}
		}
		out.close();
		cout << "File has been written" << std::endl;
	}

}

void Load(string filename, Pipe& pipe, CompressorStation& CS) {
	ifstream infile;
	infile.open(filename);
	if (infile.is_open()) {
		string name, nameC;
		double lengthStr, diameterStr, repairStr, numShopsStr, workingShopsStr, efficiencyStr;
		infile >> name;
		infile >> lengthStr;
		infile >> diameterStr;
		infile >> repairStr;
		pipe.kilometerMark = name;
		pipe.length = lengthStr;
		pipe.diameter = diameterStr;
		pipe.isRepairing = repairStr;
		infile >> nameC;
		infile >> numShopsStr;
		infile >> workingShopsStr;
		infile >> efficiencyStr;
		CS.name = nameC;
		CS.workshopCount = numShopsStr;
		CS.activeWorkshopCount = workingShopsStr;
		CS.efficiency = efficiencyStr;
	}
	infile.close();
	cout << "The data is downloaded from a file " << filename << endl;
}


int main()
{

	int commandNumber;
	Pipe pipe;
	CompressorStation CS;
	while (true)
	{
		cout << "MENU:" << endl
			<< "8. Exit the program" << endl
			<< "1. Add pipe" << endl
			<< "2. Add compressor station" << endl
			<< "3. View all objects" << endl
			<< "4. Edit pipe" << endl
			<< "5. Add active workshop" << endl
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

		case 5:

			cout << "[ Add active Workshop ]" << endl;
			EditCS(CS);
			break;

		case 6:

			cout << "[ Save ]" << endl;
			Save(pipe, CS);
			break;

		case 7:

			cout << "[ Load ]" << endl;
			Load ("vtoroi.txt", pipe, CS);
			break;

		default:
			cout << "Error! Please enter correct data: " << endl;
			break;
		}
	}
}