#include <stdio.h>
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
	if (access("C:/Program Files/7-Zip/7z.exe", F_OK) == 0) { // check if file is real
		if (argc > 2) {
			printf("Error: Too many arguments. Do %s -h for more info.\n", argv[0]);
			return 1;
		}
		else if (argc == 1) {
			printf("bakepkg - Self Installing 7Z Package\nUsage: %s [-h] [install]\nDo %s -h for more info.\n", argv[0], argv[0]);
			return 2;
		}
		else {
			if (strcmp(argv[1], "-h") == 0) {
				printf("bakepkg - Self Installing 7Z Package\nUsage: %s [-h] [install]\n%s install - Installs the package to your system.\n%s -h - Shows this.\nThis file is both an executable and a 7z archive. This executable's purpose is to extract the archive and install it to your system.\n", argv[0], argv[0], argv[0]);
				return 0;
			}
			else if (strcmp(argv[1], "--help") == 0) {
				printf("You typed --help, when i said -h. as a punishment i wont newline, and break your prompt.");
				return 69;
			}
			else if (strcmp(argv[1], "install") == 0) {
				banner();
				printf("Installing package %s\nBPKG archive version is %s\n", PKG_NAME, BPKG_VER);
				char INTERNAL_7z_L[] = "\"C:/Program Files/7-Zip/7z\" x ";
				strcat(INTERNAL_7z_L,argv[0]);
				system(INTERNAL_7z_L);
				return 0;
			}
			else {
				printf("Error: Invalid argument. do %s -h for more info.\n", argv[0]);
				return 69;
			}
		}
	} else {
		print("Error: 7z installation not found. Ensure that there is a valid 7zip installation at C:/Program Files/7-Zip/\n");
		return 80085 // haha yes
	}
}
