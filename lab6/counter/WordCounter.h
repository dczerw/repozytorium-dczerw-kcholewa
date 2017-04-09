//
// Created by dawid on 06.04.17.
//

#ifndef JIMP_EXERCISES_WORDCOUNTER_H
#define JIMP_EXERCISES_WORDCOUNTER_H

#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include <list>

class Word
{
private:
    std::string word_;

public:
    Word();
    Word(std::string word);
    ~Word();
    std::string GetWord() const;
    void SetWord(std::string word);
    bool operator <(const Word& rhs) const;
};

class Counts
{
private:
    int number_;

public:
    Counts();
    Counts(int number);
    ~Counts();
    int GetCounts() ;
    void SetCounts(int number);
    Counts &operator++(int);
    bool operator <(const Counts& rhs) const;
    bool operator >(const Counts& rhs) const;
    bool operator ==(const Counts& rhs) const;

};

class WordCounter
{
private:
    std::map<Word, Counts> counter_;

public:
    WordCounter();
    WordCounter(std::string localization);
    ~WordCounter();
    void AddWord(Counts number, Word word);
    std::map<Word, Counts> GetMap();
    int operator[](std::string word);
};

std::ostream& operator<<(std::ostream & output, WordCounter& counter);
bool compare_nocase (std::pair<Word, Counts> one, std::pair<Word, Counts> two);


#endif //JIMP_EXERCISES_WORDCOUNTER_H
