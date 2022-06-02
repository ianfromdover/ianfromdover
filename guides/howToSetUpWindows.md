# How to Set Up Windows

1. Set the keyboard repeat rate

`Win-R`
`control keyboard`

2. Get Scoop to install the other programs

```powershell
Set-ExecutionPolicy RemoteSigned -Scope CurrentUser // Optional: Needed to run a remote script the first time
Invoke-WebRequest get.scoop.sh | Invoke-Expression
```

3. Install git

```powershell
scoop install git
```

4. Install vim

```powershell
scoop install vim
```

5. Add powershell shortcuts and vimrc to home folder

    i. make an appropriate folder to place my personal files

    ii. get my personal shortcut files

    ```powershell
    git clone https://github.com/ian-from-dover/ian-from-dover.git
    ```

    iii. place the vimrc in the home folder. note the change to underscore.

    ```powershell
    cp vimrc.txt ~/_vimrc
    ```

    iv. remove the colour settings line because powershell is ugly

    ```vim
    set t_Co=256
    ```

    v. // TODO: find out how to set the powershell colour properties. Is there a file somewhere that i can copy paste?

    vi. place the powershell profile in its directory

    If you only want this user to have this powershell profile, save it under the path returned by this command

        ```powershell
        echo $profile
        ```
        If you want all users to use it, save it under this path instead

        ```powershell
        echo $PsHome
        ```

    vii. Remember to edit the cd functions

6. If authorised, use PowerToys to remap the win, alt and ctrl keys to resemble MacOS.

7. Set up complete!

