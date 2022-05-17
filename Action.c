//#include <stdlib.h>
//#include <stdio.h>
#define DIR_LEN 1024
#define FILENAME_LEN 128

Action()
{
	char ch;
	long source, target;
	char current_working_directory[DIR_LEN];
	char source_path[DIR_LEN+FILENAME_LEN];
	char target_path[DIR_LEN+FILENAME_LEN];
	
	//get the current directory path of where the script is execting
	getcwd (current_working_directory, DIR_LEN);
	
	//create the full path for the source file to be copied and the target path
	sprintf (source_path, "%s\\%s", current_working_directory, lr_get_attrib_string("file1"));
	lr_output_message ("File Source: %s", source_path);
	sprintf (target_path, "%s\\%s", lr_get_attrib_string ("target_folder"), lr_get_attrib_string("file1"));
	lr_output_message ("File Target: %s", target_path);
	
	//create the target folder.  If it already exists, no issues.
	mkdir (lr_get_attrib_string ("target_folder"));
	
	//copy source to the target
	//will work across platforms
	if ((source = fopen (source_path, "r")) != NULL){
		if ((target = fopen (target_path, "w")) != NULL){
			while ((ch=getc (source)) && !feof (source)){
				fputc (ch, target);
			}
			fclose (source);
			fclose (target);
		} else {
			lr_error_message("Unable to open target file: %s", target_path);
		}
	} else {
		lr_error_message("Unable to open source file: %s", source_path);
	}
	
	return 0;
}
