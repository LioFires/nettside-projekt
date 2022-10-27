function includeHTML() 
{
    const current_html_file = document.getElementsByTagName("*");

    for (let i = 0; i < current_html_file.length; ++i) 
    {
      let element = current_html_file[i];
      const file = element.getAttribute("include-html");

      if (file) 
      {
        const xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function()
        {
          if (this.readyState == 4) 
          {
            if (this.status == 200) element.innerHTML = this.responseText;
            if (this.status == 404) element.innerHTML = "Could not find the file or content";
            
            element.removeAttribute("include-html");
            includeHTML();
          }
        }
        xhttp.open("GET", file, true);
        xhttp.send();

        return;
      }
    }
  }

includeHTML();