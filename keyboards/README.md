# The Izumi Layout

*Izumi is a 42-key layout.* Design Principles:
- uses colemak DH matrix and the Miryoku layout as a base
    - includes all keys found on a TKL layout
    - use layers instead of reaching
    - use sticky keys instead of holding
    - use the home positions as much as possible
    - make use of the thumbs
- if a thumb key is held down, the corresponding hand's home row becomes modifiers that can be held down as well
- qwerty layer for gaming and Unity viewport control
- navigation layer includes arrow keys, `home`, `end`, that you can pair with shift and meta key, `copy`, `paste`, and window toggling
- favourite feature: control music volume and playback directly from the home row
- ergonomics determined by this chart from the colemak github:

![effort values](./imgs/effort.png)

### Base(Alphas) - Colemak DH

![base](./imgs/base.png)

### Qwerty

This layer is for playing Minecraft one-handed and navigating in Unity using WASD.

![qwerty](./imgs/qwerty.png)

### Numbers

![num](./imgs/num.png)

### Code

![code](./imgs/code.png)

### One-Shot

Tapping any button in this layer brings you out of the layer. Meant for quick one-time-use functions.

![oneshot](./imgs/oneshot.png)

### Navigation

![nav](./imgs/nav.png)

### System

![system](./imgs/sys.png)

### Note: Vim Remappings

Allows O(1) access to vim navigation. Sacrifices vim's J, L, K functionality

![vim](./imgs/vim-remap.png)

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

