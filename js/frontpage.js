const input_felt = document.getElementById("text-input");
const change_theme_button = document.getElementById("change-theme-button");

// change the emoji of the theme button to the correct one.
const change_theme_emoji = () => change_theme_button.innerText = (change_theme_button.innerText === "🌑") ? "🌕" :  "🌑" || (change_theme_button.innerText === "🌕") ? "🌑" : "🌕";
/*
    The when_input_changes function is gonnna be moved to the C++ file.
    and be redone completly.
*/