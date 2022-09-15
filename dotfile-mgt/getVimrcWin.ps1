echo "Attempting to update repo's vimrc from system\'s copy"
$a = (Get-Content -Path ~\.vimrc)

Set-Content -Path '..\vimrc.txt' $a

echo 'vimrc successfully updated'

