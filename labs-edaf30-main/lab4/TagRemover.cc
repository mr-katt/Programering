#include "TagRemover.h"
#include <regex>
#include <sstream>

TagRemover::TagRemover(std::istream& input){
    std::ostringstream oss;
    oss << input.rdbuf();
    content = oss.str();
}

void TagRemover::removeTags(){
    std::regex tagRegex("<[^>]*>");
    content = std::regex_replace(content, tagRegex, "");

}

void TagRemover::replaceSpecialChars() {
    std::regex lt("&lt;"), gt("&gt;"), nbsp("&nbsp;"), amp("&amp;");
    content = std::regex_replace(content, lt, "<");
    content = std::regex_replace(content, gt, ">");
    content = std::regex_replace(content, nbsp, " ");
    content = std::regex_replace(content, amp, "&");
}

void TagRemover::process() {
    removeTags();
    replaceSpecialChars();
}

void TagRemover::print(std::ostream& output) const {
    output << content;
}