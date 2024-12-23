#include "sentense_filter.h"

SentenceFilter::SentenceFilter() : source(nullptr), isTextSource(false) {
    cout << "Default constructor called for class SentenceFilter\n";
}

SentenceFilter::SentenceFilter(const char* filename) : isTextSource(false) {
    source = new char[strlen(filename) + 1];
    strcpy(source, filename);
    cout << "Constructor with parameters called for class SentenceFilter\n";
}

SentenceFilter::SentenceFilter(const char* text, bool isText) : isTextSource(isText) {
    source = new char[strlen(text) + 1];
    strcpy(source, text);
    cout << "Constructor with parameters called for class SentenceFilter\n";
}

SentenceFilter::SentenceFilter(const SentenceFilter& other) 
    : isTextSource(other.isTextSource) {
    source = new char[strlen(other.source) + 1];
    strcpy(source, other.source);
    cout << "Copy constructor called for class SentenceFilter\n";
}

SentenceFilter::~SentenceFilter() {
    delete[] source;
    cout << "Destructor called for class SentenceFilter\n";
}

void SentenceFilter::result(const char* word) const {
    char* text;

    if (isTextSource) {
        text = new char[strlen(source) + 1];
        strcpy(text, source);
    } else {
        ifstream file(source);
        if (!file.is_open()) {
            cerr << "Failed to open file: " << source << endl;
            return;
        }
        ostringstream buffer;
        buffer << file.rdbuf();
        string temp = buffer.str();
        text = new char[temp.size() + 1];
        strcpy(text, temp.c_str());
        file.close();
    }

    char** sentences = nullptr;
    int sentenceCount = 0;
    split_into_sentences(text, sentences, sentenceCount);

    cout << "Sentences containing the word \"" << word << "\":\n";
    for (int i = 0; i < sentenceCount; ++i) {
        if (contains_word(sentences[i], word)) {
            cout << sentences[i] << endl;
        }
        delete[] sentences[i];
    }

    delete[] sentences;
    delete[] text;
}

void SentenceFilter::split_into_sentences(const char* text, char**& sentences, int& sentenceCount) const {
    const int maxSentences = 100;
    sentences = new char*[maxSentences];
    sentenceCount = 0;

    const char* delimiters = ".!?";
    char* copy = new char[strlen(text) + 1];
    strcpy(copy, text);

    char* token = strtok(copy, delimiters);
    while (token && sentenceCount < maxSentences) {
        sentences[sentenceCount] = new char[strlen(token) + 1];
        strcpy(sentences[sentenceCount], token);
        ++sentenceCount;
        token = strtok(nullptr, delimiters);
    }

    delete[] copy;
}

bool SentenceFilter::contains_word(const char* sentence, const char* word) const {
    int len = strlen(word);
    const char* pos = strstr(sentence, word);
    while (pos) {
        if ((pos == sentence || !isalpha(*(pos - 1))) &&
            (!isalpha(*(pos + len)) || *(pos + len) == '\0')) {
            return true;
        }
        pos = strstr(pos + 1, word);
    }
    return false;
}
