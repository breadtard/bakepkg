#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

void banner(void) {
        printf("______       _       ______ _   _______ \n");
        printf("| ___ \\     | |      | ___ \\ | / /  __ \\\n");
        printf("| |_/ / __ _| | _____| |_/ / |/ /| |  \\/\n");
        printf("| ___ \\/ _` | |/ / _ \\  __/|    \\| | __ \n");
        printf("| |_/ / (_| |   <  __/ |   | |\\  \\ |_\\ \\\n");
        printf("\\____/ \\__,_|_|\\_\\___\\_|   \\_| \\_/\\____/\n");
        // this might look like shit but it spells out bakepkg trust me
}

int main(int argc, char* argv[]) {

	// Metadata
	char PKG_NAME[] = "INTERNAL_BAKEPKG_REPLACEMENT_STRING_HOPEFULLY_THIS_WORKS";
	char BPKG_VER[] = "INTERNAL_BAKEPKG_VERSION";

	if (access("/usr/bin/7z", 0) == 0) {
		if (argc > 2) {
			printf("Error: Too many arguments. Do %s -h for more info.\n", argv[0]);
			return 1;
		}
		else if (argc == 1) {
			printf("bakepkg - Self Installing 7Z Package\nUsage: %s [-h] [install] [run]\nDo %s -h for more info.\n", argv[0], argv[0]);
			return 2;
		}
		else {
			if (strcmp(argv[1], "-h") == 0) {
				printf("bakepkg - Self Installing 7Z Package\nUsage: %s [-h] [install] [run]\n%s install - Installs the package to your system.\n%s run - installs the package to a temporary directory and starts it. The package is uninstalled on reboot.\n%s -h - Shows this.\n", argv[0], argv[0], argv[0], argv[0]);
				return 0;
			}
			else if (strcmp(argv[1], "--help") == 0) {
				printf("You typed --help, when i said -h. as a punishment i wont newline, and break your prompt.");
				return 69;
			}
			else if (strcmp(argv[1], "install") == 0) {
				banner();
				printf("Installing package %s\nBPKG archive version is %s\n", PKG_NAME, BPKG_VER);
				char INTERNAL_7z_L[] = "/usr/bin/7z x ";
				strcat(INTERNAL_7z_L, argv[0]);
				system(INTERNAL_7z_L);
				return 0;
			}
			else if (strcmp(argv[1], "run") == 0) {
				banner();
				printf("Installing package %s to /tmp...\nBPKG archive version is %s\n", PKG_NAME, BPKG_VER);
				char temp[] = "/tmp/bpkg/";
				char* bpkgdir = strcat(temp, PKG_NAME);
				if (access("/tmp/bpkg", 0) != 0) {mkdir("/tmp/bpkg", S_IRWXU);}
				mkdir(bpkgdir, S_IRWXU);
				char INTERNAL_7z_X[] = "/usr/bin/7z x ";
				strcat(INTERNAL_7z_X, argv[0]);
				strcat(INTERNAL_7z_X, " -o");
				strcat(INTERNAL_7z_X, bpkgdir);
				system(INTERNAL_7z_X);
				strcat(bpkgdir, "/main.sh");
				if (access(bpkgdir, 0) != 0) {printf("Error: The package you are trying to install has a missing main.sh. Please contact the package author.\n"); exit(1);};
				system(bpkgdir);
			}
			else {
				printf("Error: invalid argument. run %s -h for more info.\n", argv[0]);
				return 69;
			}
		}
	 } else {
		 printf("Error: Valid 7z installation not found. Ensure that you have 7zip installed.\n");
		 return 80085; // haha yes
	}
}

