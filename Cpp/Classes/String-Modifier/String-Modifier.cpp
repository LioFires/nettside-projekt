#include "String-Modifier.hpp"

// em++ -std=c++20  -lembind -sFETCH  -I/usr/local/include -L/usr/local/lib  ./Cpp/Classes/String-Modifier/String-Modifier.cpp -o ./compiledJS/String_Modifier_CLASS.js

// not my function
bool replace(std::string& str, const std::string& from, const std::string& to) {
    // find the strings index
    size_t start_pos = str.find(from);
    // when the string is not equal to the one we want. We will return false
    if(start_pos == std::string::npos)
        return false;
    str.replace(start_pos, from.length(), to);
    return true;
}

void String_Modifier::change_theme_emoji()
{
    val _Document = val::global("document");
    // if the document object don't exist
    if (!_Document.as<bool>()) emscripten_run_script("console.log('document Object couldn\'t be found in the C++ file!')");

    // same as js's document.getElementById()
    val document_object_change_theme_button = _Document.call<val>("getElementById", std::string("change-theme-button"));
    // just .innerText and getting it as a std::string type
    const std::string document_object_current_emoji { document_object_change_theme_button["innerText"].as<std::string>() };

    // changeing emojis
    std::string change_emoji { (document_object_current_emoji == "🌑") ? "🌕" :  "🌑" || (document_object_current_emoji == "🌕") ? "🌑" : "🌕" };
    // same as .innerText = "text";
    document_object_change_theme_button.set("innerText", change_emoji);
    return;
}

void String_Modifier::ON_SUCCESS(emscripten_fetch_t * fetch)
{
    std::string temp_str {};
    val _Document = val::global("document");
    if (!_Document.as<bool>()) emscripten_run_script("console.log('document Object couldn\'t be found in the C++ file!')");
    val image = _Document.call<val>("getElementById", std::string("url-holder"));
    val fact_holder = _Document.call<val>("getElementById", std::string("cat-fact-holder"));

    // could use something else but it don't matter.
    for (size_t i {}; i < fetch->numBytes; ++i)
    {
        temp_str.push_back(fetch->data[i]);
    }

    // same as js's json.parse()
    json data { json::parse(temp_str) };

    // .contains chekc if the json object contains the string
    if (data.contains(std::string("fact")) || data.contains(std::string("facts")))
    {
        std::string fact { data.contains(std::string("fact")) ? data["fact"].dump() : data["facts"][0].dump() };
        fact_holder.set("innerText", fact);
    }
    else
    {
        std::string url { data.contains(std::string("message")) ? data["message"].dump() : data[0]["url"].dump() };

        // replaces the "" so we don't end up with ""text"" since we want "text"
        replace(url, "\"", "");
        replace(url, "\"", "");
        image.set("src", url);
        image.set("height", "400");
        image.set("width", "500");
    }
    // end the request
    emscripten_fetch_close(fetch);
}

void String_Modifier::ON_ERROR(emscripten_fetch_t *fetch)
{
    printf("Downloading %s failed, HTTP failure status code: %d.\n", fetch->url, fetch->status);
    emscripten_fetch_close(fetch);
}

void String_Modifier::_get_image()
{
    val _Document = val::global("document");
    if (!_Document.as<bool>()) emscripten_run_script("console.log('document Object couldn\'t be found in the C++ file!')");

    val cat_checkbox = _Document.call<val>("getElementById", std::string("cat-checkbox"));
    val dog_checkbox = _Document.call<val>("getElementById", std::string("dog-checkbox"));

    // make a get request
    emscripten_fetch_attr_t attr;
    emscripten_fetch_attr_init(&attr);
    strcpy(attr.requestMethod, "GET");
    attr.attributes = EMSCRIPTEN_FETCH_LOAD_TO_MEMORY;
    attr.onsuccess = ON_SUCCESS;
    attr.onerror = ON_ERROR;

    if (cat_checkbox["checked"].as<bool>())
    {
        // we request our url from the map in the class
        emscripten_fetch(&attr, API_urls["cat-image-url"].c_str());
        emscripten_fetch(&attr, API_urls["cat-fact-url"].c_str());
    }
    else if (dog_checkbox["checked"].as<bool>())
    {
        emscripten_fetch(&attr, API_urls["dog-image-url"].c_str());
        emscripten_fetch(&attr, API_urls["dog-fact-url"].c_str());
    }
    else
    {
        emscripten_run_script("console.log('No checkboxes was checked.')");
        return;
    }
}

EMSCRIPTEN_BINDINGS(my_class)
{
    class_<String_Modifier>("String_Modifier")
    .constructor()
    .function("change_theme_emoji", &String_Modifier::change_theme_emoji)
    .function("_get_image", &String_Modifier::_get_image);
}