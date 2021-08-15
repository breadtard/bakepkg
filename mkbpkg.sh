#!/usr/bin/env bash
shopt -s globstar
shopt -s extglob
echo "______       _       ______ _   _______          __   _____ "
echo "| ___ \     | |      | ___ \ | / /  __ \        /  | |  _  |"
echo "| |_/ / __ _| | _____| |_/ / |/ /| |  \/ __   __\`| | | |/' |"
echo "| ___ \/ _\` | |/ / _ \  __/|    \| | __  \ \ / / | | |  /| |"
echo "| |_/ / (_| |   <  __/ |   | |\  \ |_\ \  \ V / _| |_\ |_/ /"
echo "\____/ \__,_|_|\_\___\_|   \_| \_/\____/   \_/  \___(_)___/ "

cat installer.c | sed -e "s/INTERNAL_BAKEPKG_REPLACEMENT_STRING_HOPEFULLY_THIS_WORKS/$1/g" | sed -e "s/INTERNAL_BAKEPKG_VERSION/v1.1/g" > tempbkginstaller.c
cc tempbkginstaller.c -Os -o tmpbpkg
rm tempbkginstaller.c
python3 mitra/mitra.py tmpbpkg $2
rm P*-ELF*.*.tmpbpkg.7z
mv S*-ELF-7Z.*.7z.tmpbpkg $1.bpkg
chmod +x $1.bpkg
rm tmpbpkg

