/**
 * @file isPowerOfTwo.cpp 
 * @author Harith Manoj
 * @brief Example to check overflow and underflow of add operations.
 * @date 25 September 2024
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

#ifdef EX_EASYMATH_DIVIDEROUNDUP

//! [divideRoundUpExample]

#include <iostream>
#include <easyMathLib/easyMath.h>

#define REPORT(x)               #x << " " << x << "\n"

int main()
{

    constexpr int a = 100;
    constexpr auto log_a = easyMath::divideRoundUp(a, 12);
    constexpr unsigned b = 32;

    std::cout << REPORT(easyMath::divideRoundUp(10, 3))
        << REPORT(easyMath::divideRoundUp(30, 40))
        << REPORT(easyMath::divideRoundUp(8, 13))
        << REPORT(easyMath::divideRoundUp(2, 1))
        << REPORT(easyMath::divideRoundUp(16, 9))
        << REPORT(easyMath::divideRoundUp(64u, 33u))
        << REPORT(easyMath::divideRoundUp(56ull, 20ull))
        << REPORT(easyMath::divideRoundUp(32ll, 8ll))
        << REPORT(easyMath::divideRoundUp(128ull, 33ull))
        << REPORT(easyMath::divideRoundUp(23, 12))
        << REPORT(easyMath::divideRoundUp(b, 26u))
        << REPORT(easyMath::divideRoundUp(64ll, 27ll))
        << REPORT(easyMath::divideRoundUp(1024ull, 2ull))
        << "constexpr " << REPORT(log_a);
}



//! [divideRoundUpExample]

#elif defined(EX_EASYMATH_NBITMASK)

//! [nBitMaskExample]


#include <iostream>
#include <bitset>
#include <easyMathLib/easyMath.h>

#define REPORT(x)               std::bitset<sizeof(x) * 8>(x) << " : " << #x << "\n"

int main()
{

    constexpr int a = 30;
    constexpr auto mask_a = easyMath::nBitMask<std::uint64_t>(a);
    constexpr unsigned b = 32;

    std::cout << REPORT(easyMath::nBitMask<std::uint64_t>(10))
        << REPORT(easyMath::nBitMask<std::uint64_t>(40))
        << REPORT(easyMath::nBitMask<std::uint64_t>(13))
        << REPORT(easyMath::nBitMask<std::uint64_t>(2))
        << REPORT(easyMath::nBitMask<std::uint64_t>(16))
        << REPORT(easyMath::nBitMask<std::uint64_t>(33u))
        << REPORT(easyMath::nBitMask<std::uint64_t>(56ull))
        << REPORT(easyMath::nBitMask<std::uint64_t>(32ll))
        << REPORT(easyMath::nBitMask<std::uint64_t>(53ull))
        << REPORT(easyMath::nBitMask<std::uint64_t>(23))
        << REPORT(easyMath::nBitMask<std::uint64_t>(b))
        << REPORT(easyMath::nBitMask<std::uint64_t>(37ll))
        << REPORT(easyMath::nBitMask<std::uint64_t>(62ull))
        << REPORT(mask_a);
}

//! [nBitMaskExample]

#elif defined(EX_EASYMATH_EXTRACTBITS)

//! [extractBitsExample]

#include <iostream>
#include <bitset>
#include <easyMathLib/easyMath.h>

#define REPORT(x, y)               std::bitset<64>(x) << " : " << std::bitset<64>(y) << " : " << #y << "\n"

int main()
{

    constexpr int a = 30;
    constexpr auto extract_a = easyMath::extractBits<std::uint64_t>(a, 2, 10);
    constexpr unsigned b = 32;

    std::cout << REPORT(10, easyMath::extractBits<std::uint64_t>(10, 3, 20))
        << REPORT(40, easyMath::extractBits<std::uint64_t>(40, 4, 10))
        << REPORT(13, easyMath::extractBits<std::uint64_t>(13, 2, 40))
        << REPORT(2, easyMath::extractBits<std::uint64_t>(2, 3, 10))
        << REPORT(16, easyMath::extractBits<std::uint64_t>(16, 2, 40))
        << REPORT(33u, easyMath::extractBits<std::uint64_t>(33u, 1, 20))
        << REPORT(56ull, easyMath::extractBits<std::uint64_t>(56ull, 7, 20))
        << REPORT(32ll, easyMath::extractBits<std::uint64_t>(32ll, 8, 12))
        << REPORT(53ull, easyMath::extractBits<std::uint64_t>(53ull, 2, 12))
        << REPORT(23, easyMath::extractBits<std::uint64_t>(23, 2, 14))
        << REPORT(b, easyMath::extractBits<std::uint64_t>(b, 5, 12))
        << REPORT(37ll, easyMath::extractBits<std::uint64_t>(37ll, 5, 7))
        << REPORT(62ull, easyMath::extractBits<std::uint64_t>(62ull, 7, 8))
        << REPORT(a, extract_a);
}

//! [extractBitsExample]

#endif

