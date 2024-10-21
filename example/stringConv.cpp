/**
 * @file stringConv.cpp 
 * @author Harith Manoj
 * @brief String COnversion examples.
 * @date 13 October 2024
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


#ifdef EX_EASYPARSE_BINARYSTRING

//! [binaryStringExample]

#include <iostream>
#include <bitset>
#include <easyParseLib/easyParse.h>

#define CONCAT(x, y)                     x##y
#define LIT_COMMA_PAIR(x)                 #x, CONCAT(0b, x)

template<class T>
void checkAndReport(std::string_view binString, T binValue)
{
    std::cout << binString << " >> ";

    auto val = easyParse::convertBinaryString<T>(binString);

    std::cout << std::bitset<sizeof(T) * 8>(val) << "\n";

    if(val != binValue)
    {
        std::cout << "INVALID\n";
    }
}


int main()
{
    checkAndReport<std::uint32_t>(LIT_COMMA_PAIR(1010));
    checkAndReport<std::uint32_t>(LIT_COMMA_PAIR(1011));
    checkAndReport<std::uint32_t>(LIT_COMMA_PAIR(1110));
    checkAndReport<std::uint32_t>(LIT_COMMA_PAIR(1111));
    checkAndReport<std::uint32_t>(LIT_COMMA_PAIR(10101101));
    checkAndReport<std::uint32_t>(LIT_COMMA_PAIR(101110000));
    checkAndReport<std::uint32_t>(LIT_COMMA_PAIR(10101010));
    checkAndReport<std::uint32_t>(LIT_COMMA_PAIR(101110));
    checkAndReport<std::uint32_t>(LIT_COMMA_PAIR(1101010));
    checkAndReport<std::uint32_t>(LIT_COMMA_PAIR(1010010));

    return 0;
}


//! [binaryStringExample]

#elif defined(EX_EASYPARSE_HEXSTRING)

//! [hexStringExample]

#include <iostream>
#include <iomanip>
#include <easyParseLib/easyParse.h>

#define CONCAT(x, y)                     x##y
#define LIT_COMMA_PAIR(x)                 #x, CONCAT(0x, x)

template<class T>
void checkAndReport(std::string_view hexString, T hexValue)
{
    std::cout << hexString << " >> ";

    auto val = easyParse::convertHexString<T>(hexString);

    std::cout << std::hex << val << "\n";

    if(val != hexValue)
    {
        std::cout << "INVALID\n";
    }
}


int main()
{
    checkAndReport<std::uint64_t>(LIT_COMMA_PAIR(1fa0));
    checkAndReport<std::uint64_t>(LIT_COMMA_PAIR(1ed11));
    checkAndReport<std::uint64_t>(LIT_COMMA_PAIR(fed10));
    checkAndReport<std::uint64_t>(LIT_COMMA_PAIR(11fa11));
    checkAndReport<std::uint64_t>(LIT_COMMA_PAIR(101daf101));
    checkAndReport<std::uint64_t>(LIT_COMMA_PAIR(10feb10000));
    checkAndReport<std::uint64_t>(LIT_COMMA_PAIR(101a3e010));
    checkAndReport<std::uint64_t>(LIT_COMMA_PAIR(101456f0));
    checkAndReport<std::uint64_t>(LIT_COMMA_PAIR(1123d010));
    checkAndReport<std::uint64_t>(LIT_COMMA_PAIR(101369f0));

    return 0;
}


//! [hexStringExample]

#elif defined(EX_EASYPARSE_OCTSTRING)

//! [octStringExample]

#include <iostream>
#include <iomanip>
#include <easyParseLib/easyParse.h>

#define CONCAT(x, y)                     x##y
#define LIT_COMMA_PAIR(x)                 #x, CONCAT(0, x)

template<class T>
void checkAndReport(std::string_view octString, T octValue)
{
    std::cout << octString << " >> ";

    auto val = easyParse::convertOctString<T>(octString);

    std::cout << std::oct << val << "\n";

    if(val != octValue)
    {
        std::cout << "INVALID\n";
    }
}


int main()
{
    checkAndReport<std::uint64_t>(LIT_COMMA_PAIR(16770));
    checkAndReport<std::uint64_t>(LIT_COMMA_PAIR(1211));
    checkAndReport<std::uint64_t>(LIT_COMMA_PAIR(367710));
    checkAndReport<std::uint64_t>(LIT_COMMA_PAIR(1123411));
    checkAndReport<std::uint64_t>(LIT_COMMA_PAIR(1014326101));
    checkAndReport<std::uint64_t>(LIT_COMMA_PAIR(10723410000));
    checkAndReport<std::uint64_t>(LIT_COMMA_PAIR(1012334010));
    checkAndReport<std::uint64_t>(LIT_COMMA_PAIR(10145660));
    checkAndReport<std::uint64_t>(LIT_COMMA_PAIR(112323010));
    checkAndReport<std::uint64_t>(LIT_COMMA_PAIR(101365230));

    return 0;
}


//! [octStringExample]

#elif defined(EX_EASYPARSE_DECSTRING)

//! [decStringExample]

#include <iostream>
#include <easyParseLib/easyParse.h>

#define CONCAT(x, y)                     x##y
#define LIT_COMMA_PAIR(x)                 #x, x

template<class T>
void checkAndReport(std::string_view decString, T decValue)
{
    std::cout << decString << " >> ";

    auto val = easyParse::convertDecimalString<T>(decString);

    std::cout << val << "\n";

    if(val != decValue)
    {
        std::cout << "INVALID\n";
    }
}


int main()
{
    checkAndReport<std::uint64_t>(LIT_COMMA_PAIR(16770));
    checkAndReport<std::uint64_t>(LIT_COMMA_PAIR(1211));
    checkAndReport<std::uint64_t>(LIT_COMMA_PAIR(367710));
    checkAndReport<std::uint64_t>(LIT_COMMA_PAIR(1123411));
    checkAndReport<std::uint64_t>(LIT_COMMA_PAIR(1014326101));
    checkAndReport<std::uint64_t>(LIT_COMMA_PAIR(10723410000));
    checkAndReport<std::uint64_t>(LIT_COMMA_PAIR(1012334010));
    checkAndReport<std::uint64_t>(LIT_COMMA_PAIR(10145660));
    checkAndReport<std::uint64_t>(LIT_COMMA_PAIR(112323010));
    checkAndReport<std::uint64_t>(LIT_COMMA_PAIR(101365230));

    return 0;
}


//! [decStringExample]

#elif defined(EX_EASYPARSE_NUMSTRING)

//! [numStringExample]

#include <iostream>
#include <easyParseLib/easyParse.h>

#define CONCAT(x, y)                     x##y
#define LIT_COMMA_PAIR_D(x)                 #x, x
#define LIT_COMMA_PAIR_H(x)                 "0x" #x, CONCAT(0x,x)
#define LIT_COMMA_PAIR_O(x)                 "0" #x, CONCAT(0,x)
#define LIT_COMMA_PAIR_B(x)                 "0b" #x, CONCAT(0b,x)

template<class T>
void checkAndReport(std::string_view numString, T numValue)
{
    std::cout << numString << " >> ";

    auto val = easyParse::convertNumberString<T>(numString);

    std::cout << val << "\n";

    if(val != numValue)
    {
        std::cout << "INVALID\n";
    }
}


int main()
{
    checkAndReport<std::uint64_t>(LIT_COMMA_PAIR_D(167790));
    checkAndReport<std::uint64_t>(LIT_COMMA_PAIR_H(1f2e11));
    checkAndReport<std::uint64_t>(LIT_COMMA_PAIR_O(367710));
    checkAndReport<std::uint64_t>(LIT_COMMA_PAIR_B(10110101));
    checkAndReport<std::uint64_t>(LIT_COMMA_PAIR_D(11234911));
    checkAndReport<std::uint64_t>(LIT_COMMA_PAIR_H(101f01));
    checkAndReport<std::uint64_t>(LIT_COMMA_PAIR_O(10723410000));
    checkAndReport<std::uint64_t>(LIT_COMMA_PAIR_B(10110101));
    checkAndReport<std::uint64_t>(LIT_COMMA_PAIR_D(1094010));
    checkAndReport<std::uint64_t>(LIT_COMMA_PAIR_H(101f60));
    checkAndReport<std::uint64_t>(LIT_COMMA_PAIR_O(112323010));
    checkAndReport<std::uint64_t>(LIT_COMMA_PAIR_B(1101010));
    checkAndReport<std::uint64_t>(LIT_COMMA_PAIR_D(10139930));

    return 0;
}


//! [numStringExample]

#endif


