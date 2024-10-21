/**
 * @file advance.cpp 
 * @author Harith Manoj
 * @brief advance over string parser examples.
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


//! [advanceOverTextExample]

#include <iostream>
#include <easyParseLib/easyParse.h>

int main()
{
    std::string_view str = "hello\\n\\tyo";

    auto it = str.cbegin();

    while(it < str.cend())
    {
        std::cout << *it << " : ";
        auto ret = easyParse::advanceOverText(it, str.cend());

        if(ret.first == '\n')
            std::cout << "\\n";
        else if(ret.first == '\t')
            std::cout << "\\t";
        else
            std::cout << ret.first;

        std::cout << " : " << std::boolalpha << ret.second << " >> ";
        
        if(it < str.cend())
            std::cout << *it << "\n";
        else
            std::cout << "end\n";
    }

}


//! [advanceOverTextExample]




