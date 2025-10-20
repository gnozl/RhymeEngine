//
// Created by Gerardo Gonzalez on 10/19/25.
//

#ifndef RHYMEENGINE_TEXT_H
#define RHYMEENGINE_TEXT_H
#include <string>
#include <vector>
#include "Line.h"

class Text {
    private:
    std::string title;
    int numberOfLines;
    int TotalWords;
    std::string rhymePattern;

    std::vector<Line*> lines;

    public:

    explicit Text(std::string title, std::string fileName);
    ~Text();

    int getNumberOfLines() const {return numberOfLines;};
    int getTotalWords() const {return TotalWords;};
    std::string getRhymePattern() const {return rhymePattern;};

    void setNumberOfLines(int numberOfLines);
    void setTotalWords(int TotalWords);
    void setRhymePattern(std::string rhymePattern);

    void addLine(Line *line);
};

#endif //RHYMEENGINE_TEXT_H