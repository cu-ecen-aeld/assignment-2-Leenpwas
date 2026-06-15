#include "unity.h"
#include <stdbool.h>
#include <stdlib.h>

#include "../../examples/autotest-validate/autotest-validate.h"
#include "../../assignment-autotest/test/assignment1/username-from-conf-file.h"

/**
 * Validate that the username returned by my_username()
 * matches the username stored in conf/username.txt.
 */
void test_validate_my_username(void)
{
    char *conf_username = malloc_username_from_conf_file();

    TEST_ASSERT_NOT_NULL_MESSAGE(
        conf_username,
        "Failed to read username from conf/username.txt"
    );

    TEST_ASSERT_EQUAL_STRING_MESSAGE(
        my_username(),
        conf_username,
        "Username mismatch between my_username() and conf/username.txt"
    );

    free(conf_username);
}
