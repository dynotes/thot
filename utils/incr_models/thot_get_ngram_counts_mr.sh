# Author: Daniel Ortiz Mart\'inez
# *- bash -*

# Given a monolingual corpus, extracts n-gram counts using the
# map-reduce technique. This allows to estimate model from corpora of an
# arbitrary size.  The -unk option reserves a certain probability mass
# for the unknown word.

sort_counts()
{
    # Set sort command options
    export LC_ALL=""
    export LC_COLLATE=C
    if test ${sortT} = "yes"; then
        SORT_TMP="-T $TMP"
    else
        SORT_TMP=""
    fi

    ${AWK} '{printf"%d %s\n",NF,$0}' |\
        ${SORT} ${SORT_TMP} -t " " ${sortpars} | ${AWK} '{for(i=2;i<=NF-1;++i)printf"%s ",$i; printf"%d\n",$NF}'
}

print_desc()
{
    echo "get_ngram_counts_mr written by Daniel Ortiz"
    echo "get_ngram_counts_mr extracts n-grams counts from a monolingual corpus"
    echo "type \"get_ngram_counts_mr --help\" to get usage information"
}

version()
{
    echo "get_ngram_counts_mr is part of the thot package"
    echo "thot version "${version}
    echo "thot is GNU software written by Daniel Ortiz"
}

usage()
{
    echo "get_ngram_counts_mr -c <string> -n <int> [-unk]"
    echo "                    [-tdir <string>]"
    echo "                    [-debug] [--help] [--version]"
    echo ""
    echo "-c <string>        : Corpus file."
    echo "-n <int>           : Order of the n-grams."
    echo "-unk               : Reserve probability mass for the unknown word."
    echo "-tdir <string>     : Directory for temporary files."
    echo "-debug             : After ending, do not delete temporary files"
    echo "                     (for debugging purposes)."
    echo "--help             : Display this help and exit."
    echo "--version          : Output version information and exit."
}

set_tmp_dir()
{
    if [ -d ${tdir} ]; then
        # Create directory for temporary files
        TMP=$tdir/ngcounts.$$
        if [ ${debug} -eq 0 ]; then
            trap "rm -rf $TMP* 2>/dev/null" EXIT
        fi
        mkdir $TMP
    else
        echo "Error: temporary directory does not exist"
        return 1;
    fi
}

unk_given=0
c_given=0
n_given=0
tdir="/tmp"
debug=0
chunk_size=50000

if [ $# -eq 0 ]; then
    print_desc
    exit 1
fi

while [ $# -ne 0 ]; do
    case $1 in
        "--help") usage
            exit 0
            ;;
        "--version") version
            exit 0
            ;;
        "-c") shift
            if [ $# -ne 0 ]; then
                corpus=$1
                c_given=1
            else
                c_given=0
            fi
            ;;
        "-n") shift
            if [ $# -ne 0 ]; then
                n_val=$1
                n_given=1
            else
                n_given=0
            fi
            ;;
        "-tdir") shift
            if [ $# -ne 0 ]; then
                tdir=$1
            else
                tdir="./"
            fi
            ;;
        "-unk") unk_given=1
            ;;
        "-debug") debug=1
            ;;
    esac
    shift
done

# verify parameters

if [ ${c_given} -eq 0 ]; then
    echo "Error: corpus file not given"
    exit 1
else
    if [ ! -f  "${corpus}" ]; then
        echo "Error: file ${corpus} with training sentences does not exist"
        exit 1
    fi
fi

if [ ${n_given} -eq 0 ]; then
    echo "Error: order of the n-grams not provided"
    exit 1
fi

# parameters are ok

# Set TMP directory
set_tmp_dir || exit 1
    
# Split corpus into chunks of fixed size
${SPLIT} -l ${chunk_size} $corpus $TMP/

# Process chunks
c=1
for i in `ls $TMP`; do
    
    ${bindir}/thot_get_ngram_counts -c $TMP/$i -n ${n_val} | ${AWK} -v c=$c '{printf"%s %d\n",$0,c}' >> $TMP/counts
    
    c=`expr $c + 1`
    
    rm $TMP/$i

done

# Add unk symbol if requested
if [ ${unk_given} -eq 1 ]; then
    UNK_SYMBOL_STR="<unk>"
    echo ${UNK_SYMBOL_STR}" 1 1 <unk_chunk>" >> $TMP/counts
fi

# Merge counts
cat $TMP/counts | sort_counts | ${bindir}/thot_merge_ngram_counts 