#include <iostream>
#include <string>
#include <vector>

/**
 * Function computes frequencies of each character of English alphabet in the passed s.
 * Non-alpha characters are skipped
 * @param s: a string to process
 * @return a vector<double>, where each value at "i" position
 * represents frequency of the character "(char) (i+'a')"
 * */
std::vector<double> charactersFrequency (const std::string & s)
{
    const size_t alphabetLength = 'z' - 'a' + 1;
    size_t counts[alphabetLength] = {0};

    size_t totalCount = 0;
    for (char c: s)
        if (isalpha (c))
        {
            ++counts[tolower (c) - 'a'];
            ++totalCount;
        }

    std::vector<double> frequencies (alphabetLength);
    for (size_t i=0; i < alphabetLength; ++i)
        frequencies[i] = ((double) counts[i]) / totalCount;
    return frequencies;
}

int main ()
{
    // driver function
    auto frequencies = charactersFrequency ("A brown fox jumped over lazy dog.");
    char c = 'a';
    for (double i : frequencies)
        std::cout << c++ << " frequency: " << i << std::endl;
    return 0;
}
