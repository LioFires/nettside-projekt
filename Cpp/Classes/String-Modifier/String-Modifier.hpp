#ifndef WEBSITE_STR_MOD_HPP
#define WEBSITE_STR_MOD_HPP

#include <emscripten/bind.h>
#include <emscripten/val.h>
#include <emscripten/emscripten.h>
#include <emscripten/fetch.h>
#include <emscripten.h>
#include <nlohmann/json.hpp>
#include <map>
#include <string_view>
#include <string>

using json = nlohmann::json;
using namespace emscripten;

class String_Modifier
{
        std::map<std::string, std::string> API_urls 
        {
            {"cat-image-url", "https://api.thecatapi.com/v1/images/search"},
            {"cat-fact-url", "https://catfact.ninja/fact"},
            {"dog-image-url", "https://dog.ceo/api/breeds/image/random"},
            {"dog-fact-url", "https://dog-api.kinduff.com/api/facts"}
        };
        static void ON_SUCCESS(emscripten_fetch_t * fetch);
        static void ON_ERROR(emscripten_fetch_t * fetch);


    public:
        String_Modifier() = default;
        ~String_Modifier() = default;

        void change_theme_emoji();
        void _get_image();
};

#endif // WEBSITE_STR_MOD_HPP