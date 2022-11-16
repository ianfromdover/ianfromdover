<#
Compiles all .cpp programs in the dir using freeglut.
Author: Sharadh
#>

Get-ChildItem | 
Sort-Object |
Where-Object { $_.Extension -eq ".cpp" } | 
Foreach-Object {
    $Example = $_.BaseName
        cl.exe "$_" /O2 /Z7 /std:c++17 /I .\include /Fe: "${Example}.exe" /link /LIBPATH:.\lib freeglut.lib
        & ".\${Example}.exe"
}
