
#include <stdio.h>

void test_write_read_config();
void test_validate_config();
void test_create_free_entries();
void cleanup_test_files();

int main() {
    test_write_read_config();
    test_validate_config();
    test_create_free_entries();

    printf("$ All tests passed.\n");
    cleanup_test_files();

    return 0;
}
