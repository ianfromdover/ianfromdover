echo "Attempting to install repo\'s vimrc into system"
$a = (Get-Content -Path ..\vimrc.txt)

# i dont think i need .vimrc
# echo 'Setting ~\.vimrc'
# Set-Content -Path '~\.vimrc' $a

echo 'Setting ~\_vimrc'
Set-Content -Path '~\_vimrc' $a

# i dont think i need ideavimrc
# echo 'Setting ~\.ideavimrc'
# Set-Content -Path '~\.ideavimrc' $a

echo 'VIMRC successfully set :)'

echo "IMPORTANT: to load plugins, find plug#begin, ('~/.vim/plugged') -> ('~/vimfiles/plugged')"
echo "if you are doing it the proper way, that is."

