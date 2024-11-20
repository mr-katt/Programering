#include "editor.h"
#include <map>
#include <vector>

using std::string;

using size_type = Editor::size_type;

size_type Editor::get_size() const
{
    return text.size();
}

size_type Editor::find_left_par(size_type pos) const {
    std::vector<char> stack;
    std::map<char, char> matchingPairs{
        {')','('},
        {']','['},
        {'}','{'}

    };
    if(text[pos]=='.'){
        return string::npos;
    }
    char closing_par = text[pos];
    char opening_par = matchingPairs.find(closing_par)->second;
    for (size_type i = pos; i > 0; i--) {
        if (text[i] == closing_par) {
            stack.push_back(closing_par);
        }
        else if(text[i] == opening_par){
            stack.pop_back();
            if(stack.empty()){
                return i;
            }
        }
    }
    return string::npos;
   /*
    int count = 0;
    auto par = text[pos];
    for(size_type i = pos; i > 0; i--){
        std::cout << text<< "\n" << text[i] << " count is:" << count << "\n";
        if (text[i] == par) {
            count++;
        }
        else if(text[i] == '(' && par == ')'){
            count--;
            if (count == 0) {
                return i;
            }
        }
        else if(text[i] == '[' && par == ']'){
            count--;
            if (count == 0) {
                return i;
            }
        }
        else if(text[i] == '{' && par == '}'){
            count--;
            if (count == 0) {
                return i;
            }   
        }
        
    }*/
}
