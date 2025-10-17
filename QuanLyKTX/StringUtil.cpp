#include "StringUtil.h"
#include <sstream>


string StringUtil::normalizeName(string name) 
{
    stringstream ss(name);
    string word;
    string result = "";

    while (ss >> word)
    {
        for (int i = 0; i < word.length(); i++)
        {
            if (word[i] >= 'A' && word[i] <= 'Z') word[i] += 32;
        }
        word[0] -= 32;
        result += word + " ";
    }

    if (!result.empty()) {
        result.pop_back();
    }

    return result;
}