//
// Created by santv on 13.10.2023.
//

#ifndef SIAOD_FILE_FUNCTIONS_H
#define SIAOD_FILE_FUNCTIONS_H
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void createFile(const std::string &filename);
void displayFileContent(const std::string &filename);
void appendToFile(const std::string &filename, const std::vector<int> &values);
int getValueByIndex(const std::string &filename, int index);
int getNumberOfValues(const std::string &filename);
void createRandomValuesFile(const std::string &sourceFilename, const std::string &newFilename);



#endif //SIAOD_FILE_FUNCTIONS_H
