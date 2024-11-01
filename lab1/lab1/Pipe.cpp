#include "Pipe.h"

int Pipe::maxId = 0;

int Pipe::GetId()
{
	return Id;
}

void Pipe::PrintPipeStatus()
{
	cout << (isRepairing ? "Pipe is under repair" : "Pipe is in work") << endl;
}

string Pipe::GetName() const
{
	return kilometerMark;
}

int Pipe::GetDiameter() const
{
	return diameter;
}

bool Pipe::GetStatus() const
{
	return isRepairing;
}

void InputCorrectDiameter(int& diameter)
{
	cin >> diameter;
	while ((diameter < 500) || cin.fail() || cin.peek() != '\n')
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Error! Please enter correct data: ";
		cin >> diameter;
	}
}

void EditPipes(vector <Pipe*>& pipes)
{
	cout << endl << "Do you want to change repairing status?" << endl
		<< "1. Yes" << endl
		<< "2. No" << endl
		<< "Your choice: ";
	int commandNumber;
	InputCorrectNumber(commandNumber);
	switch (commandNumber)
	{
	case 1:
		bool isRepairing;
		cout << "Is the pipe being repaired? (1 - Yes, 0 - No) ";
		InputCorrectNumberNull(isRepairing, true);

		for (auto& pipe : pipes)
		{
			pipe->isRepairing = isRepairing;
			cout << "ID: " << pipe->Id << " - ";
			pipe->PrintPipeStatus();
		}
		break;
	case 2:
		return;
	default:
		cout << "Error! Please enter correct data " << endl;
		break;
	}
}

void EditPipe(Pipe& pipe)
{
	cout << "Do you want to change repairing status?" << endl
		<< "1. Yes" << endl
		<< "2. No" << endl
		<< "Your choice: ";
	int commandNumber;
	InputCorrectNumber(commandNumber);
	switch (commandNumber)
	{
	case 1:
		bool isRepairing;
		cout << "Is the pipe being repaired? (1 - Yes, 0 - No) ";
		InputCorrectNumberNull(isRepairing, true);

		pipe.isRepairing = isRepairing;
		cout << "ID: " << pipe.Id << " - ";
		pipe.PrintPipeStatus();
		break;
	case 2:
		return;
	default:
		cout << "Error! Please enter correct data " << endl;
		break;
	}
}

ostream& operator<<(ostream& out, const Pipe& pipe)
{
	out << endl << "Pipe Id: " << pipe.Id << endl;
	out << "Kilometer mark: " << pipe.kilometerMark << endl;
	out << "Pipe length: " << pipe.length << " km" << endl;
	out << "Pipe diameter: " << pipe.diameter << " mm" << endl;
	if (pipe.isRepairing)
		out << "Pipe under repair." << endl;
	else
		out << "Pipe is in work." << endl;
	return out;
}

istream& operator>>(istream& in, Pipe& pipe)
{
	pipe.Id = ++pipe.maxId;
	cout << "Id: " << pipe.Id << endl;
	cout << "Enter kilometer mark: ";
	in.ignore();
	getline(in, pipe.kilometerMark);
	cout << "Enter the pipe length (in kilometers): ";
	InputCorrectNumber(pipe.length);
	cout << "Enter the pipe diameter (in millimeters): ";
	InputCorrectDiameter(pipe.diameter);
	cout << "Is the pipe being repaired? (1 - Yes, 0 - No) ";
	InputCorrectNumberNull(pipe.isRepairing, true);
	return in;
}

ofstream& operator<<(ofstream& fout, const Pipe& pipe)
{
	fout << pipe.Id << endl;
	fout << pipe.length << endl;
	fout << pipe.kilometerMark << endl;
	fout << pipe.diameter << endl;
	fout << pipe.isRepairing << endl;
	cout << "Pipe data successfully saved to file!" << endl;
	return fout;
}

ifstream& operator>>(ifstream& fin, Pipe& pipe)
{
	fin >> pipe.Id;
	pipe.maxId = pipe.Id;
	fin >> pipe.length;
	fin.ignore();
	getline(fin, pipe.kilometerMark);
	fin >> pipe.diameter;
	fin >> pipe.isRepairing;
	cout << "Pipe data loaded successfully!" << endl;
	return fin;
}

