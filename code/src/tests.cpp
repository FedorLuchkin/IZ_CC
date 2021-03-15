#include "gtest/gtest.h"

extern "C"{
    #include "megafile.h"
    #include "myfilter.h"
    #include "myinput.h"
}

TEST(filter, 1){
    char** mass, ** mass_filter, str[4];
    int test_bad, test_good;
    str[0] = '0';
    str[1] = '1';
    str[2] = '1';
    str[3] = '\0';
    mass_filter = (char**)calloc(1, sizeof(char*));
	mass = (char**)calloc(1, sizeof(char*));
    mass[0] = (char*)calloc(255, sizeof(char));

    strncpy(mass[0], str, 3);
    test_bad = filter(mass, 1, mass_filter);
    ASSERT_EQ(test_bad, 0);

    str[2] = '3';
    strncpy(mass[0], str, 3);
    test_good = filter(mass, 1, mass_filter);
    ASSERT_EQ(test_good, 1);

    free(mass[0]);
	free(mass);
    free(mass_filter[0]);
	free(mass_filter);    
}

TEST(change_size, 1){
    char** mass, ** mass_change, str[4];
    int before = 1, after = 2, size_before = 0, size_after = 0;
    str[0] = '0';
    str[1] = '1';
    str[2] = '1';
    str[3] = '\0';
    mass_change = (char**)malloc(1 * sizeof(char*));
	mass = (char**)malloc(1 * sizeof(char*));
    mass[0] = (char*)malloc(255 * sizeof(char));
    mass_change[0] = (char*)malloc(255 * sizeof(char));
    strncpy(mass[0], str, 3);
    strncpy(mass_change[0], str, 3);
    
    mass_change = change_size(mass_change, after, before);
	for (int i = 0; i < before; i++){
		size_before += sizeof(mass[i]);
	}
	for (int i = 0; i < after; i++){
		size_after += sizeof(mass_change[i]);
	}    
    ASSERT_EQ(size_after, 2 * size_before);

    free(mass[0]);
	free(mass);
    free(mass_change[0]);
    free(mass_change[1]);
	free(mass_change);   
}

// TEST(my_input, 1){
//     int  n = 0, k = 0;
// 	char** mass;
// 	mass = (char**)malloc(1 * sizeof(char*));
// 	mass = my_input(mass, &k, &n);
//     ASSERT_GE(n, k);

//     for (int i = 0; i < n; i++)
// 	{
// 		free(mass[i]);
// 	}
// 	free(mass);
// }

TEST(clearing,1){
    char** mass, ** mass_clear;
    int success = 0;
    
	mass = (char**)calloc(1, sizeof(char*));
    mass[0] = (char*)calloc(2, sizeof(char));
    mass[0][0] = '1';
    mass[0][1] = '\0';

    mass_clear = (char**)calloc(1, sizeof(char*));
    mass_clear[0] = (char*)calloc(2, sizeof(char));    
    mass_clear[0][0] = '1';    
    mass_clear[0][1] = '\0';

    success = clearing(mass, 2, 1, mass_clear, 1);        
    ASSERT_EQ(success, 1);
}

int main(int argc, char** argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
