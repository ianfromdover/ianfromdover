set nocp

" nocp explanation:
" When cp is set, numerous other options are set to make Vim as
" Vi-compatible as possible.  When this option is unset, various options
" are set to make Vim more useful.

" Owner: Hong Yi En, Ian <ianfromdover>
" Last Change: 19 Jun 2023 (to test in Rider)
" Why: Add mvt plugins like vim-sneak
" Next Improvements:
"   - move to neovim, but make it lighter than chadvim
"   - group plugin settings and mappings to that plugin (increase modularity)
"   - test in Rider
" Usage Notes:
"   - Plugins managed by vim-plug
"   - in Gallium mode, to undo, do double stroke instead of pressing once.
"     this is to overcome the timeout problem. uu instead of u
"   - word counter appears for markdown and txt files

" -----------------------
" -- Essential Options --
" -----------------------


""" Common Settings --------------------------------

syntax on         " on colours
set re=0          " set regexp engine automatically, makes syntax on c++ files work
set nu            " show the current line's absolute number
set rnu           " relative line numbers
set ruler         " show cursor's (row, col)
set cc=80         " colorcolumn at 80 chars length
set so=5          " scrolloff: always show 5 lines around the cursor for context
set backspace=eol,start,indent " allow backspacing over indent,eol,start in insert mode 

" when escaping, make cursor stay in the same position
autocmd InsertLeave * :normal! `^
set virtualedit=onemore

" stop the whole screen from flashing when cursor reaches end of page or cannot find search results
set noeb  " no error bell for error messages
set vb t_vb= " disable flashing visualbell

" enable clicking mouse to place cursor and enter visual mode
set mouse+=a

" indentation help
set expandtab     " <tab> expands into spaces instead. this is the expectation for com sci
set smarttab      " pressing <tab> inserts spaces according to shiftwidth, 
                  " tabstop is used when cursor is in other places
                  " <backspace> deletes a shiftwidth worth of space at start
                  " of line
set shiftwidth=0 " autoindent is 4 spaces
set tabstop=4    " <tab> becomes 4 spaces, sometimes ppl set to 2
set autoindent   " copy indent of current line when starting a new line
set smartindent  " insert indent:
" - After a line ending in '{'.
" - After a line starting with a keyword from 'cinwords'.
" - Before a line starting with '}'
set linebreak     " if line too long, wrap its appearance to the next line (tho in the file it's still one line)

set listchars=tab:▸\ 
" temporarily see end of line add this
" ,eol:¬
" :h listchars to see how to do trailing spaces
set list

" file handling
filetype plugin indent on " enables plugin per filetype & enables auto-indent per filetype
set showcmd       " shows partial command on last line of screen
set nobackup      " both of these to not create a backup

" Searching 
set hls           " highlight search matches
set is            " Inclusive Search: show partial matches as you type
set wildmenu      " show autocomplete options in command mode
set sm            " showmatch: on typing a closing bracket, 
                  " cursor briefly moves to its corresponding opening bracket



" ---------------------------------------
" -- Load Plugins and Custom Functions --
" ---------------------------------------

""" Custom Functions  --------------------------------
" Lets user use original vim bindings with Ian's modified Gallium keyboard input
let g:inGalliumMode = 0
function ToggleGallium()
    if g:inGalliumMode ==# 0

        " pattern:
        " gallium key -> qwerty vim command
" previous version was izumi canary

        " escape with .,
        imap ., <nop>
        cnoremap ., <nop>

        " escape with .,
        imap ;' <Esc>
        cnoremap ;' <C-C>

        " movement
        noremap p h
        noremap h j
        noremap a k
        noremap e l

        noremap l w
        noremap j b
        noremap d e
        noremap k n
        noremap K N

        noremap f m
        noremap / ;
        noremap ? "
        noremap . /
        noremap > ?
        
        " enter insert mode
        noremap o i
        noremap O I
        noremap n a
        noremap N A
        noremap u o
        noremap U O
        noremap c r
        noremap C R

        " jumping
        noremap s f
        noremap S F
        noremap v t
        noremap V T
        " plugin vim-sneak
        noremap r <Plug>Sneak_s
        noremap R <Plug>Sneak_S
        noremap i ;
        noremap I :

        " editing
        noremap m c
        noremap M C
        noremap t d
        noremap T D
        noremap z y
        noremap Z Y
        noremap , p
        noremap < P
        noremap y u
        noremap yy u
        noremap x x
        noremap H J
        noremap ; .

        " others
            " macros (@@ is repeat last macro)
        noremap b q
            " quick file opening and closing, folds
        noremap q z
        noremap Q Z
        noremap QQ ZZ
            " enter visual mode
        noremap w v
        noremap W V

        let g:inGalliumMode = 1
        echom "-- GALLIUM ENABLED --"
    else
        " to change layout,
        " copy paste above, then noremap -> unmap, delete 2nd arg

        " escape with .,
        imap ;' <nop>
        cnoremap ;' <nop>
        " escape with .,
        imap ., <Esc>
        cnoremap ., <C-C>

        unmap h
        unmap a
        unmap e
        unmap i
        unmap l
        unmap j
        unmap d
        unmap k
        unmap K
        unmap f
        unmap /
        unmap ?
        unmap .
        unmap >
        unmap o
        unmap O
        unmap n
        unmap N
        unmap u
        unmap U
        unmap r
        unmap R
        unmap c
        unmap C
        unmap m
        unmap M
        unmap t
        unmap T
        unmap z
        unmap Z
        unmap ,
        unmap <
        unmap y
        unmap yy
        unmap x
        unmap H
        unmap ;
        unmap b
        unmap q
        unmap Q
        unmap QQ
        unmap w
        unmap W

        let g:inGalliumMode = 0
        echom "-- GALLIUM DISABLED --"
    endif
endfunction

" Enable vim-plug
" Note: if installing for the first time, download plug.vim from junegunn/vim-plug/master/plug.vim
" Note: after pasting this vimrc, run :PlugInstall to install the plugins

call plug#begin('~/.vim/plugged')
" call plug#begin('~/vimfiles/plugged') is the proper way for windows, but i
" am lazy and i just let it create a new .vim folder for the plugins files

""" Plugins  --------------------------------
Plug 'dense-analysis/ale'       " lint, go do definition, find references
Plug 'ackyshake/VimCompletesMe' " tab completion
Plug 'justinmk/vim-sneak'       " better jumping around
Plug 'tpope/vim-fugitive'       " README: https://github.com/tpope/vim-fugitive
Plug 'tpope/vim-repeat'         " lets you repeat plugin cmds
Plug 'tpope/vim-commentary'     " gcc comment line out, gc{ comment block out
Plug 'tpope/vim-surround'       " cs[' change surrounding [ to ', 
                                  " can del or add too, README: https://github.com/tpope/vim-surround
Plug 'junegunn/fzf', { 'do': { -> fzf#install() } }
Plug 'junegunn/fzf.vim'         " README: https://github.com/junegunn/fzf.vim
Plug 'itchyny/lightline.vim'    " pretty status line
Plug 'maximbaz/lightline-ale'   " ALE for lightline

Plug 'mattn/emmet-vim'          " expand to html faster
Plug 'Yggdroot/indentLine'      " show html levels
Plug 'yuezk/vim-js'
Plug 'sheerun/vim-polyglot'

call plug#end() " init plugin systems

""" Plugin Options  --------------------------------
set laststatus=2 " enable lightline
set showmode   " enable -- INSERT -- for Rider

" vim-sneak: let f and t be multiline
" nnoremap f <Plug>Sneak_f
" nnoremap F <Plug>Sneak_F
" nnoremap t <Plug>Sneak_t
" nnoremap T <Plug>Sneak_T
" note: currently not working

" enable Prettier fixer for languages i use
" use :ALEFix in these files to run Prettier
let g:ale_fixers = {'javascript': ['prettier'], 'css': ['prettier'], 'html': ['prettier'], 'csharp':['clang-format']}
let g:ale_completion_enabled = 1

" vim-sneak: enable label-mode
let g:sneak#label = 1

let g:lightline = {
    \ 'active': {
    \   'left': [ [ 'mode', 'paste' ],
    \             [ 'readonly', 'filename' ],
    \             [ 'galliummode' ],
    \             [ 'gitbranch' ] ],
    \   'right': [ [ 'lineinfo' ],
    \              [ 'wordcount', 'percent' ],
    \              [ 'fileformat', 'fileencoding', 'filetype' ]]
    \ },
    \ 'component_function': {
    \   'filename': 'LightlineFilename',
    \   'wordcount': 'LightlineWordCount',
    \   'galliummode': 'LightlineGalliumMode',
    \   'gitbranch': 'FugitiveHead',
    \   'fileformat': 'LightlineFileformat',
    \   'fileencoding': 'LightlineFileencoding',
    \   'filetype': 'LightlineFiletype'
    \ },
    \ }
  
    " Hides file format
    function! LightlineFileformat()
      return ''
    endfunction

    " Hides file encoding
    function! LightlineFileencoding()
      return ''
    endfunction

    " Hides filetype on short windows
    function! LightlineFiletype()
      return winwidth(0) > 50 ? (&filetype !=# '' ? &filetype : 'no ft') : ''
    endfunction

    " Custom modified sign
    function! LightlineFilename()
      let filename = expand('%:t') !=# '' ? expand('%:t') : 'Untitled'
      let modified = &modified ? ' [+]' : ''
      return filename . modified
    endfunction

    " Displays 'G' with yellow bg when using gallium mode
    function! LightlineGalliumMode()
      return g:inGalliumMode ==# 1 ? 'G' : ''
    endfunction

    function! LightlineWordCount()
        if &filetype ==# 'markdown' || &filetype ==# 'text'
            return CountWords()
        else
            return ''
        endif
    endfunction
    " Displays the word count for selected file types
    " Referenced from https://www.vivi.sh/blog/technical/live-wordcount-vim-airline/index
    function! CountWords()
        let position = getpos(".")
        exe ":silent normal g\<c-g>"
        let stat = v:statusmsg
        let s:word_count = 0
        if stat !=# '--No lines in buffer--'
            if mode() ==# "V"
                let s:word_count = str2nr(split(stat)[5])
            else
                let s:word_count = str2nr(split(stat)[11])
            endif
        endif
        call setpos('.', position)
        return s:word_count
    endfunction


" ---------------------
" -- Custom Mappings --
" ---------------------
    " see ide shortcuts here: https://github.com/ianfromdover/ianfromdover/tree/main/ide
    " == leader bindings ==
    " LD-L clear highlights
    " LD-GL toggle gallium mode
    " LD-B toggle prev buffer
    " LD-W toggle btwn windows
    " LD-O reveal in finder
    " LD-Z open vsplit term
    " LD-B toggle prev buffer
    "
    " - plugins -
    " LD-G fzf (global)
    " LD-P fzf (git) (C-V for vs, C-X for sp)
    " LD-BL buffer list with fzf (:bd 2 closes buffer 2)
    " LD-Y Git commit tree
    " LD-LD Search everywhere (Ag)
    " Ale:
    " LD-S rename
    " LD-D definition
    " LD-F find usages
    " LD-H toggle linting



""" My Mappings  --------------------------------
" escape with .,
imap ., <Esc>
cnoremap ., <C-C>

" Space: leader
let mapleader = " "

" I HAVENT FOUND OUT HOW TO MAKE THE LETTERS RECURSE
" So, if the user is using gallium, they must type the leader sequence in
" gallium
"
" Solutions:
" idea 1: find out the text mode using leader is
" idea 2: put the mappings below into a function, when
"       gallium mode is on or off, call the function again

" Lead_L: Clears search highlighting. <CR> means Hit Return
nmap <silent> <leader>l :let @/ = ""<CR>

" Lead_GL: Toggle Gallium mode
" TODO: muscle-memory learn the gl shortcut
nmap <leader>gl :call ToggleGallium()<Cr>

" Lead_B: Previous Buffer
nmap <leader>b :bp<Cr>

" Lead_W: Toggle between windows
nmap <leader>w <C-w>p

" Lead_O: Reveal in Finder
" replace . with current file variable (google how to get)
nmap <leader>o :!open .<Cr>

" Lead_Z: Terminal
nmap <leader>z :vert ter<Cr>



""" Plugin Mappings  --------------------------------
" Lead_G: Global FZF, Ctrl-V for vs, Ctrl-X for sp.
nmap <leader>g :Files<Cr>

" Lead_P: (git) FZF. Ctrl-V for vs, Ctrl-X for sp.
nmap <leader>p :GFiles<Cr>

" Lead_BL: FZF Buffer List
" :bd 2 to close buffer 2
nmap <leader>bl :Buffers<Cr>

" Lead_Lead: (git) Search Everywhere
nmap <leader><leader> :Ag<Cr>

" Lead_Y: Git Commit Tree
nmap <leader>y :Commits<Cr>

" ALE commands
    " Lead_S: rename
    " Lead_D: definition
    " Lead_F: find usages
    " Lead_H: toggle linting
nmap <leader>s :ALERename<Cr>
nmap <leader>d :ALEGoToDefinition<Cr>
nmap <leader>f :ALEFindReferences<Cr>
nmap <leader>h :ALEToggle<Cr>

" ---- End of File ----

