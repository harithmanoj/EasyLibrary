/**
 * @file easyArgParse.h 
 * @author Harith Manoj
 * @brief Command line argument parser
 * @date 21 June 2024
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


#ifndef INCLUDE_EASYPARSELIB_EASYARGPARSE_H_INCLUDED

/// @brief include\easyParseLib\easyArgParse.h Header Guard 
#define INCLUDE_EASYPARSELIB_EASYARGPARSE_H_INCLUDED


#include <string_view>
#include <string>
#include <vector>
#include <exception>
#include <stdexcept>
#include <array>

#include "easyParse.h"


namespace easyParse
{
    /// @brief Boolean Switch Type class.
    struct BoolSwitch
    {
        /// @brief Long form of switch, to be used along with `--` and `on, y, yes, off, n, no` as arguments.
        std::string longForm;

        /// @brief Short form sets or resets the boolean value.
        std::string shortForm;

        /// @brief Value set.
        bool setValue;

        /// @brief Whether the switch default value has been overriden.
        bool overridden;
    };

    /// @brief Custom value argument switch Type class.
    struct ArgSwitch
    {
        /// @brief Long form of switch, to be used along with `--` and an argument.
        std::string longForm;

        /// @brief Short form sets `shortFormValue` as value.
        std::string shortForm;

        /// @brief Value set when short form switch is present.
        std::vector<std::string> shortFormValue;

        /// @brief Value set.
        std::vector<std::string> setValue;
        
        /// @brief Whether the switch default value has been overriden.
        bool overridden;
    };

    /// @brief Switch type with a finite list of possible values.
    struct OptSwitch
    {
        /// @brief Long form of switch, to be used along with `--` and an argument.
        std::string longForm;

        /// @brief Short switch forms, each form sets value to the option it represents.
        std::vector<std::string> options;

        /// @brief Value set, represent index of `options`, where `options` is valid list of options.
        std::size_t setValue;
        
        /// @brief Whether the switch default value has been overriden.
        bool overridden;
    };

    /// @brief Arguments not part of switches and present at a particular position.
    struct Positional
    {
        /// @brief Argument value.
        std::string_view arg;

        /// @brief Position in argument list.
        std::size_t pos;
    };

    /** @brief Parse argument list based on switches configured.
     * 
     * <b>Example </b>
     * 
     * \snippet{lineno} argParser.cpp ArgParserExample
     * 
     * Console Output:
     * \include{lineno} argParser.out.txt
     * 
     */
    class ArgParser
    {
        /// @brief Bool switches list.
        std::vector<BoolSwitch> boolSwitchList_;

        /// @brief Custom argument switches list.
        std::vector<ArgSwitch> argSwitchList_;

        /// @brief Radio type option based switches list.
        std::vector<OptSwitch> optSwitchList_;

        /// @brief Position based arguments list.
        std::vector<Positional> posArgList_;

        /// @brief Number of arguments.
        int argc_;

        /// @brief Pointer to array of arguments (null terminated string).
        const char** argv_;

    public:
        
        /**
         * @brief Construct a new Arg Parser object.
         * 
         * @param[in] argc number of argument count.
         * @param[in] argv argument (null terminated string) list.
         */
        inline ArgParser(int argc, const char** argv) noexcept : argc_(argc), argv_(argv) {}

        /**
         * @brief Add a boolean switch configuration.
         * 
         * Ex: A boolean configuration with:
         * - long form `"verbose"` sets switch ON or OFF using `--verbose <arg>`. where `arg` is either `on, y, yes, off, n, no`.
         * - short form `"v"` sets switch ON using `-v`.
         * - `setValue` is the default value set if switch is not set.
         * 
         * @param[in] boolSw switch to add.
         * @return ArgParser& reference to same object to use for chaining.
         */
        inline ArgParser& addBoolSwitch(BoolSwitch boolSw) 
        {
            boolSwitchList_.emplace_back(boolSw);
            return *this;
        }

        /**
         * @brief Add a boolean switch configuration.
         * 
         * Ex: A boolean configuration with:
         * - long form `"verbose"` sets switch ON or OFF using `--verbose <arg>`. where `arg` is either `on, y, yes, off, n, no`.
         * - short form `"v"` sets switch ON using `-v`.
         * - `value` is the default value set if switch is not set.
         * 
         * @param[in] longForm long form of switch.
         * @param[in] shortForm short form of switch.
         * @param[in] value default value of switch.
         * @return ArgParser& reference to same object to use for chaining.
         */
        inline ArgParser& addBoolSwitch(
            const std::string& longForm,
            const std::string& shortForm,
            bool value
        )
        {
            boolSwitchList_.emplace_back(
                longForm, shortForm, value, false
            );
            return *this;
        }

        /**
         * @brief Add custom argument based switch configuration.
         * 
         * Ex: A custom argument type configuration with.
         * - long form `"out"` sets arguments using `--out <arg>`. where arg is value to be set.
         * - short form `"o"` sets value using `-o` to a preset value `shortFormValue` (eg: "out.exe").
         * - shortFormValue sets the value to be set when short form switch is present.
         * - `setValue` is the default value set if switch is not set.
         * 
         * @param[in] argSw switch to add.
         * @return ArgParser& reference to same object to use for chaining.
         */
        inline ArgParser& addArgSwitch(ArgSwitch argSw)
        {
            argSwitchList_.emplace_back(argSw);
            return *this;
        }

        /**
         * @brief Add custom argument based switch configuration.
         * 
         * Ex: A custom argument type configuration with.
         * - long form `"out"` sets arguments using `--out <arg>`. where arg is value to be set.
         * - short form `"o"` sets value using `-o` to a preset value `shortFormValue` (eg: "out.exe").
         * - shortFormValue sets the value to be set when short form switch is present.
         * - `setValue` is the default value set if switch is not set.
         * 
         * @param[in] longForm long form of switch, to be followed by arguments.
         * @param[in] shortForm short form of switch, default short form value to be selected.
         * @param[in] shortFormValue value to be set if short form is called.
         * @param[in] setValue default value of switch.
         * @return ArgParser& reference to same object to use for chaining.
         */
        inline ArgParser& addArgSwitch(
            const std::string& longForm,
            const std::string& shortForm,
            const std::vector<std::string>& shortFormValue,
            const std::vector<std::string>& setValue
        )
        {
            argSwitchList_.emplace_back(
                longForm, shortForm, 
                shortFormValue, setValue
            );
            return *this;
        }

        /**
         * @brief Add switch to choose from list.
         * 
         * Ex: A assembler mode selector: hs for hex string, b for binary, bs for binary string.
         * - longForm `"mode"` sets argument using `--mode <arg>` where `arg` is value and is member of `options`.
         * - options: list of possible values that can also be used as short switch, `{hs, bs, b}`, sets value using `-hs`, `-bs`, `-b` etc.
         * - `setValue` is the default value set, (value is index of arg in `options`).
         * 
         * @param[in] optSw switch configuration.
         * @return ArgParser& reference to same object to use for chaining.
         */
        inline ArgParser& addOptSwitch(OptSwitch optSw)
        {
            optSwitchList_.emplace_back(optSw);
            return *this;
        }

        /**
         * @brief Add switch to choose from list.
         * 
         * Ex: A assembler mode selector: hs for hex string, b for binary, bs for binary string.
         * - longForm `"mode"` sets argument using `--mode <arg>` where `arg` is value and is member of `options`.
         * - options: list of possible values that can also be used as short switch, `{hs, bs, b}`, sets value using `-hs`, `-bs`, `-b` etc.
         * - `setValue` is the default value set, (value is index of arg in `options`).
         * 
         * @param[in] longForm long form switch to set option.
         * @param[in] options value specific short switch list.
         * @param[in] setValue default value.
         * @return ArgParser& reference to same object to use for chaining.
         */
        inline ArgParser& addOptSwitch(
            std::string longForm,
            std::vector<std::string> options,
            std::size_t setValue
        )
        {
            optSwitchList_.emplace_back(
                longForm, options, setValue
            );
            return *this;
        }


        /**
         * @brief Reserve memory for switch configurations using known count of switches.
         * 
         * @param[in] boolSize number of boolean switches.
         * @param[in] argSize number of custom argument switches.
         * @param[in] optSize number of option switches.
         * @return ArgParser& reference to same object to use for chaining.
         */
        inline ArgParser& reserve(std::size_t boolSize, std::size_t argSize, std::size_t optSize) 
        {
            boolSwitchList_.reserve(boolSize);
            argSwitchList_.reserve(argSize);
            optSwitchList_.reserve(optSize);
            return *this;
        }

        /// @brief returns `std::vector<easyParse::BoolSwitch>::const_iterator` to begining of bool switch configuration vector.
        inline auto boolIterator() const noexcept { return boolSwitchList_.begin(); }

        /// @brief returns `std::vector<easyParse::BoolSwitch>::const_iterator` to begining of custom arg switch configuration vector. 
        inline auto argIterator() const noexcept { return argSwitchList_.begin(); }

        /// @brief returns `std::vector<easyParse::BoolSwitch>::const_iterator` to begining of option switch configuration vector. 
        inline auto optIterator() const noexcept { return optSwitchList_.begin(); }

        /// @brief returns `std::vector<easyParse::BoolSwitch>::const_iterator` to begining of positional switch configuration vector. 
        inline auto posIterator() const noexcept { return posArgList_.begin(); }

        /// @brief returns `std::vector<easyParse::BoolSwitch>::const_iterator` to one past end of bool switch configuration vector.
        inline auto boolSentinal() const noexcept { return boolSwitchList_.end(); }

        /// @brief returns `std::vector<easyParse::BoolSwitch>::const_iterator` to one past end of custom arg switch configuration vector. 
        inline auto argSentinal() const noexcept { return argSwitchList_.end(); }

        /// @brief returns `std::vector<easyParse::BoolSwitch>::const_iterator` to one past end of option switch configuration vector. 
        inline auto optSentinal() const noexcept { return optSwitchList_.end(); }

        /// @brief returns `std::vector<easyParse::BoolSwitch>::const_iterator` to one past end of positional switch configuration vector. 
        inline auto posSentinal() const noexcept { return posArgList_.end(); }

        /**
         * @brief Find iterator to boolean switch with long form `longform`.
         * 
         * @param[in] longForm long form of switch to find.
         * @return `std::vector<easyParse::BoolSwitch>::const_iterator` iterator 
         * to configuration, `end()` if long form not found.
         */
        inline auto findLongBool(std::string_view longForm) const
        {
            for(auto it = boolSwitchList_.begin(); it < boolSwitchList_.end(); ++it)
                if(it->longForm == longForm)
                    return it;

            return boolSwitchList_.end();
        }

        /**
         * @brief Find iterator to boolean switch with short form `longform`.
         * 
         * @param[in] shortForm short form of switch to find.
         * @return `std::vector<easyParse::BoolSwitch>::const_iterator` iterator 
         * to configuration, `end()` if short form not found.
         */
        inline auto findShortBool(std::string_view shortForm)
        {
            for(auto it = boolSwitchList_.begin(); it < boolSwitchList_.end(); ++it)
                if(it->shortForm == shortForm)
                    return it;

            return boolSwitchList_.end();
        }

        /**
         * @brief Find iterator to custom arg switch with long form `longform`.
         * 
         * @param[in] longForm long form of switch to find.
         * @return `std::vector<easyParse::ArgSwitch>::const_iterator` iterator 
         * to configuration, `end()` if long form not found.
         */
        inline auto findLongArg(std::string_view longForm) const
        {
            for(auto it = argSwitchList_.begin(); it < argSwitchList_.end(); ++it)
                if(it->longForm == longForm)
                    return it;

            return argSwitchList_.end();
        }

        /**
         * @brief Find iterator to custom arg switch with short form `longform`.
         * 
         * @param[in] shortForm short form of switch to find.
         * @return `std::vector<easyParse::ArgSwitch>::const_iterator` iterator 
         * to configuration, `end()` if short form not found.
         */
        inline auto findShortArg(std::string_view shortForm)
        {
            for(auto it = argSwitchList_.begin(); it < argSwitchList_.end(); ++it)
                if(it->shortForm == shortForm)
                    return it;

            return argSwitchList_.end();
        }

        /**
         * @brief Find iterator to option switch with long form `longform`.
         * 
         * @param[in] longForm long form of switch to find.
         * @return `std::vector<easyParse::OptSwitch>::const_iterator` iterator 
         * to configuration, `end()` if long form not found.
         */
        inline auto findLongOpt(std::string_view longForm) const
        {
            for(auto it = optSwitchList_.begin(); it < optSwitchList_.end(); ++it)
                if(it->longForm == longForm)
                    return it;

            return optSwitchList_.end();
        }

        /**
         * @brief Find iterator to option switch with short form `longform`.
         * 
         * @param[in] shortForm short form of switch to find.
         * @return `std::vector<easyParse::OptSwitch>::const_iterator` iterator 
         * to configuration, `end()` if short form not found.
         */
        inline auto findShortOpt(std::string_view shortForm)
        {
            for(auto it = optSwitchList_.begin(); it < optSwitchList_.end(); ++it)
                for(auto& opt : it->options)
                    if(opt == shortForm)
                        return it;

            return optSwitchList_.end();
        }

        /**
         * @brief Find number of positional arguments.
         */
        inline std::size_t positionalArgCount() const noexcept { return posArgList_.size(); }

        /// @brief const reference to positional argument with index `index` in the list of positional arguments. 
        inline const auto& positionalArgAt(std::size_t index) const { return posArgList_.at(index); }

        /// @brief get arg[0], invoking command.
        inline std::string_view arg0() const noexcept { return argv_[0]; }

        /**
         * @brief Parse command line arguments set. and populate all switch state and positional argument list.
         * 
         * @throw (1) `std::invalid_argument`: If only '-' is an argument.
         * @throw (2) `std::invalid_argument`: If switch after `-` is not configured (added).
         * @throw (3) `std::invalid_argument`: If after long boolean switch an argument is not present.
         * @throw (4) `std::invalid_argument`: If after long boolean switch invalid value provided.
         * @throw (5) `std::invalid_argument`: If after long option switch an argument is not present.
         * @throw (6) `std::invalid_argument`: If after long option switch, invalid value provided.
         * 
         */
        void parse();

    };
}


#endif // INCLUDE_EASYPARSELIB_EASYARGPARSE_H_INCLUDED

