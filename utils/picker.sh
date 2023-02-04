#!/usr/bin/env bash
# if user is on mac and doesn't have ffmpeg and yt-dl,
# brew install youtube-dl
# brew install ffmpeg

# define formatting consts
BOLD='\033[1m'
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

# welcome message
echo -e "\U1F344 Welcome to                        v1.0
██████╗ ██╗ ██████╗██╗  ██╗███████╗██████╗
██╔══██╗██║██╔════╝██║ ██╔╝██╔════╝██╔══██╗
██████╔╝██║██║     █████╔╝ █████╗  ██████╔╝
██╔═══╝ ██║██║     ██╔═██╗ ██╔══╝  ██╔══██╗
██║     ██║╚██████╗██║  ██╗███████╗██║  ██║
╚═╝     ╚═╝ ╚═════╝╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝ "
echo "The youtube-to-mp3 playlist downloader and converter."
echo # newline
echo -n -e "Your songs will be saved to ${BOLD}"
pwd
echo # newline
echo -e "\U23EC ${BOLD}Paste${NC} the link to your unlisted YouTube playlist:"

# get user input
read LINK
echo # newline

echo -e "\U1F344 Starting download and conversion using ${BOLD}youtube-dl${NC}"
echo # newline

# improvement: grab channel's name also for the artist
youtube-dl --ignore-errors --format bestaudio --extract-audio --audio-format mp3 --audio-quality 160K --output "%(title)s.%(ext)s" --yes-playlist $LINK
echo # newline

# alert success
echo -e "\U2705 ${GREEN}Successfully downloaded and converted! Opening save location.${NC}"
open .

# handle failure
# echo -e "${RED}There was an error downloading${NC}"

echo -n -e "if you see ${RED}env: python: No such file or directory${NC}, install youtube-dl or overwrite its links"
echo # newline


# change emoji here:
# https://unicode.org/emoji/charts/full-emoji-list.html

# ascii text from
# https://patorjk.com/software/taag/#p=display&h=0&v=0&f=ANSI%20Shadow&t=PICKER

