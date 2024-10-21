/**
 * @file easyMath.h 
 * @author Harith Manoj
 * @brief EasyMath library methods
 * @date 12 April 2024
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

#ifndef INCLUDE_EASYMATHLIB_EASYMATH_H_INCLUDED

/// @brief include\easyMathLib\easyMath.h Header Guard 
#define INCLUDE_EASYMATHLIB_EASYMATH_H_INCLUDED

#include <cmath>
#include <vector>
#include <ranges>
#include <cstdint>
#include <bit>

#include <easyLib/version.h>

/// @brief encapsulate math library code.
namespace easyMath
{

    /// @brief Namespace to store meta information, like version.
    namespace meta = easyLib::meta;

    /**
     * @brief identify whether the value is between the two values. (not inclusive)
     * 
     * @tparam T Type of value to check.
     * @param[in] value value to evaluate.
     * @param[in] begin range begin.
     * @param[in] end range end.
     * @return true begin < value < end.
     * 
     * <b>Example </b>
     * 
     * \snippet{lineno} valueBetween.cpp valueBetweenExample
     * 
     * Console Output:
     * \include{lineno} valueBetween.out.txt
     */
    template<class T>
    [[nodiscard]] inline constexpr bool valueBetween(T value, T begin, T end) noexcept
    {
        return (value > begin) && (value < end);
    }
    
    /**
     * @brief Identify whether the value is between the two values. (inclusive)
     * 
     * @tparam T Type of value to check.
     * @param[in] value value to evaluate.
     * @param[in] begin range begin.
     * @param[in] end range end.
     * @return true begin <= value <= end.
     * 
     * <b>Example </b>
     * 
     * \snippet{lineno} valueBetween.cpp valueBetweenExample
     * 
     * Console Output:
     * \include{lineno} valueBetween.out.txt
     */
    template<class T>
    [[nodiscard]] inline constexpr bool valueBetweenInclusive(T value, T begin, T end) noexcept
    {
        return (value >= begin) && (value <= end);
    }

    /**
     * @brief Check if type is numeric type, must have mathamatical operator and converters.
     * 
     * @tparam Numeric Type to check.
     * 
     * Must overload:
     * 
     * @conceptMember{Math Operators}
     * 
     * - `[Numeric] operator + (const Numeric&, const Numeric&);`
     * - `[Numeric] operator - (const Numeric&, const Numeric&);`
     * - `[Numeric] operator * (const Numeric&, const Numeric&);`
     * - `[Numeric] operator / (const Numeric&, const Numeric&);`
     * - `Numeric& operator += (Numeric&, const Numeric&);`
     * - `Numeric& operator -= (Numeric&, const Numeric&);`
     * - `Numeric& operator *= (Numeric&, const Numeric&);`
     * - `Numeric& operator /= (Numeric&, const Numeric&);`
     * 
     * @conceptMember{Relational Operators}
     * 
     * - `[bool] operator == (const Numeric&, const Numeric&);`
     * - `[bool] operator != (const Numeric&, const Numeric&);`
     * - `[bool] operator <= (const Numeric&, const Numeric&);`
     * - `[bool] operator >= (const Numeric&, const Numeric&);`
     * - `[bool] operator < (const Numeric&, const Numeric&);`
     * - `[bool] operator > (const Numeric&, const Numeric&);`
     * 
     * @conceptMember{Type Conversion}
     * 
     * - Type convert to and from: `std::uint64_t`.
     * - Type convert to and from: `std::uint32_t`.
     * - Type convert to and from: `std::uint16_t`.
     * - Type convert to and from: `std::uint8_t`.
     * - Type convert to and from: `std::int64_t`.
     * - Type convert to and from: `std::int32_t`.
     * - Type convert to and from: `std::int16_t`.
     * - Type convert to and from: `std::int8_t`.
     * - Type convert to and from: `float`.
     * - Type convert to and from: `double`.
     * - Type convert to and from: `long double`.
     * 
     */
    template<class Numeric>
    concept NumericType = requires(const Numeric& clhs, const Numeric& crhs, Numeric& lhs, std::uint64_t cuintVal, std::int64_t cintVal)
    {
        {clhs + crhs} -> std::convertible_to<Numeric>;
        {clhs - crhs} -> std::convertible_to<Numeric>;
        {clhs * crhs} -> std::convertible_to<Numeric>;
        {clhs / crhs} -> std::convertible_to<Numeric>;
        {clhs == crhs} -> std::convertible_to<bool>;
        {clhs != crhs} -> std::convertible_to<bool>;
        {clhs < crhs} -> std::convertible_to<bool>;
        {clhs <= crhs} -> std::convertible_to<bool>;
        {clhs >= crhs} -> std::convertible_to<bool>;
        {clhs > crhs} -> std::convertible_to<bool>;        
        {lhs += crhs} -> std::same_as<Numeric&>;
        {lhs -= crhs} -> std::same_as<Numeric&>;
        {lhs *= crhs} -> std::same_as<Numeric&>;
        {lhs /= crhs} -> std::same_as<Numeric&>;

        requires std::convertible_to<Numeric, std::uint64_t>;
        requires std::convertible_to<Numeric, std::uint32_t>;
        requires std::convertible_to<Numeric, std::uint16_t>;
        requires std::convertible_to<Numeric, std::uint8_t>;
        requires std::convertible_to<Numeric, std::int64_t>;
        requires std::convertible_to<Numeric, std::int32_t>;
        requires std::convertible_to<Numeric, std::int16_t>;
        requires std::convertible_to<Numeric, std::int8_t>;
        requires std::convertible_to<std::uint64_t, Numeric>;
        requires std::convertible_to<std::uint32_t, Numeric>;
        requires std::convertible_to<std::uint16_t, Numeric>;
        requires std::convertible_to<std::uint8_t, Numeric>;
        requires std::convertible_to<std::int64_t, Numeric>;
        requires std::convertible_to<std::int32_t, Numeric>;
        requires std::convertible_to<std::int16_t, Numeric>;
        requires std::convertible_to<std::int8_t, Numeric>;
        requires std::convertible_to<Numeric, float>;
        requires std::convertible_to<Numeric, double>;
        requires std::convertible_to<Numeric, long double>;
        requires std::convertible_to<float, Numeric>;
        requires std::convertible_to<double, Numeric>;
        requires std::convertible_to<long double, Numeric>;
    };

    /**
     * @brief Numeric traits that can be automatically deduced. (eg concept based).
     * 
     * @tparam Numeric Type for traits to be deduced.
     */
    template<NumericType Numeric>
    struct SelfCheckingNumericTraits
    {
        /// @brief Checks whether type has a static member function to evaluate add overflow.
        ///
        /// Member Function must be of signature: `[bool] willAddOverflow([const] Numeric[&] lhs, [const] Numeric[&] rhs, [const] Numeric[&] max);`
        /// 
        /// Function should return `true` (equivalent) if the `lhs + rhs` operation results in value greater than `max`.
        static constexpr bool isOverflowCheckable = requires(const Numeric& lhs, const Numeric& rhs, const Numeric& max)
        {
            { Numeric::willAddOverflow(lhs, rhs, max) } -> std::convertible_to<bool>;
        };

        /**
         * @brief Checks whether type has a static member function to evaluate subtract underflow.
         * 
         * Member Function must of signature: `[bool] willSubtractUnderflow([const] Numeric[&] lhs, [const] Numeric[&] rhs, [const] Numeric[&] lowest);`
         * 
         * Function should return `true` (equivalent) if the `lhs - rhs` operation results in value lesser than `lowest`.
         */
        static constexpr bool isUnderflowCheckable = requires(const Numeric& lhs, const Numeric& rhs, const Numeric& lowest)
        {
            { Numeric::willSubtractUnderflow(lhs, rhs, lowest) } -> std::convertible_to<bool>;
        };

        /**
         * @brief Checks whether type is custom sized or has method to find bit size.
         * 
         * Must have static member function:
         * `[std::size_t] bitSize() noexcept;`
         * 
         */
        static constexpr bool isCustomSized = requires 
        {
            {Numeric::bitSize()} -> std::convertible_to<std::size_t>;
            noexcept(Numeric::bitSize());
        };

        /**
         * @brief Checks whether type has method to generate bit masks.
         * 
         * Must have static member function:
         * `Numeric nBitMask(std::size_t) noexcept;`
         * 
         */
        static constexpr bool hasBitMaskGenerator = requires(std::size_t maskSize)
        {
            { Numeric::nBitMask(maskSize) } -> std::same_as<Numeric>;
            noexcept(Numeric::nBitMask(maskSize));
        };
    };

    /**
     * @brief Specializable and extended `std::numeric_limits`.
     * 
     * @tparam Numeric Type for traits to be provided.
     */
    template<NumericType Numeric>
    struct NumericTraits : public std::numeric_limits<Numeric>, public SelfCheckingNumericTraits<Numeric>
    {
        /// @brief Whether the type is an integer type and can be bit manipulated assuming data storage is in 2's complement integer format (if signed).
        static constexpr bool is2sCompRepInteger = std::numeric_limits<Numeric>::is_integer;
    };

    /**
     * @brief Check if type is Integer of standard 2's complement representation if signed, and standard representation if unsigned.
     * 
     * @tparam Integer type to check.
     */
    template<class Integer>
    concept IntegerRepresentation = NumericTraits<Integer>::is2sCompRepInteger;

    namespace impl_detail_
    {
        /**
         * @brief Check if type has bitwise operators.
         * 
         * @tparam Integer type to check.
         * 
         * Must Satisfy: `NumericType`.
         * 
         * Must Overload:
         * 
         * @conceptMember{Bitwise Operators}
         * 
         * - `[Integer] operator & (const Integer&, const Integer&);`
         * - `[Integer] operator | (const Integer&, const Integer&);`
         * - `[Integer] operator ^ (const Integer&, const Integer&);`
         * - `Integer& operator &= (Integer&, const Integer&);`
         * - `Integer& operator |= (Integer&, const Integer&);`
         * - `Integer& operator ^= (Integer&, const Integer&);`
         * 
         */
        template<class Integer>
        concept BitWiseOperable_ = requires(const Integer& clhs, const Integer& crhs, Integer& lhs)
        {
            requires NumericType<Integer>;
            {clhs & crhs} -> std::convertible_to<Integer>;
            {clhs | crhs} -> std::convertible_to<Integer>;
            {clhs ^ crhs} -> std::convertible_to<Integer>;
            {lhs &= crhs} -> std::same_as<Integer&>;
            {lhs |= crhs} -> std::same_as<Integer&>;
            {lhs ^= crhs} -> std::same_as<Integer&>;
        };
    }

    /// @brief extendable concept for Integral types, extend by specializing `NumericTraits`.
    template<class Integer>
    concept Integral = NumericTraits<Integer>::is_integer;

    /// @brief extendable concept for Unsigned Integral types, extend by specializing `NumericTraits`.
    template<class UInt>
    concept UnsignedIntegral = (!NumericTraits<UInt>::is_signed) && Integral<UInt> && impl_detail_::BitWiseOperable_<UInt>;

    /// @brief extendable concept for Unsigned Integral types, extend by specializing `NumericTraits`.
    template<class SInt>
    concept SignedIntegral = (NumericTraits<SInt>::is_signed) && Integral<SInt>;

    namespace impl_detail_
    {
        template<NumericType Numeric>
        [[nodiscard]] inline constexpr bool checkPositiveOverflow_(Numeric lhs, Numeric rhs, Numeric max)
        {
            return (max - lhs) < rhs;
        }

        template<NumericType Numeric>
        [[nodiscard]] inline constexpr bool checkNegativeOverflow_(Numeric lhs, Numeric rhs, Numeric lowest)
        {
            return lhs < (lowest + rhs);
        }
    }

    /**
     * @brief Check if addition of arguments will overflow.
     * 
     * @tparam Numeric Numeric type to use.
     * @param[in] lhs left hand side of operation.
     * @param[in] rhs right hand side of operation.
     * @param[in] max maximum allowed (or possible) value.
     * @return true if addition overflows.
     * 
     * <b>Example </b>
     * 
     * \snippet{lineno} overflowUnderflow.cpp overflowUnderflowExample
     * 
     * Console Output:
     * \include{lineno} overflowUnderflow.out.txt
     */
    template<class Numeric>
    [[nodiscard]] inline constexpr bool willAddOverflow(
        Numeric lhs,
        Numeric rhs,
        Numeric max = NumericTraits<Numeric>::max(),
        Numeric lowest = NumericTraits<Numeric>::lowest()
    ) noexcept
    {
        if constexpr (NumericTraits<Numeric>::isOverflowCheckable)
            return Numeric::willAddOverflow(lhs, rhs, max);
        else if constexpr (NumericTraits<Numeric>::is_signed)
        {
            if((lhs < 0) && (rhs < 0))
                return impl_detail_::checkNegativeOverflow_(lhs, -rhs, lowest);
            else if((lhs > 0) && (rhs > 0))
                return impl_detail_::checkPositiveOverflow_(lhs, rhs, max);
            else 
                return false;
        }
        else
            return impl_detail_::checkPositiveOverflow_(lhs, rhs, max);
    }

    /**
     * @brief Chech if subtraction of arguments will underflow. 
     * 
     * @tparam Numeric type to use.
     * @param[in] lhs left hand side of operation.
     * @param[in] rhs right hand side of operation.
     * @param[in] lowest lowest allowed (or possible) value.
     * @return true if subtraction underflows.
     * 
     * <b>Example </b>
     * 
     * \snippet{lineno} overflowUnderflow.cpp overflowUnderflowExample
     * 
     * Console Output:
     * \include{lineno} overflowUnderflow.out.txt
     */
    template<class Numeric>
    [[nodiscard]] inline constexpr bool willSubtractUnderflow(
        Numeric lhs,
        Numeric rhs,
        Numeric max = NumericTraits<Numeric>::max(),
        Numeric lowest = NumericTraits<Numeric>::lowest()
    ) noexcept
    {
        if constexpr (NumericTraits<Numeric>::isUnderflowCheckable)
            return Numeric::willSubtractUnderflow(lhs, rhs, lowest);
        else if constexpr (NumericTraits<Numeric>::is_signed)
        {
            if((lhs < 0) && (rhs > 0))
                return impl_detail_::checkNegativeOverflow_(lhs, rhs, lowest);
            else if((lhs > 0) && (rhs < 0))
                return impl_detail_::checkPositiveOverflow_(lhs, -rhs, max);
            else 
                return false;
        }
        else
            return impl_detail_::checkNegativeOverflow_(lhs, rhs, lowest);
    }

    /**
     * @brief Add lhs, rhs, and previous overflow (carry in) and report if overflow exists.
     * 
     * @tparam Numeric Basic type to use.
     * @param[inout] lhs left hand side of add operation.
     * @param[in] rhs right hand side of add operation.
     * @param[in] lastOpOverflow overflow in previous add operation (carry in).
     * @param[in] max maximum allowed (or possible) value.
     * @return true if add overflows (carry out).
     */
    template<class Numeric>
    inline constexpr bool addAndCheckOverflow(
        Numeric& lhs,
        Numeric rhs,
        bool lastOpOverflow = false,
        Numeric max = NumericTraits<Numeric>::max()
    ) noexcept
    {
        std::uint8_t addOverflowPrevious = (lastOpOverflow? 1 : 0);
        auto overflow = willAddOverflow<Numeric>(lhs, rhs, max);
        lhs += rhs;
        overflow = overflow || willAddOverflow<Numeric>(lhs, addOverflowPrevious, max);
        lhs += addOverflowPrevious;
        return overflow;
    }

    /**
     * @brief Add lhs, rhs, and previous overflow (carry in) and report if overflow exists.
     * 
     * @tparam Numeric Basic type to use.
     * @param[inout] sum destination of add operation.
     * @param[in] lhs left hand side of add operation.
     * @param[in] rhs right hand side of add operation.
     * @param[in] lastOpOverflow overflow in previous add operation (carry in).
     * @param[in] max maximum allowed (or possible) value.
     * @return true if add overflows (carry in).
     */
    template<class Numeric>
    inline constexpr bool addAndCheckOverflow(
        Numeric& sum,
        Numeric lhs,
        Numeric rhs,
        bool lastOpOverflow = false,
        Numeric max = NumericTraits<Numeric>::max()
    ) noexcept
    {
        sum = lhs;
        return addAndCheckOverflow<Numeric>(sum, rhs, lastOpOverflow, max);
    }


    /**
     * @brief Acquire bitsize of each item.
     * 
     * @tparam Integer type of item to evaluate.
     * @return std::size_t number of bits.
     */
    template<Integral Integer>
    [[nodiscard]] inline consteval std::size_t bitSize() noexcept
    {
        if constexpr (NumericTraits<Integer>::isCustomSized)
            return Integer::bitSize();
        else
            return sizeof(Integer) * 8;
    }

    /// @brief Implementation helper code.
    namespace impl_detail_
    {
        /**
         * @brief Selects either 32 or 64 bit integer (signed | unsigned) 
         * depending on size.
         * 
         * @tparam bitSize size in bits required.
         * @tparam isSigned wether signed integer to use.
         */
        template<std::size_t bitSize, bool isSigned = false>
        using Integer32ThresholdSize_ = std::conditional_t<
            bitSize <= 32,
            std::conditional_t<isSigned, std::int32_t, std::uint32_t>,
            std::conditional_t<isSigned, std::int64_t, std::uint64_t>
        >;

        /**
         * @brief Selects either 16, 32 or 64 bit integer (signed | unsigned) 
         * depending on size.
         * 
         * @tparam bitSize size in bits required.
         * @tparam isSigned wether signed integer to use.
         */
        template<std::size_t bitSize, bool isSigned = false>
        using Integer16ThresholdSize_ = std::conditional_t<
            bitSize <= 16,
            std::conditional_t<isSigned, std::int16_t, std::uint16_t>,
            Integer32ThresholdSize_<bitSize, isSigned>
        >;

        
        /**
         * @brief Selects either 8, 16, 32 or 64 bit integer (signed | unsigned) 
         * depending on size.
         * 
         * @tparam bitSize size in bits required.
         * @tparam isSigned wether signed integer to use.
         */
        template<std::size_t bitSize, bool isSigned = false>
        using Integer8ThresholdSize_ = std::conditional_t<
            bitSize <= 8,
            std::conditional_t<isSigned, std::int8_t, std::uint8_t>,
            Integer16ThresholdSize_<bitSize, isSigned>
        >;

    }

    /**
     * @brief Selects smallest possible unsigned integer type depending on size 
     * required.
     * 
     * @tparam bitSize size in bits required.
     */
    template<std::size_t bitSize>
    using SizeCapableUint = impl_detail_::Integer8ThresholdSize_<bitSize, false>;

    /**
     * @brief Selects smallest possible signed integer type depending on size 
     * required.
     * 
     * @tparam bitSize size in bits required.
     */
    template<std::size_t bitSize>
    using SizeCapableInt = impl_detail_::Integer8ThresholdSize_<bitSize, true>;

    /**
     * @brief Selects smallest possible unsigned integer type depending on max 
     * value required.
     * 
     * @tparam maxValue maximum value to be supported.
     */
    template<std::size_t maxValue>
    using MaxCapableUint = SizeCapableUint<std::bit_width(maxValue)>;

    /**
     * @brief Get rounded up result of division.
     * 
     * @tparam Numeric Number type.
     * @param[in] numerator numerator of division.
     * @param[in] denominator denominator of division.
     * @return Numeric division result.
     * 
     * <b>Example </b>
     * 
     * \snippet{lineno} isPowerOfTwo.cpp divideRoundUpExample
     * 
     * Console Output:
     * \include{lineno} divideRoundUp.out.txt
     */
    template<Integral Numeric>
    [[nodiscard]] inline constexpr Numeric divideRoundUp(
        const Numeric& numerator,
        const Numeric& denominator
    ) noexcept
    {
        auto remainder = numerator % denominator;
        auto ret = numerator / denominator;

        if(remainder != 0)
            ++ret;
        
        return ret;        
    }

    /**
     * @brief Select Larger type from the two. (Selection based on `bitSize` method).
     */
    template<Integral TypeA, Integral TypeB>
    using LargerType = std::conditional_t<bitSize<TypeA>() < bitSize<TypeB>(), TypeB, TypeA>;

    /**
     * @brief Select Smaller type from the two. (Selection based on `bitSize` method).
     */
    template<Integral TypeA, Integral TypeB>
    using SmallerType = std::conditional_t<bitSize<TypeA>() < bitSize<TypeB>(), TypeA, TypeB>;

    /**
     * @brief Generate mask to mask lower n bits.
     * 
     * May use static member function.
     * 
     * @param[in] size number of bits to be masked.
     * @return Integer Mask.
     * 
     * <b>Example </b>
     * 
     * \snippet{lineno} isPowerOfTwo.cpp nBitMaskExample
     * 
     * Console Output:
     * \include{lineno} nBitMask.out.txt
     */
    template<class Integer>
    [[nodiscard]] constexpr inline Integer nBitMask(std::size_t size) noexcept
    {
        constexpr auto hasMember = NumericTraits<Integer>::hasBitMaskGenerator;

        if constexpr (hasMember)
            return Integer::nBitMask(size);
        else
            return (static_cast<Integer>(1) << size) - 1;
    }

    /**
     * @brief Extract bits from bit stream (as an integer)
     * 
     * @tparam Integer type of bit stream.
     * @param[in] value bit stream to extract from
     * @param[in] offset offset from 0th position.
     * @param[in] size number of bits to extract.
     * @return Integer extracted bits.
     * 
     * <b>Example </b>
     * 
     * \snippet{lineno} isPowerOfTwo.cpp extractBitsExample
     * 
     * Console Output:
     * \include{lineno} extractBits.out.txt
     */
    template<class Integer>
    [[nodiscard]] constexpr inline Integer extractBits(Integer value, std::size_t offset, std::size_t size) noexcept
    {
        auto mask = nBitMask<Integer>(size);
        mask = mask << offset;

        value &= mask;
        return value >> offset;
    }



    /**
     * @brief Split Integer to multiple smaller integers, partition along bit position (concatenate in binary to restore).
     * 
     * eg: 0xfffa -> 0xff and 0xfa where `destSize_` is 8.
     * 
     * @tparam Source Source Type.
     * @tparam destSize_ destination size.
     * @tparam Destination destination type.
     * 
     * Requires `destSize_ <= bitSize<Destination>()`.
     * 
     * @param[in] value source
     * @return std::array<Destination, divideRoundUp<std::size_t>(bitSize<Source>(), destSize_)> array of destination integers.
     */
    template<UnsignedIntegral Source, std::size_t destSize_, UnsignedIntegral Destination = SizeCapableUint<destSize_>>
        requires (destSize_ <= bitSize<Destination>())
    [[nodiscard]] constexpr inline 
        std::array<Destination, divideRoundUp<std::size_t>(bitSize<Source>(), destSize_)> 
        splitInteger(Source value) noexcept
    {
        std::array<Destination, divideRoundUp<std::size_t>(bitSize<Source>(), destSize_)> ret;

        for(std::size_t i = 0; i < ret; ++i)
        {
            ret[i] = static_cast<decltype(ret)::value_type>(value & nBitMask<Source>(destSize_));
            value = value >> destSize_;
        }

        return ret;
    }
}

#endif // INCLUDE_EASYMATHLIB_EASYMATH_H_INCLUDED

