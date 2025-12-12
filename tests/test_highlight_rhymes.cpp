#include <fstream>
#include <RhymeEngine.h>

int main() {
    std::cout << "==RHYME COLOR TEST==" << std::endl;
    RhymeEngine engine;
    engine.createDictionary();
    Text text = engine.createText("../tests/test/rhymetest.txt");
    engine.setRhymes(text);
    Text text2 = engine.createText("../tests/test/rhymetest2.txt");
    engine.setRhymes(text2);
    Text text3 = engine.createText("../tests/test/rhymetest3.txt");
    engine.setRhymes(text3);
    std::cout << "END OF LINE RHYMES TEST==" << std::endl;
    text.print();
    std::cout << "CORRECT RHYMES TEST==" << std::endl;
    text2.print();
    std::cout << "LOOP COLORS TEST==" << std::endl;
    text3.print();

    return 0;
}
