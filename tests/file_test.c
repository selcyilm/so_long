#include "../include/so_long.h"
#include <criterion/criterion.h>

Test(file, check_map_name_valid) {
	cr_expect_eq(true, check_map_name("hello.bar"), "1");
	cr_expect_eq(true, check_map_name("valid_map_name.bar"), "2");
	cr_expect_eq(true, check_map_name("test.bar"), "3");
	cr_expect_eq(true, check_map_name("thisisverylongtextsoletstest.bar"), "4");
}

Test(file, check_map_name_valid) {
	cr_expect_eq(false, check_map_name("test..bar"), "1");
	cr_expect_eq(false, check_map_name("test.barr"), "2");
	cr_expect_eq(false, check_map_name("test.ber"), "3");
	cr_expect_eq(false, check_map_name("te.st.bar"), "4");
	cr_expect_eq(false, check_map_name("testb.ar"), "5");
	cr_expect_eq(false, check_map_name("hellobar."), "6");
}



