let String_Modifier_OBJ = {};

var Module =
{
    onRuntimeInitialized: function()
    {
        String_Modifier_OBJ = new Module.String_Modifier();
    },
}

// add this: AddType application/wasm wasm 
// to the .htaccess file