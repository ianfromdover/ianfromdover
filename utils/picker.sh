#!/usr/bin/env bash
# if user is on mac and doesn't have brew, ffmpeg or yt-dlp, install them

playlists=$@
list_num=$#
first=$1

# Colours :D
NC='\033[0m' # No Color
BOLD='\033[1m'
RED='\033[0;31m'
GREEN='\033[0;32m'

function check_install {
    echo "Package versions found:"
    brew -v
    if [[ $? -ne 0 ]]; then
        /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)";
        brew install yt-dlp
        brew install ffmpeg
    else
        ffmpeg -version || brew install ffmpeg
        yt-dlp --version || brew install yt-dlp
    fi
}

function is_website {
    regex='(https?|ftp|file)://[-[:alnum:]\+&@#/%?=~_|!:,.;]*[-[:alnum:]\+&@#/%=~_|]'
    if [[ $1 =~ $regex ]]; then 
        exit 0
    else
        exit 1 # fail
    fi
}

function downl_playlst {
    # downloads the vid in mp3, naming as "Coldplay - Viva La Vida.mp3"
    yt-dlp --ignore-errors --format bestaudio --extract-audio --audio-format mp3 --audio-quality 160K --output "%(channel)s - %(title)s.%(ext)s" --yes-playlist "$1"
    echo # newline

    # alert success
    if [[ $? -ne 0 ]]; then
        echo -e "${RED}There was an error downloading${NC}"
    else
        echo -e "\U2705 ${GREEN}Successfully downloaded and converted!${NC}"
    fi
}


# welcome message
echo -e "\U1F344 Welcome to                        v2.0
██████╗ ██╗ ██████╗██╗  ██╗███████╗██████╗
██╔══██╗██║██╔════╝██║ ██╔╝██╔════╝██╔══██╗
██████╔╝██║██║     █████╔╝ █████╗  ██████╔╝
██╔═══╝ ██║██║     ██╔═██╗ ██╔══╝  ██╔══██╗
██║     ██║╚██████╗██║  ██╗███████╗██║  ██║
╚═╝     ╚═╝ ╚═════╝╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝ "
echo "The youtube-to-mp3 playlist downloader and converter."
echo # newline

# if dk how to use
# if [[ -z $first ]] || is_website $first; then # how to run funcs in if?
if [[ -z $first ]]; then
    echo "Usage: ./picker <link to playlist1> <link to playlist2> ..."
    echo -e "Ensure you used links to ${BOLD}Unlisted${NC} playlists."
    exit 1
fi

# check_install
echo -e "Your songs will be saved to:${BOLD}"
for i in $(seq 1 $list_num); do
    echo "$(pwd)/$i"
done
echo # newline

echo "========================================================="
echo -e "\U1F344 Starting download and conversion using ${BOLD}yt-dlp${NC}"
echo "========================================================="

counter=1
for i in $playlists; do
    subpath="$(pwd)/$counter"
    mkdir $subpath
    cd $subpath
    ((counter++))
    downl_playlst $i &
    cd ../
done

echo -e "Opening save location..."
open .

# change emoji here:
# https://unicode.org/emoji/charts/full-emoji-list.html

# ascii text from
# https://patorjk.com/software/taag/#p=display&h=0&v=0&f=ANSI%20Shadow&t=PICKER

