# IDE Shortcuts / Keymaps
- TODO: make Cmd-1,2,3 be window 1,2,3.

| Function            | JetBrains IDEs        | VS Code      | Custom    |
| ------------------- | --------------------- | ------------ | --------- |
| Settings            | Ctrl-Alt-S            | Cmd-,        | Cmd-,     |
| Search Everywhere   | Shift-Shift           | Ctrl-P       | Sft-Sft   | <VS Go To File />
| Run Anything        | Ctrl-Ctrl             | Shift-Ctrl-P | Ctl-Ctl   | <VS Show all commands />
| Run Code            | F5                    | F5           | Cmd-R     | <VS Run is Debug />
| Debug Code          | F5                    | F5           | Sft-Cmd-R |
| Build               | F5                    | F5           | Cmd-B     |
| -- EDIT ACTIONS --  |                       |              |           |
| Context Action      | Alt-Enter             | Ctrl-.       | Alt-Enter | <VS Quick Fix />
| Rename Symbol       | Shift-F6              | F2           | Alt-S     |
| Preview Declaration | Ctrl-B (vim conflict) | F12          | Alt-D     | <JB Go To Declaration or Usages />
| Show Usages         | Alt-F7                | Shift-F12    | Alt-F     | <VS Peek References. Note: NOT "Find" Usages />
| -- TOOL WINDOWS --  |                       |              |           |
| Terminal            | Alt-F12               | Ctrl-\`      | Alt-Z     |
| Project / Explorer  | Alt-1                 | Ctrl-Shift-E | Alt-1     | <VS Show Explorer />
| Structure           | ??                    | ??           | Sft-Alt-1 | 
| File Changes(Commit)| ??                    | NA           | Alt-2     | <VS Open Changes />
| Version Control     | Alt-9                 | Ctrl-Shift-G | Sft-Alt-2 | <VS Show Source Control />
| Run Panel           | ??                    | ??           | Alt-3     | <VS Show Run and Debug. />
| Debug Panel         | Alt-4                 | Ctrl-Shift-D | Sft-Alt-3 | <VS Show Run and Debug. />
| Problems            | Alt-6                 | F8           | Alt-4     | <VS Toggle Problems />
| TODO                | ??                    | ??           | Sft-Alt-4 |
| Unit Testing        | ??                    | ??           | Alt-5     |
| Reveal in Finder    | ??                    | Opt-Cmd-R    | Alt-V     | <VS Open Changes />

# ensure it doesn't conflict with:
- vim
- system shortcuts (eg. rectangle, alfred, notion)

### VS
- switch tabs: Cmd 123. Switch panels: Alt- 123. hide vs code activity bar.
- extension: resize window with [ and ]?
- extension: fold/expand all regions

### Installation
Rider, IntelliJ, CLion: File > Manage IDE Settings > Import Settings... > choose the zip file

VS Code: Command Palette > Open Keyboard Shortcuts (JSON), Explorer: view open editors, show keybindings in finder
replace keybindings.json in /Users/YOUR_USER_NAME/Library/Application Support/Code/User

