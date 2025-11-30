#include "libtest.h"

// Weak symbol sentinel - we can't return this from void function, so we'll check list state
extern void ft_list_push_front(t_list **begin_list, void *data);

// Helper function to create a new list node
static t_list *create_node(void *data)
{
	t_list *node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return NULL;
	node->data = data;
	node->next = NULL;
	return node;
}

// Helper function to free entire list
static void free_list(t_list *list)
{
	t_list *tmp;
	
	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}

// Helper function to count list size
static int list_size(t_list *list)
{
	int count = 0;
	
	while (list)
	{
		count++;
		list = list->next;
	}
	return count;
}

// Reference implementation
static void ref_list_push_front(t_list **begin_list, void *data)
{
	t_list *new_node;
	
	if (!begin_list)
		return;
	
	new_node = create_node(data);
	if (!new_node)
		return;
	
	new_node->next = *begin_list;
	*begin_list = new_node;
}

void test_ft_list_push_front(t_test_stats *stats)
{
	char detail[256];
	int passed;
	t_list *list_ft;
	t_list *list_ref;
	
	print_header("Testing ft_list_push_front [BONUS]");
	
	// Check if function exists (try to detect weak symbol by checking if it does anything)
	list_ft = NULL;
	ft_list_push_front(&list_ft, "test");
	if (list_ft == NULL)
	{
		printf("%s  Function not found or not compiled with 'make bonus'%s\n", COLOR_YELLOW, COLOR_RESET);
		if (g_verbose_mode)
			printf("\n");
		return;
	}
	free_list(list_ft);
	
	// Test 1: NULL pointer parameter (should not segfault)
	ft_list_push_front(NULL, "data");
	ref_list_push_front(NULL, "data");
	passed = 1; // If we reach here, it didn't segfault
	snprintf(detail, sizeof(detail), "(NULL pointer parameter: no segfault)");
	print_test_result("NULL pointer parameter (no crash)", passed, detail);
	stats->total++;
	if (passed) stats->passed++;
	else stats->failed++;
	
	// Test 2: Push to empty list (NULL)
	list_ft = NULL;
	list_ref = NULL;
	ft_list_push_front(&list_ft, "first");
	ref_list_push_front(&list_ref, "first");
	passed = (list_ft != NULL && list_ref != NULL && 
			  list_ft->data == list_ref->data &&
			  list_ft->next == NULL && list_ref->next == NULL);
	snprintf(detail, sizeof(detail), "(push \"first\" to NULL: list=%p, data=%s)", 
			 (void*)list_ft, list_ft ? (char*)list_ft->data : "NULL");
	print_test_result("Push to empty list (NULL)", passed, detail);
	stats->total++;
	if (passed) stats->passed++;
	else stats->failed++;
	free_list(list_ft);
	free_list(list_ref);
	
	// Test 3: Push second element
	list_ft = NULL;
	list_ref = NULL;
	ft_list_push_front(&list_ft, "second");
	ft_list_push_front(&list_ft, "first");
	ref_list_push_front(&list_ref, "second");
	ref_list_push_front(&list_ref, "first");
	passed = (list_ft && list_ref &&
			  list_size(list_ft) == 2 && list_size(list_ref) == 2 &&
			  list_ft->data == list_ref->data &&
			  list_ft->next->data == list_ref->next->data);
	snprintf(detail, sizeof(detail), "(size=%d, first=%s, second=%s)", 
			 list_size(list_ft), 
			 list_ft ? (char*)list_ft->data : "NULL",
			 list_ft && list_ft->next ? (char*)list_ft->next->data : "NULL");
	print_test_result("Push second element", passed, detail);
	stats->total++;
	if (passed) stats->passed++;
	else stats->failed++;
	free_list(list_ft);
	free_list(list_ref);
	
	// Test 4: Push multiple elements (5)
	list_ft = NULL;
	list_ref = NULL;
	for (int i = 5; i > 0; i--)
	{
		char *str = malloc(20);
		sprintf(str, "element_%d", i);
		ft_list_push_front(&list_ft, str);
		ref_list_push_front(&list_ref, str);
	}
	passed = (list_size(list_ft) == 5 && list_size(list_ref) == 5);
	if (passed)
	{
		t_list *tmp_ft = list_ft;
		t_list *tmp_ref = list_ref;
		while (tmp_ft && tmp_ref && passed)
		{
			if (tmp_ft->data != tmp_ref->data)
				passed = 0;
			tmp_ft = tmp_ft->next;
			tmp_ref = tmp_ref->next;
		}
	}
	snprintf(detail, sizeof(detail), "(pushed 5 elements: size=%d, order correct=%s)", 
			 list_size(list_ft), passed ? "yes" : "no");
	print_test_result("Push 5 elements", passed, detail);
	stats->total++;
	if (passed) stats->passed++;
	else stats->failed++;
	// Free the strings we allocated
	t_list *tmp = list_ft;
	while (tmp)
	{
		free(tmp->data);
		tmp = tmp->next;
	}
	free_list(list_ft);
	free_list(list_ref);
	
	// Test 5: Push NULL data
	list_ft = NULL;
	list_ref = NULL;
	ft_list_push_front(&list_ft, NULL);
	ref_list_push_front(&list_ref, NULL);
	passed = (list_ft != NULL && list_ref != NULL &&
			  list_ft->data == NULL && list_ref->data == NULL);
	snprintf(detail, sizeof(detail), "(push NULL data: list=%p, data=%p)", 
			 (void*)list_ft, list_ft ? list_ft->data : (void*)0xBAD);
	print_test_result("Push NULL data", passed, detail);
	stats->total++;
	if (passed) stats->passed++;
	else stats->failed++;
	free_list(list_ft);
	free_list(list_ref);
	
	// Test 6: Push integer data
	list_ft = NULL;
	list_ref = NULL;
	int num1 = 42;
	int num2 = 84;
	ft_list_push_front(&list_ft, &num1);
	ft_list_push_front(&list_ft, &num2);
	ref_list_push_front(&list_ref, &num1);
	ref_list_push_front(&list_ref, &num2);
	passed = (list_ft && list_ref &&
			  list_ft->data == &num2 && list_ref->data == &num2 &&
			  list_ft->next->data == &num1 && list_ref->next->data == &num1);
	snprintf(detail, sizeof(detail), "(push ints: first=%d, second=%d)", 
			 list_ft && list_ft->data ? *(int*)list_ft->data : -1,
			 list_ft && list_ft->next && list_ft->next->data ? *(int*)list_ft->next->data : -1);
	print_test_result("Push integer pointers", passed, detail);
	stats->total++;
	if (passed) stats->passed++;
	else stats->failed++;
	free_list(list_ft);
	free_list(list_ref);
	
	// Test 7: Push to existing list maintains order
	list_ft = create_node("existing");
	list_ref = create_node("existing");
	ft_list_push_front(&list_ft, "new");
	ref_list_push_front(&list_ref, "new");
	passed = (list_ft && list_ref &&
			  strcmp((char*)list_ft->data, "new") == 0 &&
			  strcmp((char*)list_ft->next->data, "existing") == 0 &&
			  strcmp((char*)list_ref->data, "new") == 0 &&
			  strcmp((char*)list_ref->next->data, "existing") == 0);
	snprintf(detail, sizeof(detail), "(push to existing: head=%s, next=%s)", 
			 list_ft ? (char*)list_ft->data : "NULL",
			 list_ft && list_ft->next ? (char*)list_ft->next->data : "NULL");
	print_test_result("Push to existing list", passed, detail);
	stats->total++;
	if (passed) stats->passed++;
	else stats->failed++;
	free_list(list_ft);
	free_list(list_ref);
	
	// Test 8: LIFO order (Last In First Out)
	list_ft = NULL;
	list_ref = NULL;
	char *strings[] = {"first", "second", "third", "fourth"};
	for (int i = 0; i < 4; i++)
	{
		ft_list_push_front(&list_ft, strings[i]);
		ref_list_push_front(&list_ref, strings[i]);
	}
	// After pushing in order: first, second, third, fourth
	// List should be: fourth -> third -> second -> first
	passed = (list_ft && list_ref &&
			  list_ft->data == strings[3] &&
			  list_ft->next->data == strings[2] &&
			  list_ft->next->next->data == strings[1] &&
			  list_ft->next->next->next->data == strings[0] &&
			  list_ft->next->next->next->next == NULL);
	snprintf(detail, sizeof(detail), "(LIFO: head=%s, expected=%s)", 
			 list_ft ? (char*)list_ft->data : "NULL", "fourth");
	print_test_result("LIFO order verification", passed, detail);
	stats->total++;
	if (passed) stats->passed++;
	else stats->failed++;
	free_list(list_ft);
	free_list(list_ref);
	
	// Test 9: Push large string
	list_ft = NULL;
	list_ref = NULL;
	char *large_str = "This is a very long string that should be handled correctly by the push_front function without any issues";
	ft_list_push_front(&list_ft, large_str);
	ref_list_push_front(&list_ref, large_str);
	passed = (list_ft && list_ref &&
			  list_ft->data == large_str &&
			  list_ref->data == large_str);
	snprintf(detail, sizeof(detail), "(large string: len=%zu, match=%s)", 
			 strlen(large_str), passed ? "yes" : "no");
	print_test_result("Push large string", passed, detail);
	stats->total++;
	if (passed) stats->passed++;
	else stats->failed++;
	free_list(list_ft);
	free_list(list_ref);
	
	// Test 10: Push many elements (stress test)
	list_ft = NULL;
	list_ref = NULL;
	for (int i = 100; i > 0; i--)
	{
		ft_list_push_front(&list_ft, (void*)(long)i);
		ref_list_push_front(&list_ref, (void*)(long)i);
	}
	passed = (list_size(list_ft) == 100 && list_size(list_ref) == 100);
	if (passed)
	{
		t_list *tmp = list_ft;
		for (int i = 1; i <= 100 && tmp && passed; i++)
		{
			if ((long)tmp->data != i)
				passed = 0;
			tmp = tmp->next;
		}
	}
	snprintf(detail, sizeof(detail), "(stress test: pushed 100 elements, size=%d, order=%s)", 
			 list_size(list_ft), passed ? "correct" : "incorrect");
	print_test_result("Stress test (100 elements)", passed, detail);
	stats->total++;
	if (passed) stats->passed++;
	else stats->failed++;
	free_list(list_ft);
	free_list(list_ref);
	
	// Test 11: Push empty string
	list_ft = NULL;
	list_ref = NULL;
	ft_list_push_front(&list_ft, "");
	ref_list_push_front(&list_ref, "");
	passed = (list_ft && list_ref &&
			  list_ft->data == list_ref->data &&
			  strlen((char*)list_ft->data) == 0);
	snprintf(detail, sizeof(detail), "(empty string: data=\"\", len=%zu)", 
			 list_ft && list_ft->data ? strlen((char*)list_ft->data) : 999);
	print_test_result("Push empty string", passed, detail);
	stats->total++;
	if (passed) stats->passed++;
	else stats->failed++;
	free_list(list_ft);
	free_list(list_ref);
	
	if (g_verbose_mode)
		printf("\n");
}
