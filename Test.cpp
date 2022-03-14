/**
 * Unit tests.
 *
 * AUTHORS: Eyad Amer
 * Date:  2021-03
 */

#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input)
{
    std::erase(input, ' ');
    std::erase(input, '\t');
    std::erase(input, '\n');
    std::erase(input, '\r');
    return input;
}

// Good inputs and results
TEST_CASE("Good input")
{

    CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n"
                                                    "@-------@\n"
                                                    "@-@@@@@-@\n"
                                                    "@-@---@-@\n"
                                                    "@-@@@@@-@\n"
                                                    "@-------@\n"
                                                    "@@@@@@@@@"));

    CHECK(nospaces(mat(7, 9, '@', '-')) == nospaces("@@@@@@@\n"
                                                    "@-----@\n"
                                                    "@-@@@-@\n"
                                                    "@-@-@-@\n"
                                                    "@-@-@-@\n"
                                                    "@-@-@-@\n"
                                                    "@-@@@-@\n"
                                                    "@-----@\n"
                                                    "@@@@@@@"));

    CHECK(nospaces(mat(13, 5, '@', '-')) == nospaces("@@@@@@@@@@@@@\n"
                                                     "@-----------@\n"
                                                     "@-@@@@@@@@@-@\n"
                                                     "@-----------@\n"
                                                     "@@@@@@@@@@@@@"));

    CHECK(nospaces(mat(7, 5, '$', '*')) == nospaces("$$$$$$$\n"
                                                    "$*****$\n"
                                                    "$*$$$*$\n"
                                                    "$*****$\n"
                                                    "$$$$$$$"));

    CHECK(nospaces(mat(5, 1, '#', '*')) == nospaces("#####"));

    CHECK(nospaces(mat(1, 5, '#', '*')) == nospaces("#\n"
                                                    "#\n"
                                                    "#\n"
                                                    "#\n"
                                                    "#"));

    CHECK(nospaces(mat(1, 1, '$', '*')) == nospaces("$"));

    CHECK(nospaces(mat(3, 5, '$', '+')) == nospaces("$$$\n"
                                                    "$+$\n"
                                                    "$+$\n"
                                                    "$+$\n"
                                                    "$$$"));

    CHECK(nospaces(mat(7, 7, '$', '*')) == nospaces("$$$$$$$\n"
                                                    "$*****$\n"
                                                    "$*$$$*$\n"
                                                    "$*$*$*$\n"
                                                    "$*$$$*$\n"
                                                    "$*****$\n"
                                                    "$$$$$$$"));

    CHECK(nospaces(mat(9, 11, '#', '&')) == nospaces("#########\n"
                                                     "#&&&&&&&#\n"
                                                     "#&#####&#\n"
                                                     "#&#&&&#&#\n"
                                                     "#&#&#&#&#\n"
                                                     "#&#&#&#&#\n"
                                                     "#&#&#&#&#\n"
                                                     "#&#&&&#&#\n"
                                                     "#&#####&#\n"
                                                     "#&&&&&&&#\n"
                                                     "#########"));
}

// Bad inputs - Even number
TEST_CASE("Bad input - Even number in the input")
{
    CHECK_THROWS(mat(10, 5, '$', '%'));
    CHECK_THROWS(mat(5, 10, '$', '%'));
    CHECK_THROWS(mat(2, 7, '#', '*'));
    CHECK_THROWS(mat(100, 7, '$', '!'));
    CHECK_THROWS(mat(4, 4, '&', '@'));
    CHECK_THROWS(mat(1, 2, '!', '#'));
}

// Bad inputs - non Positive number
TEST_CASE("Bad input - Negetave or zero number in the input")
{
    CHECK_THROWS(mat(-10, 5, '$', '%'));
    CHECK_THROWS(mat(-10, -5, '$', '%'));
    CHECK_THROWS(mat(0, 5, '%', '&'));
    CHECK_THROWS(mat(5, 0, '%', '&'));
    CHECK_THROWS(mat(0, -3, '@', '&'));
    CHECK_THROWS(mat(10, -5, '#', '%'));
    CHECK_THROWS(mat(-1, 5, '#', '*'));
}

// Bad inputs - illegal characters
TEST_CASE("Bad input - illegal characters input")
{
    CHECK_THROWS(mat(9, 5, '\n', '%')); // \n
    CHECK_THROWS(mat(7, 11, '$', ' ')); // space
}

// Wrong results
TEST_CASE("The matrix is wrong for the input")
{
    CHECK_THROWS(nospaces(mat(9, 7, '@', '-')) = nospaces("@@@@@@@@@\n"
                                                          "@-------@\n"
                                                          "@-------@\n"
                                                          "@-@---@-@\n"
                                                          "@-------@\n"
                                                          "@-------@\n"
                                                          "@@@@@@@@@"));

    CHECK_THROWS(nospaces(mat(9, 7, '#', '+')) = nospaces("@@@@@@@@@\n"
                                                          "@-------@\n"
                                                          "@-------@\n"
                                                          "@-@---@-@\n"
                                                          "@-------@\n"
                                                          "@-------@\n"
                                                          "@@@@@@@@@"));

    CHECK_THROWS(nospaces(mat(11, 7, '@', '-')) = nospaces("@@@@@@@@@\n"
                                                           "@-------@\n"
                                                           "@-@@@@@-@\n"
                                                           "@-@---@-@\n"
                                                           "@-@@@@@-@\n"
                                                           "@-------@\n"
                                                           "@@@@@@@@@"));

    CHECK_THROWS(nospaces(mat(1, 5, '@', '-')) = nospaces("@@@@@\n"));
}

// Bad inputs - illegal inputs
TEST_CASE("Bad input - illegal inputs!")
{
    CHECK_THROWS(mat('$', '%', 7, 11));
    CHECK_THROWS(mat('$', '%', '$', '%'));
    CHECK_THROWS(mat('$', 5, 7, '#'));
    CHECK_THROWS(mat('$', 8, '@', 11));
    CHECK_THROWS(mat('$', 8, 7, 11));
    CHECK_THROWS(mat(2, 8, 7, '#'));
    CHECK_THROWS(mat(1, 5, 7, 11));
}