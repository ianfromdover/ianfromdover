<#
If you only want this user to execute this, save under
- echo $profile
If you want it to be global, save under
- echo $PsHome

    Last Edit: 6th June 2022
    Reason: Update GHB address
    Context: ianfromdover github username change
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
    cd 'C:\Users\Ian Hong\Desktop\gh\ian-from-dover'
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
Set-Alias gcm GCmmtM

function GStatus {
    git status
}

function GAdd {
    git add *
}

function GChk {
    git checkout
}

function GCmmtM {
    git commit -m
}

function GDiff {
    git diff
}

function GBranch {
    git branch
}

function GChkMaster {
    git checkout master
}

function GLog {
    git log --oneline --graph --decorate --all
}

function GHub {
    Start-Process https://github.com/ianfromdover?tab=repositories
}

# APPS
New-Alias t notepad.exe
# New-Alias p python3
New-Alias kmonad 'C:\Program Files\kmonad\.stack-work\install\f9de1b14\bin\kmonad.exe'
New-Alias mr Miryoku

function Miryoku {
    kmonad 'C:\Users\Ian Hong\Desktop\gh\miryoku_kmonad\src\build\win_miryoku.kbd'
}

