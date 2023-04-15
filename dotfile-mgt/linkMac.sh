#!/usr/bin/env bash
# Creates symlinks to all the dotfiles
echo If fail, \'ln: path: File exists\' will be printed.
echo To fix, delete those files at those paths.
echo
echo Attemping to set symlinks to these dotfiles:
echo - ~/.aliases
ln -s ../aliases.txt ~/.aliases 
echo
echo - ~/.bash_profile
ln -s ../bash_profile.txt ~/.bash_profile 
echo
echo - ~/.config/karabiner.edn
ln -s ../keyboards/karabiner.edn ~/.config/karabiner.edn
echo
echo - ~/.vimrc
ln -s ../vimrc.txt ~/.aliases 
echo
echo - ~/.vifm/vifmrc
ln -s ../vifmrc.txt ~/.vifm/vifmrc
echo
echo "Finished routine!"

