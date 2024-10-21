/**
 * @file clog2.cpp 
 * @author Harith Manoj
 * @brief clog2 test.
 * @date 19 October 2024
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


#include <iostream>
#include <string>
#include <cmath>
#include <random>

#include <easyMathLib/easyMath.h>

template<class T>
constexpr bool validateExclusive(T value, T rangeLow, T rangeHigh, bool exclusive)
{
    return (easyMath::valueBetween(value, rangeLow, rangeHigh) == exclusive);
}

template<class T>
constexpr bool validateInclusive(T value, T rangeLow, T rangeHigh, bool inclusive)
{
    return (easyMath::valueBetweenInclusive(value, rangeLow, rangeHigh) == inclusive);
}

template<class T>
void log(T value, T rangeLow, T rangeHigh, bool inclusive, bool exclusive)
{
    std::cout << (validateExclusive(value, rangeLow, rangeHigh, exclusive) ? "PASS " : "FAIL ") << value << " in (" << rangeLow << ", " << rangeHigh << ")\n";
    std::cout << (validateInclusive(value, rangeLow, rangeHigh, inclusive) ? "PASS " : "FAIL ") << value << " in [" << rangeLow << ", " << rangeHigh << "]\n";
}

#define STATIC_VALIDATE(val, low, high, exclusive, inclusive)       static_assert(validateExclusive(val, low, high, exclusive), "Validate " #val " in (" #low ", " #high ")");\
                                                                    std::cout << "PASS " << val << " in (" << low << ", " << high << ")\n";\
                                                                    static_assert(validateInclusive(val, low, high, inclusive), "Validate " #val " in [" #low ", " #high "]");\
                                                                    std::cout << "PASS " << val << " in [" << low << ", " << high << "]\n";\

constexpr std::size_t COUNT = 10;

int main()
{

    STATIC_VALIDATE(5, 1, 6, true, true);
    STATIC_VALIDATE(3, 1, 6, true, true);
    STATIC_VALIDATE(1, 1, 6, false, true);
    STATIC_VALIDATE(6, 1, 6, false, true);
    STATIC_VALIDATE(-20, 1, 6, false, false);
    STATIC_VALIDATE(10, 1, 6, false, false);

    std::cout << "PASS Compile time checks\n";

    std::random_device rd;
    std::mt19937_64 rng(rd());

    std::uniform_int_distribution<long> gen(-10000, 10000);

    for(std::size_t i = 0; i < COUNT; ++i)
    {
        auto val = gen(rng);
        log(val, val - 100, val + 100, true, true);
        log(val, val - 200, val + 200, true, true);
        log(val, val, val + 100, true, false);
        log(val, val - 100, val, true, false);
        log(val, val + 10, val + 100, false, false);
        log(val, val - 100, val - 10, false, false);
    }
}




