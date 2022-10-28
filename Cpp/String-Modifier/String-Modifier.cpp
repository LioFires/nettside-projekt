/*

    Idea: make a function that go through all the elements in the website and check their color
    and then switch them for dark theme or white theme.
*/

#include "String-Modifier.hpp"

// em++ -std=c++20  --bind ./Cpp/String-Modifier/String-Modifier.cpp -o ./compiledJS/String_Modifier_CLASS.js

void String_Modifier::change_theme_emoji()
{
    val document_object = val::global("document");

    if (!document_object.as<bool>()) 
    {
        emscripten_run_script("console.log('Document Object couldn\'t be found in the C++ file!')");
    }

    val document_object_change_theme_button = document_object.call<val>("getElementById", std::string("change-theme-button"));
    const std::string document_object_current_emoji { document_object_change_theme_button["innerText"].as<std::string>() };

    const std::string change_emoji { (document_object_current_emoji == "🌑") ? "🌕" :  "🌑" || (document_object_current_emoji == "🌕") ? "🌑" : "🌕" };
    document_object_change_theme_button.set("innerText", val(change_emoji));
    return;
}

EMSCRIPTEN_BINDINGS(my_class)
{
    class_<String_Modifier>("String_Modifier")
    .constructor<>()
    .function("change_theme_emoji", &String_Modifier::change_theme_emoji)
    .function("_get_sizeof", &String_Modifier::_get_sizeof);
}