#include <iostream>
#include <fstream>
#include <vector>

void writeOutputData(std::vector<std::string>& data);
void mergeSortInputData(std::vector<std::string>& data, std::vector<std::string>& dataLeft, std::vector<std::string>& dataRight);
void mergeInputData(std::vector<std::string>& data);
std::vector<std::string> readInputData(std::string path);
bool checkIfFileExists(std::string path);
std::string fileChooser(std::string mode);
void program(std::string mode, int n);
void modeChecker(std::string mode);

void writeOutputData(std::vector<std::string>& data) {
    std::ofstream outputFile("output.txt");
    for (auto& line: data) {
        outputFile << line << "\n";
    }
    outputFile.close();
}

void mergeInputData(std::vector<std::string>& data, std::vector<std::string>& dataLeft, std::vector<std::string>& dataRight) {
    int leftIndex = 0, rightIndex = 0, vIndex = 0;
    while (leftIndex < dataLeft.size() && rightIndex < dataRight.size()) {
        if (dataLeft[leftIndex] <= dataRight[rightIndex]) {
            data[vIndex] = dataLeft[leftIndex];
            ++leftIndex;
        }
        else {
            data[vIndex] = dataRight[rightIndex];
            ++rightIndex;
        }
        ++vIndex;
    }
    // if rightIndex > vEnd
    while (leftIndex < dataLeft.size()) {
        data[vIndex] = dataLeft[leftIndex];
        ++leftIndex;
        ++vIndex;
    }
    // if leftIndex > vMiddle
    while (rightIndex < dataRight.size()) {
        data[vIndex] = dataRight[rightIndex];
        ++rightIndex;
        ++vIndex;
    }
}

void mergeSortInputData(std::vector<std::string>& data) {
    if (data.size() > 1) {
        std::vector<std::string> dataLeft, dataRight;
        std::vector<std::string>::iterator iteratorMiddle(data.begin() + data.size() / 2);
        for (auto vIterator = data.begin(); vIterator < data.end(); ++vIterator) {
            if (distance(vIterator, iteratorMiddle) > 0) dataLeft.emplace_back(*vIterator);
            else dataRight.emplace_back(*vIterator);
        }
        mergeSortInputData(dataLeft);
        mergeSortInputData(dataRight);
        mergeInputData(data, dataLeft, dataRight);
    }
}

std::vector<std::string> readInputData(std::string path) {
    std::vector<std::string> inputData;
    std::string line;
    std::ifstream inputFile;
    inputFile.open(path);
    while (getline(inputFile, line)) inputData.emplace_back(line);
    inputFile.close();
    return inputData;
}

bool checkIfFileExists(std::string path) {
    std::ifstream filename;
    filename.open(path);
    if (filename) {
        filename.close();
        return true;
    }
    else return false;
}

std::string fileChooser(std::string mode) {
    std::string path;
    if (mode == "user") std::cout << "Please, write the path to the input file: ";
    else if (mode == "default") std::cout << "Please, write the name of the chosen default input file: ";
    getline(std::cin >> std::ws, path);
    if (!checkIfFileExists(path)) {
        std::cout << "Sorry, the path/filename is incorrect, or the file does not exist.\n";
        fileChooser(mode);
    }
    return path;
}

void program(std::string mode, int n) {
    int i = 0;
    std::vector<std::string> inputData, data;
    while (i != n) {
        std::string path = fileChooser(mode);
        inputData = readInputData(path);
        data.insert(data.end(), inputData.begin(), inputData.end());
        ++i;
    }
    mergeSortInputData(data);
    writeOutputData(data);
    std::cout << "Ending the program...\nCopyright 2022 Viola Mazurenko All Rights Reserved.\n";
}

void modeChecker(std::string mode) {
    std::string startProgram, catchError;
    if (mode == "user") {
        startProgram = "\nPlease, enter the number of the input files you want to read and sort: ";
        catchError = "ERROR! Wrong input data type or the number is not a positive integer.\n";
    }
    if (mode == "default") {
        startProgram = "\nPlease, enter the number of the input files you want to read and sort (max = 5, min = 1): ";
        catchError = "ERROR! Wrong input data type or the number is incorrect.\n";
    }
    std::cout << startProgram;
    int n;
    std::cin >> n;
    if (mode == "user" && n > 0) program(mode, n);
    else if (mode == "default" && (n > 0 && n < 6)) program(mode, n);
    else {
        std::cout << catchError;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        modeChecker(mode);
    }
}

void userMenu() {
    std::cout << "Please, choose one of the following options:";
    std::cout << "\n 1) If you want to run the program with the default input files press 'D'/'d'.";
    std::cout << "\n 2) If you want to run the program with your input files press 'U'/'u'.";
    std::cout << "\n 3) If you want to exit the program press 'E'/'e'.";
    std::cout << "\nYour answer is: ";
    std::string answer;
    std::cin >> answer;
    if (answer.size() == 1) {
        switch(answer[0]) {
            case 'D':
            case 'd':
                modeChecker("default");
                break;
            case 'U':
            case 'u':
                modeChecker("user");
                break;
            case 'E':
            case 'e':
                std::cout << "Ending the program...\nCopyright 2022 Viola Mazurenko All Rights Reserved.\n";
                break;
            default:
                std::cout << "Sorry, wrong button! Please, try again.\n";
                userMenu();
        }
    }
    else {
        std::cout << "Error, sorry! Please, type only ONE letter.\n";
        userMenu();
    }
}

int main() {
    std::cout << "Starting the program...\n";
    userMenu();
    system("pause");
    return 0;
}
