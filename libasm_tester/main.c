#include "libtest.h"

int main(int argc, char **argv)
{
	char libasm_path[1024];
	t_test_stats stats = {0, 0, 0};
	
	// Print welcome message
	printf("\n%s", COLOR_MAGENTA);
	printf("╔════════════════════════════════════════════════════════════╗\n");
	printf("║                                                            ║\n");
	printf("║              LIBASM COMPREHENSIVE TEST SUITE               ║\n");
	printf("║                                                            ║\n");
	printf("╚════════════════════════════════════════════════════════════╝\n");
	printf("%s\n", COLOR_RESET);
	
	// Check if path was provided as argument
	if (argc >= 2)
	{
		strncpy(libasm_path, argv[1], sizeof(libasm_path) - 1);
		libasm_path[sizeof(libasm_path) - 1] = '\0';
		printf("%sUsing libasm path from argument: %s%s\n", 
			COLOR_CYAN, libasm_path, COLOR_RESET);
	}
	else
	{
		// Prompt for libasm path
		printf("%sEnter the path to your libasm project: %s", 
			COLOR_CYAN, COLOR_RESET);
		fflush(stdout);
		
		if (fgets(libasm_path, sizeof(libasm_path), stdin) == NULL)
		{
			printf("%sError: Failed to read path%s\n", COLOR_RED, COLOR_RESET);
			return 1;
		}
		
		// Remove trailing newline
		size_t len = strlen(libasm_path);
		if (len > 0 && libasm_path[len - 1] == '\n')
			libasm_path[len - 1] = '\0';
	}
	
	// Validate path
	if (strlen(libasm_path) == 0)
	{
		printf("%sError: Empty path provided%s\n", COLOR_RED, COLOR_RESET);
		return 1;
	}
	
	// Build libasm
	printf("\n%sBuilding libasm...%s\n", COLOR_YELLOW, COLOR_RESET);
	char make_cmd[2048];
	snprintf(make_cmd, sizeof(make_cmd), "make -C %s 2>&1", libasm_path);
	
	int make_result = system(make_cmd);
	if (make_result != 0)
	{
		printf("%sWarning: make returned non-zero status. Continuing anyway...%s\n", 
			COLOR_YELLOW, COLOR_RESET);
	}
	else
	{
		printf("%sLibasm built successfully!%s\n", COLOR_GREEN, COLOR_RESET);
	}
	
	// Validate libasm.a exists
	char lib_file[2048];
	snprintf(lib_file, sizeof(lib_file), "%s/libasm.a", libasm_path);
	FILE *f = fopen(lib_file, "r");
	if (!f)
	{
		printf("%sError: libasm.a not found at %s%s\n", 
			COLOR_RED, lib_file, COLOR_RESET);
		printf("%sPlease make sure your libasm project builds correctly.%s\n",
			COLOR_YELLOW, COLOR_RESET);
		return 1;
	}
	fclose(f);
	
	printf("%sFound libasm.a at %s%s\n\n", COLOR_GREEN, lib_file, COLOR_RESET);
	
	// Run tests
	printf("%s════════════════════════════════════════════════════════════%s\n", 
		COLOR_CYAN, COLOR_RESET);
	printf("%s                    MANDATORY FUNCTIONS                     %s\n", 
		COLOR_WHITE, COLOR_RESET);
	printf("%s════════════════════════════════════════════════════════════%s\n\n", 
		COLOR_CYAN, COLOR_RESET);
	
	test_ft_strlen(&stats);
	test_ft_strcpy(&stats);
	test_ft_strcmp(&stats);
	test_ft_write(&stats);
	test_ft_read(&stats);
	test_ft_strdup(&stats);
	
	printf("%s════════════════════════════════════════════════════════════%s\n", 
		COLOR_CYAN, COLOR_RESET);
	printf("%s                     BONUS FUNCTIONS                        %s\n", 
		COLOR_WHITE, COLOR_RESET);
	printf("%s════════════════════════════════════════════════════════════%s\n\n", 
		COLOR_CYAN, COLOR_RESET);
	
	test_ft_atoi_base(&stats);
	test_ft_list_push_front(&stats);
	test_ft_list_size(&stats);
	test_ft_list_sort(&stats);
	test_ft_list_remove_if(&stats);
	
	// Print final summary
	print_summary(stats);
	
	return (stats.failed > 0) ? 1 : 0;
}


