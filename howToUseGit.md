# How I learnt to use Git after I used Github Desktop Before
1. to download all your existing online git stuff in Documents, cd to Documents and make a new dir for all your git stuff. im calling mine gh.

`cd Documents`
`mkdir gh`

2. to get your repo which is already inside github, clone it. you will be prompted to login, so google "github personal access token" or the error message you get when you fail to login. it should end with you adding the gh token to keychain.

`git clone <web address of the repo you want to get>`

3. you've gotten the repo onto your computer (local). now you can use the following commands inside the git dir:

`git status` - what was edited, what needs to be committed

`git branch` - what version are you on?

`git checkout <commit>`  - go back to previous versions. beware, this unrecoverably discards uncommitted changes in the staging area

`git add <filename>` - add the file to be committed. use "." to add everything

`git commit -m "Commit Message which is human readable"` - saves a version, but doesn't sync it yet. it's still on your computer

`git pull` - update your version with the one online. sync and receive new updates.

`git push` - sends all the commits on your computer onto the cloud. aka syncs and publishes it.

`git log --oneline --graph --decorate --all` - see history branches in terms of commit messages

`git tag -a "v1.0.0"` - Add the tag to the most recent commit  

`git push origin --tags` - Push the tags to github  

## To make a new repo directly from command line
1. install github CLI using 

`brew install gh`

2. create your new repo and make it a git repo

`mkdir fish-project`
`cd fish-project`
`git init`

3. create and add your files

`vim README.md`
`vim fishy.js`

4. create the online github repo. the name of the repo will be identical to the filename of the current directory

`gh repo create --source=. --private` // can also be public or internal

5. push your stuff there, enter your gh username and personal access token when they ask for password

`git push --set-upstream origin master`


## Create a git hook that works across all environments
Add `#!/usr/bin/env bash` to the top of the script, not the usual bash one

## Checkout to someone else's branch in someone else's fork
1. Add their fork as another remote to your local repo 

`git remote add zhongfu git@github.com:zhongfu/tp.git`, when I was trying to make edits to zhongfu's branch

2. fetch their repo data first

`git fetch zhongfu`

3. checkout to their branch

`git checkout zhongfu/fix-ui`

