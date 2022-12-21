<#
    Author: Ian Hong
    Last Edit: 21 Dec 2022
    Reason: add gs to ga command
    Context: rushing for hiverlab cannon project
If you only want this user to execute this, save under
- echo $profile
If you want it to be global, save under
- echo $PsHome

Guide for creating aliases that accept arguments:
- make a function and simply place the $args at the end of the shortcut
#>

# NAVIGATION
New-Alias .. Back
New-Alias ... BackTwo
New-Alias .... BackThree
New-Alias ..... BackFour
New-Alias e Exitz
New-Alias c clear
# v launches vim

function v {
    vim $args
}

function Back {
    cd ..
}

function BackTwo {
    cd ../..
}

function BackThree {
    cd ../../..
}

function BackFour {
    cd ../../../..
}

function Exitz {
    exit
}

# COMMON DIRECTORIES
del alias:h -Force # was Get-History
New-Alias h Homez
New-Alias dt Desktopz
# New-Alias dl Downloadz # was messing with scoop installation
New-Alias dc Documentz
New-Alias g GRepos
New-Alias gg GLastRepo

function Homez {
    cd 'C:\Users\Ian Hong\'
}

function Desktopz {
    cd 'C:\Users\Ian Hong\Desktop'
}

<#
if i remember correctly this binding is already used
function Downloadz {
    cd 'C:\Users\Ian Hong\Downloads'
}
#>

function Documentz {
    cd 'C:\Users\Ian Hong\Documents'
}

function GRepos {
    cd 'C:\Users\Ian Hong\Desktop\gh'
}

function GLastRepo {
    cd 'C:\Users\Ian Hong\Desktop\gh\ianfromdover'
}


# GIT
Set-Alias gs GStatus
Set-Alias ga GAdd
Set-Alias gd GDiff
Set-Alias gb GBranch
Set-Alias ghb GHub
del alias:gm -Force # default is Get-Member
Set-Alias gm GChkMaster
del alias:gl -Force # default is Get-Location
Set-Alias gl GLog
del alias:gc -Force # default is Get-Content
Set-Alias gc GChk
del alias:gcm -Force # default is Get-Command

function gcm {
    git commit -m $args
}

function GStatus {
    git status
}

function GAdd {
    git add *
    gs
}

function GChk {
    git checkout
}

function GDiff {
    git diff
}

function GBranch {
    git branch
}

function GChkMaster {
    git checkout main
}

function GLog {
    git log --oneline --graph --decorate --all
}

function GHub {
    Start-Process https://github.com/ianfromdover?tab=repositories
}

function gam { # git add all + commit message + push
    ga
    gs
    gcm $args
    git push
}

# APPS
New-Alias t notepad.exe
# New-Alias p python3
New-Alias kmonad 'C:\Users\Ian Hong\Desktop\gh\ianfromdover\keyboards\kmonad-0.4.1-win.exe'
New-Alias iz IzumiKeyboard

function IzumiKeyboard {
 kmonad 'C:\Users\Ian Hong\Desktop\gh\ianfromdover\keyboards\win-izumi.kbd'
}

# Set Vim (Windows) search youtube how to write powershell scripts
function svw {
    # copy vimrc in ianfromdover repo to the following locations:
    '~\.vimrc'
    '~\_vimrc'
    '~\.ideavimrc'
    # this is already available as a separate script in dotfile mgt
}

# GL Compile All
function glca {
    # "C:\Program Files\WindowsPowerShell\powershell.exe" -Parameter "C:\Users\Ian Hong\Desktop\gh\ianfromdover\utils\win_opengl_compile.ps1"
    powershell.exe -Parameter "C:\Users\Ian Hong\Desktop\gh\ianfromdover\utils\win_opengl_compile.ps1"
}

