#!/usr/bin/env bash
shopt -s globstar
shopt -s extglob
echo "______       _       ______ _   _______          __   _____ "
echo "| ___ \     | |      | ___ \ | / /  __ \        /  | |  _  |"
echo "| |_/ / __ _| | _____| |_/ / |/ /| |  \/ __   __\`| | | |/' |"
echo "| ___ \/ _\` | |/ / _ \  __/|    \| | __  \ \ / / | | |  /| |"
echo "| |_/ / (_| |   <  __/ |   | |\  \ |_\ \  \ V / _| |_\ |_/ /"
echo "\____/ \__,_|_|\_\___\_|   \_| \_/\____/   \_/  \___(_)___/ "

cat winstaller.c | sed -e "s/INTERNAL_BAKEPKG_REPLACEMENT_STRING_HOPEFULLY_THIS_WORKS/$1/g" > tempbkgwinstaller.c
/usr/bin/x86_64-w64-mingw32-cc tempbkgwinstaller.c -Os -o tmpbpkg-w.exe
rm tempbkgwinstaller.c
python3 mitra/mitra.py tmpbpkg-w.exe $2
mv S*-PE*-7Z.*.7z.exe $1.bpkg.exe
chmod +x $1.bpkg.exe
rm tmpbpkg-w.exe

