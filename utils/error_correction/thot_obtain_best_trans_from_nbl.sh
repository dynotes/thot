# Author: Daniel Ortiz Mart\'inez
# *- bash -*

# Obtains the best translation given an n-best list file generated by
# means of the process_wg tool and a set of weights.

get_trans()
{
    ${AWK} '{
              spsymfound=0
              for(i=1;i<=NF;++i)
              {
                if($i=="|||") ++spsymfound
                if(spsymfound==2) break;
              }
              ++i
              for(;i<=NF;++i)
              {
                printf"%s",$i
                if(i!=NF) printf" "
              }
              printf"\n"
            }'
}

if [ $# -lt 2 ]; then
    echo "Usage: thot_obtain_best_trans_from_nbl <nblfile> \"<weight1> <weight2> ... <weightn>\""
else
    file=$1
    weights=$2
    cat $file | $bindir/thot_rescore_nbest "$weights" | ${SORT} -k1gr | head -1 | get_trans
fi
