#ifndef WEBSITE_STR_MOD_HPP
#define WEBSITE_STR_MOD_HPP

#include <string>
#include <emscripten/bind.h>
#include <emscripten/val.h>
#include <emscripten/emscripten.h>
#include <algorithm>

#ifdef __cplusplus
    extern "C" {
#endif

using namespace emscripten;

// emcc -lembind ./Cpp/main.cpp -o ./compiledJS/main.js

class String_Modifier
{
    public:
        String_Modifier() = default;
        ~String_Modifier();

        void when_input_changes();
};

#ifdef __cplusplus
}

#endif // WEBSITE_STR_MOD_HPP