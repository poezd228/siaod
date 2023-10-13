//
// Created by santv on 13.10.2023.
//

#include "file_functions.h"

#include "file_functions.h"
#include <random>

void createFile(const std::string &filename) {
    std::ofstream file(filename);
    file.close();
}

void displayFileContent(const std::string &filename) {
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }
    file.close();
}

void appendToFile(const std::string &filename, const std::vector<int> &values) {
    std::ofstream file(filename, std::ios_base::app);
    for (int val : values) {
        file << val << " ";
    }
    file << "\n";
    file.close();
}

int getValueByIndex(const std::string &filename, int index) {
    std::ifstream file(filename);
    int currentValue, currentIndex = 0;
    while (file >> currentValue) {
        if (currentIndex == index) {
            file.close();
            return currentValue;
        }
        currentIndex++;
    }
    file.close();
    throw std::runtime_error("Index out of bounds");
}

int getNumberOfValues(const std::string &filename) {
    std::ifstream file(filename);
    int count = 0, value;
    while (file >> value) {
        count++;
    }
    file.close();
    return count;
}

void createRandomValuesFile(const std::string &sourceFilename, const std::string &newFilename) {
    int numValues = getNumberOfValues(sourceFilename);
    std::ofstream newFile(newFilename);
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1, numValues);

    for (int i = 0; i < numValues; i++) {
        int randomValuesCount = dist(mt);
        for (int j = 0; j < randomValuesCount; j++) {
            newFile << dist(mt) << " ";
        }
        newFile << "\n";
    }
    newFile.close();
}
