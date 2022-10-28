#ifndef WEBSITE_STR_MOD_HPP
#define WEBSITE_STR_MOD_HPP

#include <string>
#include <emscripten/bind.h>
#include <emscripten/val.h>
#include <emscripten/emscripten.h>
#include <algorithm>

using namespace emscripten;

class String_Modifier
{
    public:
        String_Modifier() = default;
        ~String_Modifier() = default;

        void when_input_changes();
        void change_theme_emoji();
        size_t _get_sizeof() const { return _class_size; }
    
    private:
        const size_t _class_size { sizeof(String_Modifier) };
};

#endif // WEBSITE_STR_MOD_HPP