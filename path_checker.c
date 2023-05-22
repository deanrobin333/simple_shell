#include <stdio.h>
#include "main.h"
#include <dirent.h>
#include <string.h>
/**
 * path_checker - checks the path of commands not specified the path
 * @command_ptr: pointer to commands entered
 * @rpath: pointer to path
 * Return: actual path
 */
char *path_checker(char *command_ptr, char *rpath)
{
	DIR *bin_dir;
	char *folder_name;
	struct dirent *folder;

	bin_dir = opendir("/bin/");
	if (bin_dir == NULL)
		return (NULL);
	folder = readdir(bin_dir);
	while (folder != NULL)
	{
		folder_name = folder->d_name;
		if (strcmp(folder_name, command_ptr) == 0)
		{
			snprintf(rpath, PATH_SIZE, "/bin/%s", command_ptr);
			closedir(bin_dir);
			return (rpath);
		}
		folder = readdir(bin_dir);
	}
	closedir(bin_dir);
	return (NULL);
}
