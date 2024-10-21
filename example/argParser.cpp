/**
 * @file argParser.cpp 
 * @author Harith Manoj
 * @brief Arg Parser example
 * @date 17 October 2024
 * 
 * @copyright Copyright (C) Harith Manoj
 * 
 * 
 *                      APACHE LICENSE 2.0
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * 
 */

//! [ArgParserExample]

#include <iostream>
#include <string_view>

#include <easyParseLib/ArgParser.h>


int main()
{

    std::array arg = {"prgrm", "-bs", "--anotherBoolean", "ON", "-cf1", "--custom2", "cf2", "--argType", "args", "args2", "-bs3", "helloPositional"};

    easyParse::ArgParser parser(arg.size(), arg.data());

    parser.addBoolSwitch("boolSwitch1", "bs", false)
        .addBoolSwitch("anotherboolean", "bs2", false)
        .addOptSwitch("custom1", {"cf1", "cs1", "ct1"}, 1)
        .addOptSwitch("custom2", {"cf2", "cs2", "ct2"}, 1)
        .addArgSwitch("argtype", "arg", {"default"}, {"def2"})
        .addBoolSwitch("boolean3", "bs3", false);

    parser.parse();
    
    std::cout << std::boolalpha;

    for(auto i = parser.posIterator(); i < parser.posSentinal(); ++i)
    {
        std::cout << "POSITIONAL " << i->pos << " >> " << i->arg << "\n";
    }

    for(auto i = parser.argIterator(); i < parser.argSentinal(); ++i)
    {
        std::cout << "ARGUMENT   " << i->longForm << " / " << i->shortForm << " : " << i->overridden;

        for(auto argVal : i->setValue)
            std::cout << " : " << argVal;

        std::cout << "\n";
    }

    for(auto i = parser.optIterator(); i < parser.optSentinal(); ++i)
    {
        std::cout << "OPTIONAL   " << i->longForm << " / ";

        for(auto optVal : i->options)
            std::cout << " : " << optVal;

        std::cout << " : " << i->overridden << " >> " << i->options[i->setValue] << "\n";
    }

    for(auto i = parser.boolIterator(); i < parser.boolSentinal(); ++i)
    {
        std::cout << "BOOLEAN    " << i->longForm << " / " << i->shortForm << " : " << i->overridden << " >> " << i->setValue << "\n";
    }

    return 0;
}


//! [ArgParserExample]



