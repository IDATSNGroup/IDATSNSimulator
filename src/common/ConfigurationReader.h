//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#ifndef SWITCH_FORWARDINGLOGIC_CONFIGURATIONFILEREADERSINGLETONSINGLETON_H_
#define SWITCH_FORWARDINGLOGIC_CONFIGURATIONFILEREADERSINGLETONSINGLETON_H_

#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <omnetpp.h>

using namespace omnetpp;

#define COMMENT_SYMBOL   "#"
#define COMMENT_POSITION  0

typedef std::vector<std::vector<int>> configVector;

class ConfigurationReader
{
public:
    /*
     * Singleton design pattern:
     */
    static ConfigurationReader* getInstance();

    virtual ~ConfigurationReader();

    configVector getMACTableEntriesFromInputFile(std::string inputConfigurationFile);

    configVector getAVBTableEntriesFromInputFile(std::string inputConfigurationFile);

private:
    /*
     * Singleton design pattern: private constructor to prevent instantiation
     */
    ConfigurationReader();

    /*
     *
     */
    void openConfigurationFile(std::string inputConfigurationFile);

    /*
     *
     */
    configVector readOutInputFile();

    /*
     *
     */
    bool isCommentLine(std::string line);

    /*
     *
     */
    std::vector<int> splitFileLineAndGetEntry();

    /*
     * Singleton design pattern: only one instance will be instantiated and is
     * stored here
     */
    static ConfigurationReader* instance;

    /*
     * variable to store the input file stream
     */
    std::ifstream inputFile;

    /*
     * variable to store one line of the input file
     */
    std::string fileLine;

    /*
     *
     */
    configVector macTableVector;

    /*
     *
     */
    configVector avbTableVector;


};

#endif /* SWITCH_FORWARDINGLOGIC_CONFIGURATIONFILEREADERSINGLETONSINGLETON_H_ */
