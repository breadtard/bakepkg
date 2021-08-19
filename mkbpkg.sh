#!/usr/bin/env bash
shopt -s globstar
shopt -s extglob
echo " ____        _        ____  _  ______ "
echo "| __ )  __ _| | _____|  _ \| |/ / ___|"
echo "|  _ \ / _\` | |/ / _ \ |_) | ' / |  _"
echo "| |_) | (_| |   <  __/  __/| . \ |_| |"
echo "|____/ \__,_|_|\_\___|_|   |_|\_\____|"


cat installer.c | sed -e "s/INTERNAL_BAKEPKG_REPLACEMENT_STRING_HOPEFULLY_THIS_WORKS/$1/g" | sed -e "s/INTERNAL_BAKEPKG_VERSION/v1.1/g" > tempbkginstaller.c
cc tempbkginstaller.c -Os -o tmpbpkg
rm tempbkginstaller.c
python3 mitra/mitra.py tmpbpkg $2
rm P*-ELF*.*.tmpbpkg.7z
mv S*-ELF-7Z.*.7z.tmpbpkg $1.bpkg
chmod +x $1.bpkg
rm tmpbpkg

