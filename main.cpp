#include <iostream>
#include <fstream>

using namespace std;

bool CheckArguments(int argc, char* argv[]);
int OpenInputFile(ifstream& inputStream, string filename);

int main(int argc, char* argv[])
{
    // Check for the right amount of arguments
    if (!CheckArguments(argc, argv))
    {
        return 1;
    }

    // Get arguments and create file streams
    string fileName = argv[1];
    string outputFile = fileName + "_encrypted";
    int shiftVal = atoi(argv[2]);
    ofstream outFS;
    ifstream inFS;

    if (OpenFile(inFS, fileName) == 1)
    {
        return 1;
    }

    // Open output file
    outFS.open(outputFile);
    if (!outFS.is_open())
    {
        cout << "Could not open file" << endl;
        return 1;
    }
    else
    {
        cout << outputFile << " is open" << endl;
    }

    int count = 1;
    string currLine = "";

    // Go through each line and encrypt it
    while (!inFS.fail() && !outFS.fail())
    {
        cout << "Reading line " << count << endl;
        getline(inFS, currLine);
        cout << currLine << endl;

        // Shift each char in the line by shiftVal amount
        for (int i = 0; i < currLine.length() && currLine.at(i) != '\0'; i++)
        {
            currLine.at(i) += shiftVal;
        }

        outFS << currLine << endl;

        count++;
    }

    // See if we are at the end of the file
    if (inFS.eof())
    {
        cout << "End of file reached" << endl;
    }

    // Close file streams
    outFS.close();
    inFS.close();

    return 0;
}

bool CheckArguments(int argc, char* argv[])
{
    // Make sure the arguments for the input file and the shift value are defined
    if (argc < 3)
    {
        cout << "Not enough arguments entered. Please format as follows: ./encrypt <filename> <offset amount>\nExiting" << endl;
        cout << argc << endl;

        return false;
    }

    return true;
}

int OpenInputFile(ifstream& inputStream, string filename)
{
	// Open input file
	cout << "Trying to open " << filename << endl;
	inputStream.open(filename);
	if (!inputStream.is_open())
	{
		cout << "Could not open file" << endl;
		return 1;
	}
	else
	{
		cout << filename << " is open" << endl;
        return 0;
	}
}
