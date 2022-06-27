<#
    Author: Ian Hong
    Last Edit: 13th June 2022
    Reason: Change miryoku to izumi shortcut
    Context: ianfromdover github username change

If you only want this user to execute this, save under
- echo $profile
If you want it to be global, save under
- echo $PsHome
#>

# NAVIGATION
New-Alias .. Back
New-Alias ... BackTwo
New-Alias .... BackThree
New-Alias ..... BackFour
New-Alias e Exitz
New-Alias v vim
New-Alias c clear

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
New-Alias home Homez
New-Alias dt Desktopz
New-Alias dc Documentz
New-Alias g GRepos
New-Alias gg GLastRepo

function Homez {
    cd 'C:\Users\User\'
}

function Desktopz {
    cd 'C:\Users\User\Desktop'
}

function Downloadz {
    cd 'C:\Users\User\Downloads'
}

function Documentz {
    cd 'C:\Users\User\Documents'
}

function GRepos {
    cd 'D:\Ian_Work_Files'
}

function GLastRepo {
    cd 'D:\Unity Projects\trajectorydemo'
}


# GIT
Set-Alias gs GStatus
Set-Alias ga GAdd
Set-Alias gd GDiff
Set-Alias gb GBranch
del alias:gm -Force # default is Get-Member
Set-Alias gm GChkMaster
del alias:gl -Force # default is Get-Location
Set-Alias gl GLog
del alias:gc -Force # default is Get-Content
Set-Alias gc GChk
Set-Alias ghb GHub
del alias:gcm -Force # default is Get-Command

function gcm {
    git commit -m $args
}

function GStatus {
    git status
}

function GAdd {
    git add *
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
New-Alias kmonad 'D:\Ian_Work_Files\ianfromdover\keyboards\kmonad-0.4.1-win.exe'
New-Alias iz IzumiKeyboard

function IzumiKeyboard {
 kmonad 'D:\Ian_Work_Files\ianfromdover\keyboards\win-izumi.kbd'
}


