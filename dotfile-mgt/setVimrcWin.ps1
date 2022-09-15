echo "Attempting to install repo\'s vimrc into system"
$a = (Get-Content -Path ..\vimrc.txt)

echo 'Setting ~\.vimrc'
Set-Content -Path '~\.vimrc' $a

echo 'Setting ~\_vimrc'
Set-Content -Path '~\_vimrc' $a

echo 'Setting ~\.ideavimrc'
Set-Content -Path '~\.ideavimrc' $a

echo 'All 3 vimrcs successfully set 🎉'

