# BakePKG
## A bad way of packaging applications.

### Deprecation Notice
BPKG will stop providing windows support at the end of this month. Any existing packages **will sitll work**, but the build scripts wont be updated, and will be removed from the repo

**Linux Builds will still be updated**

### Introduction
BakePKG is a package archive that can install itself without without a package manager.

The only requirement is `7zip` to extract the archive. BakePKG works on windows, linux, and android*


(* only in termux.)

### Usage
BakePKG currently accepts these options:

| Command           | What it does                                                   |
|-------------------|----------------------------------------------------------------|
| `bakepkg`         | Tells you to run `bakepkg -h` for more info                    |
| `bakepkg -h`      | Shows a help message, usage, and explains the bpkg file format |
| `bakepkg install` | Installs the package                                           |
| `bakepkg run`     | Installs the package into a temporary directory and starts it  |
| `bakepkg --help`  | Yells at you. Its `-h` not `--help` you clown.                 |

### Package Creation (linux chad edition)
To create BakePKG packages (or bpkgs for short), you fist need [mitra](https://github.com/corkami/mitra).

Running `bash download-mitra.sh` will automatically download mitra to the location where it should be.

Then, to create a bpkg, run the following command:
```
bash mkbpkg.sh package-name package-archive.7z
```
For example,
```
bash mkbpkg.sh uwuTerm uwuterm.7z
```

If the package name has spaces, surround the name in quotes.
For example,
```
bash mkbpkg.sh "my finest creation" e621-desktop-client.7z
```


### Package Creation (windows pleb edition)
To create BakePKG packages for windows, you first need
- a linux system
- minigw

With minigw downloaded, just make a package the same way as normal, but this time use the `mkbpkg-win.sh` script.

So, for example,
```
bash mkbpkg-win.sh totally-legal-content microsoft-office-crack.7z
```

### DISCLAIMER
All of the jokes in this readme, like `totally-legal-content microsoft-office-crack.7z` and `e621-desktop-client.7z`, are 
# JOKES
its a joke, dont sue me over this, i am not responsible for what people package, and i dont condone piracy.

### Legal stuff
BakePKG is licensed under the Bread License (which is basically the MIT License, **but** you cannot sell this code, compiled, uncompiled, or modified, **unless** it is bundled with other code which is licensed under a license that permits selling it.

For a better explenation, see [The license file](LICENSE.md)

:wq
