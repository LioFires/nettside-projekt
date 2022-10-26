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

std::string reverse_string(const std::string & str)
{	
    return std::string(str.rbegin(), str.rend());
}



std::string lower_or_uppercase_string(std::string str)
{
    val document_object = val::global("document");

    if (!document_object.as<bool>()) 
    {
        emscripten_run_script("console.log('Document Object couldn\'t be found in the C++ file!')");
    }

    val document_object_uppercase_checkmark = document_object.call<val>("getElementById", std::string("uppercase-text-checked"));
    
    std::transform(str.begin(), str.end(), str.begin(), (document_object_uppercase_checkmark["checked"].as<bool>()) ? ::toupper : ::tolower);

    return str;
}

EMSCRIPTEN_BINDINGS(my_module) 
{
    function("reverse_string", &reverse_string);
    function("lower_or_uppercase_string", &lower_or_uppercase_string);
}

#ifdef __cplusplus
}
#endif