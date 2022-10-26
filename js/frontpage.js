const input_felt = document.getElementById("text-input");
const change_theme_button = document.getElementById("change-theme-button");

// change the emoji of the theme button to the correct one.
const change_theme_emoji = () => change_theme_button.innerText = (change_theme_button.innerText === "🌑") ? "🌕" :  "🌑" || (change_theme_button.innerText === "🌕") ? "🌑" : "🌕";
/*
    The when_input_changes function is gonnna be moved to the C++ file.
    and be redone completly.
*/
// function when_input_changes()
// {
//     let str;
//     for (const i of check_box_list.children)
//     {
//         if (i.firstChild.checked)
//         {
//             switch (i.firstChild.id)
//             {
//                 case "reverse-text-checked":
//                     str = Module.reverse_string(input_felt.value);
//                     input_felt.value = str;
//                 break;
    
//                 case "uppercase-text-checked":
//                 case "lowercase-text-checked":
//                     str = Module.lower_or_uppercase_string(input_felt.value);
//                     input_felt.value = str;
//                 break;
    
//                 case "color-text-checked":

//                 break;
    
//                 case "download-text-checked":
    
//                 break;
    
//                 case "copy-text-checked":
    
//                 break;
            
//             }
//         }
//     }
// }