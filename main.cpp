#include <iostream>
#include <fstream>

using namespace std;

bool CheckArguments(int argc, char* argv[]);

int main(int argc, char* argv[])
{
    if (!CheckArguments(argc, argv))
    {
        return 1;
    }

    string fileName = argv[1];
    string outputFile = "ENCRYPTED" + fileName;
    int shiftVal = atoi(argv[2]);
    ofstream outFS;
    ifstream inFS;

    cout << "Trying to open " << fileName << endl;

    inFS.open(fileName);
    if (!inFS.is_open())
    {
        cout << "Could not open file" << endl;
        return 1;
    }
    else
    {
        cout << fileName << " is open" << endl;
    }

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

    while (!inFS.fail() && !outFS.fail())
    {
        cout << "Reading line " << count << endl;
        getline(inFS, currLine);
        cout << currLine << endl;

        for (int i = 0; i < currLine.length() && currLine.at(i) != '\0'; i++)
        {
            currLine.at(i) += shiftVal;
        }

        outFS << currLine << endl;

        count++;
    }

    if (inFS.eof())
    {
        cout << "End of file reached" << endl;
    }

    outFS.close();
    inFS.close();

    return 0;
}

bool CheckArguments(int argc, char* argv[])
{
    if (argc < 3)
    {
        cout << "Not enough arguments entered. Please format as follows: ./encrypt <filename> <offset amount>\nExiting" << endl;
        cout << argc << endl;

        return false;
    }

    return true;
}
