#ifndef TAG_REMOVER_H
#define TAG_REMOVER_H

#include <iostream>
#include <string>

class TagRemover {
    private:
        std::string content;

        void removeTags();
        void replaceSpecialChars();
    public:
        TagRemover(std::istream& input);
        void process();
        void print(std::ostream& output) const;


};
#endif