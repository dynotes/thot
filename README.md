Thot: a Toolkit for Statistical Machine Translation
===================================================
*Thot* is an open source toolkit for statistical machine
translation. Originally, Thot incorporated tools to train phrase-based
models. The new version of Thot now includes a state-of-the-art
phrase-based translation decoder as well as tools to estimate all of the
models involved in the translation process. In addition to this, Thot is
also able to incrementally update its models in real time after
presenting an individual sentence pair.

Thot is being developed by [Daniel Ortiz-Martínez] [1]. Daniel is a
member of the [PRHLT research group] [2] at the [Polytechnic University
of Valencia] [3].


Functionality
-------------
The toolkit includes the following functionality:

- Phrase-based statistical machine translation decoder
- Computer-aided translation (post-edition and interactive machine translation)
- Incremental estimation of all of the models involved in the translation process
- Robust generation of alignments at phrase-level
- Client-server implementation of the translation functionality
- Single word alignment model estimation using the incremental EM algorithm
- Scalable implementation of the different estimation algorithms using Map-Reduce
- Integration with the [CasMaCat Workbench] [4] developed in the [CasMaCat project] [5]
- ...


Distribution Details
--------------------
Thot is known to compile on Linux and Windows (using cygwin) systems.
As future work we plan to port the code to other platforms. See the
"Support" section of this file if you experience problems during
compilation.

It is released under the [GNU Lesser General Public License (LGPL)] [6].


Installation
------------
To install Thot, first you need to install the autotools (autoconf,
autoconf-archive, and automake packages in Ubuntu). 

Once the autotools are available, you can proceed with the installation
of Thot by following the next sequence of steps:

 1. Obtain the package using git:

        $ git clone https://github.com/daormar/thot.git

    Or [download it in a zip file] [7]

 2. `cd` to the directory containing the package's source code and type
    `./reconf`

 3. Type `./configure` to configure the package

 4. Type `make` to compile the package

 5. Type `make install` to install the programs and any data files and
    documentation

 6. You can remove the program binaries and object files from the source
    code directory by typing `make clean`

By default the files are installed under the /usr/local/ directory (or
similar, depending of the OS you use); however, since Step 5 requires
root privileges, another directory can be specified during Step 3 by
typing:

     $ configure --prefix=<absolute-installation-path>

For example, if "user1" wants to install the Thot package in the
directory /home/user1/thot, the sequence of commands to execute should be
the following:

     $ ./reconf
     $ configure --prefix=/home/user1/thot
     $ make
     $ make install

NOTE: the installation directory can be the same directory where the
Thot package was decompressed.

In order to build and use Thot on Windows platforms, the linux-like
environment called Cygwin must be downloaded and installed previously.

See "INSTALL" file for more information.


Installation Including the CasMaCat Workbench
---------------------------------------------
Thot can be combined with the CasMacat Workbench that is being developed
in the CasMaCat project. [See this webpage] [4] to get the specific
installation instructions.


Current Status
--------------
The Thot toolkit is under development. Original public versions of Thot
date back to 2005 and did only include estimation of phrase-based
models. By contrast, current version offers several new features that
had not been previously incorporated.

Current work is mainly focused on adding the minimal documentation that
is required to access the whole functionality implemented by the
tool. After completing this task, a list of new extension directions
will be published here.


Support
-------
Project documentation is being developed. Such documentation include:

- This README file
- The Thot manual ("thot_manual.pdf" under the "doc" directory)

If you need additional help, you can:

- use the [github issue tracker] [8]
- [send me an e-mail] [9]
- join the [CasMaCat support group] [10]

Additional information about the theoretical foundations of Thot can be
found in [Ortiz-Martínez, 2011]. One interesting feature of Thot,
incremental (or online) estimation of statistical models, is also
described in [Ortiz-Martínez et al., 2010].


Citation
--------
You are welcome to use the code under the terms of the license for
research or commercial purposes, however please acknowledge its use with
a citation:

Daniel Ortiz-Martínez, Ismael García-Varea, Francisco Casacuberta. 
*"Thot: a toolkit to train phrase-based models for statistical machine translation"*.
Proc. of the Tenth Machine Translation Summit,
Phuket, Thailand, September 2005.

Here is a BiBTeX entry:

<pre>
@InCollection{Ortiz2005,
  author =  {D.~Ortiz-Mart\'{\i}nez  and  I.~Garc\'{\i}a-Varea and F.~Casacuberta},
  title =  {Thot: a Toolkit To Train Phrase-based Statistical Translation Models},
  booktitle = {Tenth Machine Translation Summit},
  publisher = {AAMT},
  year = {2005},
  address = {Phuket, Thailand},
  month = {September},
}
</pre>


Literature
----------
Daniel Ortiz-Martínez,
*Advances in Fully-Automatic and Interactive Phrase-Based Statistical Machine Translation*. 
PhD Thesis. Universidad Politécnica de Valencia. 2011. 
Advisors: Ismael García Varea and Francisco Casacuberta. [Download] [11].

Daniel Ortiz-Martínez, Ismael García-Varea, Francisco Casacuberta. 
*Online Learning for Interactive Statistical Machine Translation*. 
Proceedings of the North American Chapter of the Association for Computational Linguistics - 
Human Language Technologies (NAACL HLT), 2010. pp. 546-554. [Download] [12].


Acknowledgements
----------------
Thot is currently supported by the European Union under the [CasMaCat
research project] [5]. Thot has also received support from the Spanish
Government in a number of research projects, such as the [MIPRCV
project] [13] that belongs to the [CONSOLIDER programme] [14].


Last updated: 26 November 2013,
[daormar2@gmail.com] [8]

[1]: https://prhlt.iti.upv.es/page/member?user=dortiz
[2]: https://prhlt.iti.upv.es/
[3]: http://www.upv.es/
[4]: http://www.casmacat.eu/index.php?n=Workbench.Workbench
[5]: http://www.casmacat.eu/
[6]: http://www.gnu.org/copyleft/lgpl.html
[7]: https://github.com/daormar/thot/archive/master.zip
[8]: https://github.com/daormar/thot/issues
[9]: mailto:daormar2@gmail.com
[10]: http://groups.google.com/group/casmacat-support/boxsubscribe
[11]: https://prhlt.iti.upv.es/aigaion2/attachments/dortiz_thesis_2011.pdf-d12d165f9a2b01b0697000ed7c08c4bc.pdf
[12]: http://aclweb.org/anthology-new/N/N10/N10-1079.pdf
[13]: http://miprcv.iti.upv.es/
[14]: http://www.ingenio2010.es/
