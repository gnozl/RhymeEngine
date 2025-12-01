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
    std::string rhymePattern;

    std::vector<Line> lines;

    public:

    Text();
    //TODO: Implement constructor
    //explicit Text(std::vector<Line> lines);
    ~Text();

    [[nodiscard]] int getNumberOfLines() const {return (lines.size());}


    [[nodiscard]] int getTotalWords() const;
    [[nodiscard]] std::string getRhymePattern() {return rhymePattern;};
    [[nodiscard]] std::vector<Line> getLines() {return lines;};

    void setRhymePattern(const std::string& rhymePattern);
    void addLine(Line & line);

    void print();
    void printIPA();
};

#endif //RHYMEENGINE_TEXT_H