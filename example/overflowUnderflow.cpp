/**
 * @file overflowUnderflow.cpp 
 * @author Harith Manoj
 * @brief Example to check overflow and underflow of add operations.
 * @date 17 September 2024
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


//! [overflowUnderflowExample]


#include <iostream>

#include <easyMathLib/easyMath.h>

#define REPORT(x)               #x << "\t\t= " << x << "\n"



class IntWrapper
{
    int value;

public:
    IntWrapper() : value(0) {}
    IntWrapper(int val_) : value(val_) {}
    IntWrapper(const IntWrapper&) = default;
    IntWrapper(IntWrapper&&) = default;

    IntWrapper& operator += (const IntWrapper& rhs) noexcept { value += rhs.value; return *this; }
    IntWrapper& operator -= (const IntWrapper& rhs) noexcept { value -= rhs.value; return *this; }
    IntWrapper& operator *= (const IntWrapper& rhs) noexcept { value *= rhs.value; return *this; }
    IntWrapper& operator /= (const IntWrapper& rhs) noexcept { value /= rhs.value; return *this; }

    IntWrapper operator + (const IntWrapper& rhs) const noexcept { return value + rhs.value; }
    IntWrapper operator - (const IntWrapper& rhs) const noexcept { return value - rhs.value; }
    IntWrapper operator * (const IntWrapper& rhs) const noexcept { return value * rhs.value; }
    IntWrapper operator / (const IntWrapper& rhs) const noexcept { return value / rhs.value; }

    operator int() const noexcept { return value; }

    std::strong_ordering operator <=>(const IntWrapper& rhs) const noexcept { return value <=> rhs.value; }

    static bool willAddOverflow(const IntWrapper& lhs, const IntWrapper& rhs, const IntWrapper& max = easyMath::NumericTraits<int>::max()) noexcept
    {
        std::cout << "\t\t Use member overflow check: ";
        return easyMath::willAddOverflow<int>(lhs, rhs, max);
    }
};

namespace easyMath
{
    template<>
    class NumericTraits<IntWrapper> : public std::numeric_limits<int>, public easyMath::SelfCheckingNumericTraits<IntWrapper>
    {};
}

int main()
{
    static_assert(easyMath::NumericType<IntWrapper>, "IntWrapper compliance fail");

    std::cout << std::boolalpha;
    std::cout   << REPORT(easyMath::willAddOverflow<std::uint32_t>(0, 2))
                << REPORT(easyMath::willAddOverflow<std::uint32_t>(easyMath::NumericTraits<std::uint32_t>::max(), 10))
                << REPORT(easyMath::willAddOverflow<std::int32_t>(20, 30))
                << REPORT(easyMath::willAddOverflow<std::int32_t>(-20, -30))
                << REPORT(easyMath::willAddOverflow<std::int32_t>(-20, 30))
                << REPORT(easyMath::willAddOverflow<std::int32_t>(20, -30))
                << REPORT(easyMath::willAddOverflow<std::int32_t>(easyMath::NumericTraits<std::int32_t>::max(), 10))
                << REPORT(easyMath::willAddOverflow<std::int32_t>(easyMath::NumericTraits<std::int32_t>::lowest(), -20));
    
    
    std::cout   << REPORT(easyMath::willSubtractUnderflow<std::uint32_t>(20, 2))
                << REPORT(easyMath::willSubtractUnderflow<std::uint32_t>(easyMath::NumericTraits<std::uint32_t>::lowest(), 10))
                << REPORT(easyMath::willSubtractUnderflow<std::int32_t>(20, 30))
                << REPORT(easyMath::willSubtractUnderflow<std::int32_t>(-20, -30))
                << REPORT(easyMath::willSubtractUnderflow<std::int32_t>(-20, 30))
                << REPORT(easyMath::willSubtractUnderflow<std::int32_t>(20, -30))
                << REPORT(easyMath::willSubtractUnderflow<std::int32_t>(easyMath::NumericTraits<std::int32_t>::max(), -10))
                << REPORT(easyMath::willSubtractUnderflow<std::int32_t>(easyMath::NumericTraits<std::int32_t>::lowest(), 10));
}


//! [overflowUnderflowExample]
