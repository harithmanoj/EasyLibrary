/**
 * @file argParser.cpp 
 * @author Harith Manoj
 * @brief arg parser class definitions
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

#include <easyParseLib/ArgParser.h>

namespace easyParse
{
    void ArgParser::parse()
    {
        enum class ArgType {
            SHORT, LONG, POSITIONAL
        };

        auto checkType = [](std::string_view arg)
        {
            if(arg[0] == '-')
            {
                if(arg.size() == 1)
                    throw std::invalid_argument("'-' is not a valid argument");
                else if(arg[1] == '-')
                    return ArgType::LONG;
                else
                    return ArgType::SHORT;
            }
            else
                return ArgType::POSITIONAL;
        };

        for(int i = 1; i < argc_; ++i)
        {
            std::string_view arg = argv_[i];

            auto argType = checkType(arg);

            if(argType == ArgType::POSITIONAL)
            {
                posArgList_.emplace_back(arg, i);
                continue;
            }
            else if(argType == ArgType::SHORT)
            {
                std::string shortForm = toLower(arg.substr(1));   
                bool found = false;                                     

                for(auto& sw : boolSwitchList_)
                {
                    if(sw.shortForm.empty())
                        continue;

                    if(sw.shortForm == shortForm)
                    {
                        sw.setValue = true;
                        sw.overridden = true;
                        found = true;
                        break;
                    }
                }

                if(found)
                    continue;

                for(auto& sw : argSwitchList_)
                {
                    if(sw.shortForm.empty())
                        continue;
                    if(sw.shortForm == shortForm)
                    {
                        sw.setValue = sw.shortFormValue;
                        sw.overridden = true;
                        found = true;
                        break;
                    }
                }  

                if(found)
                    continue;       

                for(auto& sw : optSwitchList_)
                {
                    for(std::size_t j = 0; j < sw.options.size(); ++j)
                    {

                        if(sw.options[j] == shortForm)
                        {
                            sw.setValue = j;
                            sw.overridden = true;
                            found = true;
                            break;
                        }
                    }

                    if(found)
                        break;
                }

                if(found)
                    continue;   
                
                throw std::invalid_argument("Unknown Switch");
            }
            else if(argType == ArgType::LONG)
            {
                std::string longForm = toLower(arg.substr(2));
                bool found = false;

                for(auto& sw : boolSwitchList_)
                {
                    if(sw.longForm.empty())
                        continue;
                    if(sw.longForm == longForm)
                    {
                        ++i;
                        if(i >= argc_)
                            throw std::invalid_argument("Long Boolean switch must have OFF / ON argument");
                        
                        std::string boolArg = toLower(argv_[i]);

                        constexpr std::array onValues = {"on", "y", "yes"};
                        constexpr std::array offValues = {"off", "n", "no"};

                        for(const auto& str : onValues)
                        {
                            if(boolArg == str)
                            {
                                sw.setValue = true;
                                sw.overridden = true;
                                found = true;
                                break;
                            }
                        }

                        if(found)
                            break;
                        
                        for(const auto& str : offValues)
                        {
                            if(boolArg == str)
                            {
                                sw.setValue = false;
                                sw.overridden = true;
                                found = true;
                                break;
                            }
                        }

                        if(found)
                            break;
                        
                        throw std::invalid_argument("Invalid argument to boolean switch");

                    }
                }

                if(found)
                    continue; 

                for(auto& sw : argSwitchList_)
                {
                    if(sw.longForm.empty())
                        continue;
                    if(sw.longForm == longForm)
                    {
                        sw.setValue.clear();
                        while((++i) < argc_)
                        {
                            auto argType = checkType(argv_[i]);
                            if(argType != ArgType::POSITIONAL)
                            {
                                --i;
                                found = true;
                                break;
                            }
                            sw.setValue.emplace_back(argv_[i]);
                            sw.overridden = true;
                        }
                        break;
                    }
                }

                if(found)
                    continue; 

                for(auto& sw : optSwitchList_)
                {
                    if(sw.longForm.empty())
                        continue;
                    if(sw.longForm == longForm)
                    {
                        ++i;

                        if(i >= argc_)
                            throw std::invalid_argument("Long opt switch must have an argument");

                        std::string opt = toLower(argv_[i]);

                        for(std::size_t j = 0; j < sw.options.size(); ++j)
                        {
                            if(sw.options[j] == opt)
                            {
                                sw.setValue = j;
                                sw.overridden = true;
                                found = true;
                                break;
                            }
                        }
                        if(!found)
                            throw std::invalid_argument("Invalid argument to opt switch");

                        break;
                    }
                }
            }
        }
    }
}
