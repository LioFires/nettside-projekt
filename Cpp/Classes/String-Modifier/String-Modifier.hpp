#ifndef WEBSITE_STR_MOD_HPP
#define WEBSITE_STR_MOD_HPP

#include <string>
#include <emscripten/bind.h>
#include <emscripten/val.h>
#include <emscripten/emscripten.h>
#include <emscripten/fetch.h>
#include <fstream>
//#include <boost/filesystem.hpp>

using namespace emscripten;

class String_Modifier
{
    public:
        String_Modifier() = default;
        ~String_Modifier() = default;

        void when_input_changes();
        void change_theme_emoji();
        size_t _get_sizeof() const { return _class_size; }
        void _get_image();
        std::string get_temp_holder();
        static std::string _temp_holder;
    private:
        const size_t _class_size { sizeof(String_Modifier) };
        static void _F_ON_SUCCESS(struct emscripten_fetch_t * fetch);
        void _F_ON_ERROR();
        
};

#endif // WEBSITE_STR_MOD_HPP