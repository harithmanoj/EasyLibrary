/**
 * @file easyParse.cpp 
 * @author Harith Manoj
 * @brief EasyParse library code.
 * @date 16 October 2024
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


#include <easyParseLib/easyParse.h>


namespace easyParse
{
     /**
     * @brief Split string into substring based on location of the delimiters.
     * 
     * eg : Hello uo, awr; asdf; asda, sad , asd a , a
     *  will be split using {' ', ',', ';', ','} to
     *      "Hello", "uo", " awr", " asdf; asda", " sad ", " asd a ", " a".
     * 
     * @param[in] string string to split.
     * @param[in] delim delimiter to split string.
     * @return std::vector<std::string_view> list of split substrings.
     */
    [[nodiscard]] std::vector<std::string_view> splitUsingDelimiterList(std::string_view string, std::vector<char> delim)
    {
        std::vector<std::string_view> ret;

        ret.reserve(delim.size() + 1);

        for(std::size_t i = 0; (i < delim.size()) && !string.empty(); ++i)
        {
            ret.emplace_back(extractTillDelimiter(string, delim[i]));
        }

        while(!string.empty())
            ret.emplace_back(extractTillDelimiter(string, delim.back()));

        return ret;
    }

    /**
     * @brief Get vector of stringes that were not enclosed by "" or '' in input string.
     * 
     * @param[in] string string to evaluate.
     * @return std::vector<std::string_view> list of non enclosed sub-strings.
     */
    [[nodiscard]] std::vector<std::string_view> extractNonText(std::string_view string)
    {
        auto iterator = string.begin();
        auto sentinel = string.end();
        std::vector<std::string_view> ret;
        ret.reserve(3);

        auto begin = string.begin();

        while (iterator < sentinel)
        {
            auto temp = iterator;
            auto eval = advanceSkipReportQuotedText(iterator, sentinel);
            if(eval.second)
            {
                ret.push_back(
                    string.substr(std::ranges::distance(string.begin(), begin), std::ranges::distance(begin, temp))
                );
                begin = iterator;
            }
        }
        return ret;
    }
}

