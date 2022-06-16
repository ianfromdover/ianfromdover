# The Izumi Layout

*Izumi is a 36-key layout.* Features: 
- uses colemak DH matrix and Miryoku's home-row modifiers as a base
- has half the number of layers Miryoku has, making it easier to learn
- number row is on the top of the keyboard (if you're not used to a number pad)
- navigation layer has arrow keys, `home`, `end`, `copy`, `paste`, and many useful shortcuts
- favourite feature: control music volume and playback directly from the home row

### All
![all](./imgs/all.png)

### Base - Colemak DH Matrix
Also known by more avid keyboard enthusiasts as 'alphas'.

![base](./imgs/base.png)

### Qwerty

This layer is for Unity's WASD and Vim (until kmonad gets repeat key support). For now, the emulated arrow keys suffice for navigation.

*Work in progress*

![qwerty]()

### Numbers and Symbols

![nsm](./imgs/num.png)

### Navigation

![nav](./imgs/nav.png)

### Media

![media](./imgs/media.png)

### Function

![func]()

# Running the Izumi Layout

## Windows
1. Simply navigate to this folder
2. use the `kmonad.exe` to run any .kbd file
3. for `win-izumi.kbd`, quit by selecting this terminal again, do NAV-q, and type Ctrl-c again to cancel the kmonad process

## MacOS
1. Follow the kmonad installation instructions below to install kmonad 
2. use the ./kmonad in the installation path to run the `mac-izumi.kbd` file
3. quit by selecting this terminal again and type `NAV-q` to cancel the kmonad process.  

4. (highly recommended) Create an alias `iz` to start this process easily from the terminal.

# Install KMonad on Mac
1. Follow the [guide on the KMonad](https://github.com/kmonad/kmonad/blob/master/doc/installation.md#installing-the-dext) repo to install kmonad on MacOS. I installed the `dext` because the kext had problems.
2. `brew install stack` 
3. `stack` might timeout when installing, just wait half an hour and try again.
4. The new kmonad executable is in `/Users/USERNAME/Documents/PATH-THAT-YOU-CLONED-KMONAD/kmonad/.stack-work/install/x86_64-osx/SOME-HASH/8.10.7/bin/kmonad`

