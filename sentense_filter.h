#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cctype>

using namespace std;

class SentenceFilter {
private:
    char* source;
    bool isTextSource;

    void split_into_sentences(const char* text, char**& sentences, int& sentenceCount) const;
    bool contains_word(const char* sentence, const char* word) const;

public:
    SentenceFilter();
    SentenceFilter(const char* filename);
    SentenceFilter(const char* text, bool isText);
    SentenceFilter(const SentenceFilter& other);
    ~SentenceFilter();
    void result(const char* word) const;
};
