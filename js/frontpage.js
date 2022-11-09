const input_felt = document.getElementById("text-input");
const change_theme_button = document.getElementById("change-theme-button");
const text = document.getElementById("text");

/*
    The when_input_changes function is gonnna be moved to the C++ file.
    and be redone completly.
*/

let String_Modifier_OBJ = {};

var Module =
{
    onRuntimeInitialized: function()
    {
        String_Modifier_OBJ = new Module.String_Modifier();
    },
}


function get_image()
{
   console.log(String_Modifier_OBJ._temp_holder);
//   console.log(text.innerHTML);
}


// add this: AddType application/wasm wasm 
// to the .htaccess file when you finally need to host the website on 000webhost.com