#include <fstream>
#include <RhymeEngine.h>

int main() {
    std::cout << "==RHYME COLOR TEST==" << std::endl;
    RhymeEngine engine;
    engine.createDictionary();
    Text text = engine.createText("../tests/test/rhymetest.txt");
    engine.setRhymes(text);
    text.print();

    return 0;
}
