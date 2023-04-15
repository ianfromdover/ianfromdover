# https://stackoverflow.com/questions/894430/creating-hard-and-soft-links-using-powershell
# Symlink file
echo 'Sets the PS profile and vimrc'
echo 'Setting powershell profile on system with location:'
echo $profile

$from = Get-Content -Path '..\Microsoft.Powershell_profile.ps1'
New-Item -ItemType SymbolicLink -Path $from -Target $profile
echo 'Powershell profile has been set!'
echo

echo "Attempting to install repo\'s vimrc into system"
$a = (Get-Content -Path ..\vimrc.txt)
New-Item -ItemType SymbolicLink -Path $a -Target '~\_vimrc'
echo 'VIMRC successfully set :)'

echo "IMPORTANT: to load plugins, find plug#begin, ('~/.vim/plugged') -> ('~/vimfiles/plugged')"
echo "if you are doing it the proper way, that is."

