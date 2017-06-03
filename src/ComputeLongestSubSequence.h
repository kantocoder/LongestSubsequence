#include <functional>

template <typename T>
struct ComparatorTraits {
    typedef std::function <bool (T, T)> comp_func_ptr_t;
};


template<typename container_t, typename comparator_fun_ptr_t>  
void  compute_longest_increasing_subseq (
        const container_t &   v_input,               /* input array of integers */
        comparator_fun_ptr_t  comparator_function,   /* comparator function, input */
        size_t & max_subseq_start,                   /* output */
        size_t & max_subseq_len                      /* output */
      )
{
    max_subseq_start = max_subseq_len = 0;
    size_t seq_start=0;
    
    if (v_input.size() == 1) 
        max_subseq_len=1;

    if (v_input.size()<2) 
        return;

    for (size_t i = 1; i<v_input.size(); ++i)
    {
        if  ( comparator_function (v_input[i-1], v_input[i]) )
        {
        /*
          subsequence ended base on the condition in the comparator function.  
          compute its length; if it is longer than the length of the 
          previous increasing subsequence, then update: 
          a) start position of the subsequence, and
          b) its length
        */
            size_t subseq_len = i - seq_start;

            if (subseq_len>max_subseq_len)
            {
                max_subseq_start = seq_start;
                max_subseq_len = subseq_len;
            }
        
        //    reset seq_start to the beginning of the new subsequence
            seq_start = i;
        }
    }

    //  the last several elements might have been increasing subsequence,
    //  so check for its maximality
    size_t subseq_len = v_input.size() - seq_start;

    if (subseq_len>max_subseq_len)
    {
        max_subseq_start = seq_start;
        max_subseq_len = subseq_len;
    }

}   //  compute_longest_increasing_subseq(...)

