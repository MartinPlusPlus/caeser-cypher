#include <iostream>
#include <fstream>

using namespace std;

bool CheckArguments(int argc, char* argv[]);
int OpenInputFile(fstream& filestream, string filename);

int main(int argc, char* argv[])
{
    string fileName = argv[1];
    int shiftVal = atoi(argv[2]);
    int dotIndex;
    string pureName;
    string extension;
    string outputFile = fileName + "_encrypted";
    ofstream outFS;
    fstream fileStream;

    // Check for the right amount of arguments
    if (!CheckArguments(argc, argv))
    {
        return 1;
    }

    // Find start of extension
    if (fileName.find('.') != string::npos)
    {
        dotIndex = fileName.find('.');
        extension = fileName.substr(dotIndex);
    }
    else
    {
        cout << "WARNING: Your file does not contain an extension, some functionality may be lost" << endl;
    }

    // If there is a file extension, create a string containing just the filename
    if (dotIndex)
    {
        pureName = fileName.substr(0, (dotIndex));
    }
    else
    {
        pureName = fileName;
    }

    outputFile = pureName + "_encrypted" + extension;

    // Open file, if it fails, return 1
    if (OpenInputFile(fileStream, fileName) == 1)
    {
	cout << "ERROR: Could not read file: " << fileName << endl;
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
    while (!fileStream.fail() && !outFS.fail())
    {
        cout << "Reading line " << count << endl;
        getline(fileStream, currLine);
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
    if (fileStream.eof())
    {
        cout << "End of file reached" << endl;
    }

    // Close file streams
    outFS.close();
    fileStream.close();

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

int OpenInputFile(fstream& filestream, string filename)
{
    // Open input file
    cout << "Trying to open " << filename << endl;
    filestream.open(filename);
    if (!filestream.is_open())
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
