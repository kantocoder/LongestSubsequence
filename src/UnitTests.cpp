#include <vector>
#include "ComputeLongestSubSequence.h"

#include <gtest/gtest.h>
#include <iostream>

TEST(Case1, test1_integer_array)
{
    size_t      max_subseq_start;
    size_t      max_subseq_len;


    std::vector<int>  input{4,1,3,2,6,7};//{1,3,4,2,9,7,3,5,6,7,8,1};

 
    ComparatorTraits<int>::comp_func_ptr_t
        comparator_func = [](int x, int y) -> bool {return x>=y;};

    
    compute_longest_increasing_subseq (input, comparator_func, max_subseq_start, max_subseq_len);  

    ASSERT_EQ(3, max_subseq_start) << "Subsequence must start from position 3";
    ASSERT_EQ(3, max_subseq_len) << "Subsequence have length of 3";
    
    for (int i = max_subseq_start; i<max_subseq_start+max_subseq_len;++i)
        printf ("%1d", input[i]);
    printf ("\n");

}

TEST(Case1, test2_binary_array)
{
    size_t      max_subseq_start;
    size_t      max_subseq_len;

    std::vector<int>  input{0,1,1,0,1,1,1,0,0,0,0};
    

    ComparatorTraits<int>::comp_func_ptr_t
        comparator_func = [](int x, int y) -> bool {return x!=y;};
    

    compute_longest_increasing_subseq (input, comparator_func, max_subseq_start, max_subseq_len);  

    ASSERT_EQ(7, max_subseq_start) << "Subsequence must start from position 7";
    ASSERT_EQ(4, max_subseq_len) << "Subsequence have length of 4";
    
    for (int i = max_subseq_start; i<max_subseq_start+max_subseq_len;++i)
        printf ("%1d",input[i]);
    printf ("\n");
}


TEST(Case1, test3_string)
{
    size_t      max_subseq_start;
    size_t      max_subseq_len;

    std::string     input("AsBsCCXBcCCCCx");
    

    ComparatorTraits<char>::comp_func_ptr_t   
        comparator_func = [](char x, char y) -> bool {return x!=y;};

    
    compute_longest_increasing_subseq (input, comparator_func, max_subseq_start, max_subseq_len);  
    
    std::string result = input.substr(max_subseq_start, max_subseq_len);

    ASSERT_STREQ ("CCCC", result.c_str())<<" longest subsequence must be equal to CCCC";
    std::cout <<result<<"\n";
}




int main(int argc, char * argv[])
{
    testing::InitGoogleTest(&argc, argv);
    
    return RUN_ALL_TESTS();
}

