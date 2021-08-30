function PrintName()
{
    var names=["Talha","Ali","Usman"];

    for(var i=1; i<=100; i++)
    {
        if(i % 2 === 0)
        {
            document.write(names[0]+"<br>");
        }
        else if(i % 3 === 0)
        {
            document.write(names[1]+"<br>");
        }
        else if(i % 4 === 0)
        {
            document.write(names[2]+"<br>");
        }
        else if(i % 5 === 0)
        {
            document.write(names+"<br>");
        }
        else
        {
            document.write(i+"<br>");
        }
    }
}

PrintName();