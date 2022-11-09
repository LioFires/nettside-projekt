#include "String-Modifier.hpp"

// em++ -std=c++20  --bind ./Cpp/String-Modifier/String-Modifier.cpp -o ./compiledJS/String_Modifier_CLASS.js

void String_Modifier::change_theme_emoji()
{
    val document_object = val::global("document");

    if (!document_object.as<bool>()) 
    {
        emscripten_run_script("console.log('Object couldn\'t be found in the C++ file!')");
    }

    val document_object_change_theme_button = document_object.call<val>("getElementById", std::string("change-theme-button"));
    const std::string document_object_current_emoji { document_object_change_theme_button["innerText"].as<std::string>() };

    const std::string change_emoji { (document_object_current_emoji == "🌑") ? "🌕" :  "🌑" || (document_object_current_emoji == "🌕") ? "🌑" : "🌕" };
    document_object_change_theme_button.set("innerText", val(change_emoji));
    return;
}

void String_Modifier::_get_image()
{
    emscripten_fetch_attr_t attr;
    emscripten_fetch_attr_init(&attr);
    strcpy(attr.requestMethod, "GET");
    attr.attributes = EMSCRIPTEN_FETCH_LOAD_TO_MEMORY;
    attr.onsuccess = _F_ON_SUCCESS;
    //attr.onerror = _F_ON_ERROR;
    emscripten_fetch(&attr, "https://picsum.photos/200/300");
}

void String_Modifier::_F_ON_SUCCESS(emscripten_fetch_t * fetch)
{
    val _Document = val::global("document");
    val text_output = _Document.call<val>("getElementById", std::string("text"));
    static std::string temp_str {};
    for (size_t i {}; i < fetch->numBytes; ++i)
    {
        temp_str.push_back(fetch->data[i]);
    }
    _temp_holder = temp_str;
    //temp[fetch->numBytes - 1] = '\0';
    // std::ofstream outfile ("test.jpg");
    // outfile << temp << std::endl;
    // boost::filesystem::path abs_path = boost::filesystem::complete("./nettside-projekt/test.jpg");
    // std::string abs_path_str = abs_path.string();
    //text_output.set("innerHTML", temp);
    emscripten_fetch_close(fetch);
}

std::string String_Modifier::get_temp_holder()
{
    return _temp_holder;
}

EMSCRIPTEN_BINDINGS(my_class)
{
    class_<String_Modifier>("String_Modifier")
    .constructor()
    .function("change_theme_emoji", &String_Modifier::change_theme_emoji)
    .function("_get_sizeof", &String_Modifier::_get_sizeof)
    .function("_get__image", &String_Modifier::_get_image)
    .property("_temp_holder", &String_Modifier::get_temp_holder);
}