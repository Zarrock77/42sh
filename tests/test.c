/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <assert.h>
#include <stdlib.h>
#include "../include/mysh.h"

Test(my_putstr, Test_hello_worl, .init = cr_redirect_stdout)
{
    my_putstr("Hello World!");
    cr_assert_stdout_eq_str("Hello World!");
}

Test(my_strlen, Test_my_strlen)
{
    int a = my_strlen("je");
    cr_assert_eq(a, 2, "my_strlen(\"je\") should return 2");
}

Test(my_putchar, Test_hello_worl, .init = cr_redirect_stdout)
{
    my_putchar('H');
    cr_assert_stdout_eq_str("H");
}
Test(my_strdup, Test_strdup)
{
    const char *original_str = "je suis le laitier";
    char *str = my_strdup(original_str);
    cr_assert_str_eq(str, original_str, "my_strdup did not copy the string correctly");
    free(str);
}

Test(my_strdup, Test_strdup_si_null)
{
    const char *original_str = NULL;
    char *str = my_strdup(original_str);
    cr_assert_null(str, "my_strdup should return NULL when called with a NULL argument");
    cr_expect_eq(str, NULL, "my_strdup should return NULL when called with a NULL argument");
}

Test(check_char, Test_check_char)
{
    cr_assert_eq(check_char('\t'), 1);
    cr_assert_eq(check_char('\"'), 1);
    cr_assert_eq(check_char('\\'), 1);
    cr_assert_eq(check_char('\a'), 1);
    cr_assert_eq(check_char('\b'), 1);
    cr_assert_eq(check_char('\f'), 1);
    cr_assert_eq(check_char('\n'), 1);
    cr_assert_eq(check_char('\r'), 1);
    cr_assert_eq(check_char('\v'), 1);
    cr_assert_eq(check_char(' '), 1);
    cr_assert_eq(check_char('a'), 0);
    cr_assert_eq(check_char('5'), 0);
    cr_assert_eq(check_char('_'), 0);
}

Test(my_clean_str, Test_my_clean_str)
{
    char str1[] = "This is a test.";
    char str2[] = "   \t  This is  a  test. \n \r";
    char str3[] = "   \t  This is  a  test. \n \r ";
    char str4[] = "";
    char *clean_str1 = my_clean_str(str1);
    char *clean_str2 = my_clean_str(str2);
    char *clean_str3 = my_clean_str(str3);
    char *clean_str4 = my_clean_str(str4);

    cr_assert_str_eq(clean_str1, "This is a test.");
    cr_assert_str_eq(clean_str2, "This is a test.");
    cr_assert_str_eq(clean_str3, "This is a test.");
    cr_assert_str_eq(clean_str4, "");
    free(clean_str1);
    free(clean_str2);
    free(clean_str3);
    free(clean_str4);
}

Test(my_strncmp, test_my_strncmp)
{
    cr_assert_eq(my_strncmp("hello", "hello", 5), 0);
    cr_assert_eq(my_strncmp("hello", "helxo", 5), 'l' - 'x');
    cr_assert_eq(my_strncmp("hello", "hell", 4), 0);
    cr_assert_eq(my_strncmp("hello", "hell", 5), 'o');
    cr_assert_eq(my_strncmp("hello", "goodbye", 7), 'h' - 'g');
}

Test(my_strstr, empty_string)
{
    char str[10] = "";
    char* result = my_strstr(str, "test");
    cr_assert_null(result, "Expected NULL but got %p", result);
}

Test(my_strstr, empty_substring)
{
    char str[10] = "test";
    char* result = my_strstr(str, "");
    cr_assert_str_eq(result, str, "Expected '%s' but got '%s'", str, result);
}

Test(my_strstr, no_match)
{
    char str[10] = "test";
    char* result = my_strstr(str, "foo");
    cr_assert_null(result, "Expected NULL but got %p", result);
}

Test(my_strstr, match_at_beginning)
{
    char str[10] = "test";
    char* result = my_strstr(str, "te");
    cr_assert_str_eq(result, str, "Expected '%s' but got '%s'", str, result);
}

Test(my_strstr, match_at_end)
{
    char str[10] = "test";
    char* result = my_strstr(str, "st");
    cr_assert_str_eq(result, str + 2, "Expected '%s' but got '%s'", str + 2, result);
}

Test(my_strstr, match_in_middle)
{
    char str[10] = "test";
    char* result = my_strstr(str, "es");
    cr_assert_str_eq(result, str + 1, "Expected '%s' but got '%s'", str + 1, result);
}

Test(my_strstr, multiple_matches)
{
    char str[10] = "test";
    char* result = my_strstr(str, "t");
    cr_assert_str_eq(result, str, "Expected '%s' but got '%s'", str, result);
    result = my_strstr(result + 1, "t");
    cr_assert_str_eq(result, str + 3, "Expected '%s' but got '%s'", str + 3, result);
}

Test(my_strcmp, same_strings)
{
    char s1[] = "hello";
    char s2[] = "hello";
    int result = my_strcmp(s1, s2);
    cr_assert_eq(result, 0);
}

Test(my_strcmp, s1_smaller)
{
    char s1[] = "cat";
    char s2[] = "dog";
    int result = my_strcmp(s1, s2);
    cr_assert(result < 0);
}

Test(my_strcmp, s1_empty)
{
    char s1[] = "";
    char s2[] = "hello";
    int result = my_strcmp(s1, s2);
    cr_assert(result < 0);
}

Test(my_strcmp, s2_empty)
{
    char s1[] = "hello";
    char s2[] = "";
    int result = my_strcmp(s1, s2);
    cr_assert(result > 0);
}

Test(my_strcat, empty_string)
{
    char dest[100] = "";
    char *result = my_strcat(dest, "");
    cr_assert_str_eq(result, "");
}

Test(my_strcat, non_empty_string)
{
    char dest[100] = "Hello, ";
    char *result = my_strcat(dest, "world!");
    cr_assert_str_eq(result, "Hello, world!");
}

Test(my_strcat, multiple_concatenations)
{
    char dest[100] = "The quick brown fox ";
    char *result = my_strcat(dest, "jumps over ");
    result = my_strcat(dest, "the lazy dog.");
    cr_assert_str_eq(result, "The quick brown fox jumps over the lazy dog.");
}

Test(my_strcat, concatenation_with_empty_dest)
{
    char dest[100] = "";
    char *result = my_strcat(dest, "Some string");
    cr_assert_str_eq(result, "Some string");
}

Test(my_strncpy, basic_test)
{
    char dest[10] = {0};
    char *result = my_strncpy(dest, "Hello, World!", 5);
    cr_assert_str_eq(result, "Hello");
}

Test(my_strncpy, is_negative)
{
    char dest[10] = {0};
    char *result = my_strncpy(dest, "Hello, World!", -5);
    cr_assert_null(result);
}

Test(my_str_to_word_array, basic_test)
{
    char **result = my_str_to_word_array("Hello, World!", ",");
    cr_assert_not_null(result);
    cr_assert_str_eq(result[0], "Hello");
    cr_assert_str_eq(result[1], " World!");
    cr_assert_null(result[2]);
    for (int i = 0; result[i]; i++)
        free(result[i]);
    free(result);
}

Test(my_str_to_word_array, no_delimiter)
{
    char **result = my_str_to_word_array("Hello World!", ",");
    cr_assert_not_null(result);
    cr_assert_str_eq(result[0], "Hello World!");
    cr_assert_null(result[1]);
    free(result[0]);
    free(result);
}

Test(my_env_parsing, normal_input)
{
    char *env[] = {
        "USER=john",
        "HOME=/home/john",
        "PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin",
        "PWD=/home/john/my_folder",
        NULL
    };
    main_struct_t *all = my_env_parsing(env);

    cr_assert_str_eq(all->path, "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin");
    cr_assert_str_eq(all->pwd, "/home/john/my_folder");
    cr_assert_eq(all->localisation_pwd, 3);

    for (int i = 0; env[i] != NULL; i++) {
        cr_assert_str_eq(all->env_copy[i], env[i]);
    }
    cr_assert_null(all->env_copy[4]);
    free(all->path);
    free(all->pwd);
    mickeal_myers(all->env_copy);
    free(all);
}

Test(my_env_parsing, empty_input)
{
    char *env[] = {NULL};
    main_struct_t *all = my_env_parsing(env);

    cr_assert_null(all->path);
    cr_assert_null(all->pwd);
    free(all);
}

Test(condition_signal, test_condition_signal)
{
    main_struct_t all = {0};
    int status = WTERMSIG(SIGSEGV);
    condition_signal(&all, status);
    assert(all.return_value == 139);

    status = WTERMSIG(SIGFPE);
    condition_signal(&all, status);
    assert(all.return_value == 136);
}

Test(condition_coredump, test_condition_coredump)
{
    main_struct_t all = {0};
    int status = WTERMSIG(SIGSEGV);
    condition_coredump(&all, status);
    assert(all.return_value == 139);

    status = WTERMSIG(SIGFPE);
    condition_coredump(&all, status);
    assert(all.return_value == 136);
}

Test(heck_segmentation, test_segmentation)
{
    main_struct_t all = {0};
    int status = 0;
    check_segmentation(&all, status);
    assert(all.return_value == 0);

    status = WTERMSIG(SIGSEGV);
    check_segmentation(&all, status);
    assert(all.return_value == 139);

    status = WTERMSIG(SIGFPE);
    check_segmentation(&all, status);
    assert(all.return_value == 136);

    status = WTERMSIG(SIGFPE);
    check_segmentation(&all, status);
    assert(all.return_value == 136);
}

Test(my_putstr_error, basic) {
    cr_redirect_stderr();
    my_putstr_error("Error message\n");
    cr_assert_stderr_eq_str("Error message\n");
}

Test(my_array_len ,test_my_array_len) {
    char *array1[] = {"a", "b", "c", NULL};
    char *array2[] = {"hello", "world", "!", "how", "are", "you", NULL};
    char *array3[] = {NULL};
    char *array4[] = {"", "", "", "", NULL};

    int len1 = my_array_len(array1);
    int len2 = my_array_len(array2);
    int len3 = my_array_len(array3);
    int len4 = my_array_len(array4);

    if (len1 != 3) {
        printf("Error: expected length 3 for array1, got %d\n", len1);
    }
    if (len2 != 6) {
        printf("Error: expected length 6 for array2, got %d\n", len2);
    }
    if (len3 != 0) {
        printf("Error: expected length 0 for array3, got %d\n", len3);
    }
    if (len4 != 4) {
        printf("Error: expected length 4 for array4, got %d\n", len4);
    }
}

Test(set_old_pwd, test_set_old_pwd) {
    main_struct_t all;
    all.localisation_old_pwd = 2;
    all.pwd = strdup("/home/user");
    all.env_copy = malloc(sizeof(char*) * 3);
    all.env_copy[0] = strdup("VAR1=value1");
    all.env_copy[1] = strdup("VAR2=value2");
    all.env_copy[2] = strdup("OLDPWD=/previous/directory");

    set_old_pwd(&all);

    if (strcmp(all.env_copy[2], "OLDPWD=/home/user") != 0) {
        printf("Error: expected OLDPWD=/home/user, got %s\n", all.env_copy[2]);
    }

    free(all.pwd);
    free(all.env_copy[0]);
    free(all.env_copy[1]);
    free(all.env_copy[2]);
    free(all.env_copy);
}

Test(set_new_pwd ,test_set_new_pwd) {
    main_struct_t all;
    all.localisation_pwd = 1;
    all.env_copy = malloc(sizeof(char*) * 2);
    all.env_copy[0] = strdup("VAR1=value1");
    all.env_copy[1] = strdup("PWD=/previous/directory");

    set_new_pwd(&all, "/home/user");

    if (strcmp(all.env_copy[1], "PWD=/home/user") != 0) {
        printf("Error: expected PWD=/home/user, got %s\n", all.env_copy[1]);
    }

    free(all.env_copy[0]);
    free(all.env_copy[1]);
    free(all.env_copy);
}

Test(setup_pwd, test_setup_pwd) {
    main_struct_t all;
    all.localisation_pwd = 1;
    all.env_copy = malloc(sizeof(char*) * 2);
    all.env_copy[0] = strdup("VAR1=value1");
    all.env_copy[1] = strdup("PWD=/previous/directory");
}

Test(fonction_for_exit, test_fonction_for_exit) {
    void **state;
    main_struct_t *all = malloc(sizeof(main_struct_t));
    all->pwd = malloc(sizeof(char) * 10);
    all->env_copy = malloc(sizeof(char*) * 10);
    all->tab_of_line = malloc(sizeof(char*) * 10);
    all->return_value = 0;
    int len = 10;
    char *pwd = malloc(sizeof(char) * len);
    char *old_pwd = malloc(sizeof(char) * len);
    all->env_copy[0] = malloc(sizeof(char) * len);
    all->tab_of_line[0] = malloc(sizeof(char) * len);
    fonction_for_exit(all);
    cr_assert_null(all->pwd);
    cr_assert_null(all->env_copy);
    cr_assert_null(all->tab_of_line);
    cr_assert_null(pwd);
    cr_assert_null(old_pwd);
}

Test(setup_pwd, test_setup_pwd_bis) {
    main_struct_t all;
    all.pwd = NULL;
    all.env_copy = malloc(sizeof(char*) * 2);
    all.env_copy[0] = strdup("HOME=/home/user");
    all.env_copy[1] = NULL;
    all.localisation_pwd = 0;
    char* pwd = NULL;
    char* old_pwd = NULL;
    size_t len = 0;

    setup_pwd(&all, pwd);
    cr_assert(all.pwd != NULL);

    char* new_pwd = strdup("/home/user/test");
    setup_pwd(&all, new_pwd);

    free(all.env_copy[0]);
    free(all.env_copy);
    free(all.pwd);
    free(new_pwd);
}

Test(check_env_existing, test_check_env_existing) {
    main_struct_t all;
    all.env_copy = malloc(sizeof(char *) * 3);
    all.env_copy[0] = my_strdup("VAR1=value1");
    all.env_copy[1] = my_strdup("VAR2=value2");
    all.env_copy[2] = NULL;
    all.tab_of_line = malloc(sizeof(char *) * 4);
    all.tab_of_line[0] = my_strdup("setenv");
    all.tab_of_line[1] = my_strdup("VAR1");
    all.tab_of_line[2] = my_strdup("new_value");
    all.tab_of_line[3] = NULL;
    int result = check_env_existing(&all);
    cr_assert_eq(result, 0);
    cr_assert_str_eq(all.env_copy[0], "VAR1=new_value");
    free(all.env_copy[0]);
    free(all.env_copy[1]);
    free(all.env_copy);
    free(all.tab_of_line[0]);
    free(all.tab_of_line[1]);
    free(all.tab_of_line[2]);
    free(all.tab_of_line);
}

Test(setenv_end ,test_setenv_end) {
    main_struct_t all;
    all.env_copy = malloc(sizeof(char *) * 3);
    all.env_copy[0] = my_strdup("VAR1=value1");
    all.env_copy[1] = my_strdup("VAR2=value2");
    all.env_copy[2] = NULL;
    all.tab_of_line = malloc(sizeof(char *) * 4);
    all.tab_of_line[0] = my_strdup("setenv");
    all.tab_of_line[1] = my_strdup("VAR3");
    all.tab_of_line[2] = my_strdup("");
}

Test(fonction_for_env, empty_env_copy)
{
    main_struct_t all;
    all.env_copy = malloc(sizeof(char *));
    all.env_copy[0] = NULL;
    cr_redirect_stdout();
    int result = fonction_for_env(&all);
    cr_assert_eq(result, 0);
    cr_assert_stdout_eq_str("$> ");
    free(all.env_copy);
}

Test(fonction_for_env, one_variable_in_env_copy)
{
    main_struct_t all;
    all.env_copy = malloc(sizeof(char *) * 2);
    all.env_copy[0] = strdup("PATH=/usr/local/bin");
    all.env_copy[1] = NULL;
    cr_redirect_stdout();
    int result = fonction_for_env(&all);
    cr_assert_eq(result, 0);
    cr_assert_stdout_eq_str("PATH=/usr/local/bin\n$> ");
    free(all.env_copy[0]);
    free(all.env_copy);
}

Test(fonction_for_env, multiple_variables_in_env_copy)
{
    main_struct_t all;
    all.env_copy = malloc(sizeof(char *) * 4);
    all.env_copy[0] = strdup("USER=john");
    all.env_copy[1] = strdup("HOME=/home/john");
    all.env_copy[2] = strdup("PATH=/usr/local/bin");
    all.env_copy[3] = NULL;
    cr_redirect_stdout();
    int result = fonction_for_env(&all);
    cr_assert_eq(result, 0);
    cr_assert_stdout_eq_str("USER=john\nHOME=/home/john\nPATH=/usr/local/bin\n$> ");
    free(all.env_copy[0]);
    free(all.env_copy[1]);
    free(all.env_copy[2]);
    free(all.env_copy);
}