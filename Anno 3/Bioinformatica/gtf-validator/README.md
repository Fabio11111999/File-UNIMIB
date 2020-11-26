# GTF-VALIDATOR
Python script for the validation of GTF file
GTF is a file-format fot genomic sequences. More info [here](https://mblab.wustl.edu/GTF22.html#intro)
Types of errors detected:
 - [x] Diffrent types of strand.
 - [x] Diffrent sources.
 - For each row:
   - [x] Wrong number of values.
   - [x] Wrong feature.
   - [x] Wrong start/end.
   - [x] Wrong frame.
   - [x] Wrong Attributes.

Comments in `validator.py` contain more info about each error. `validator.py` works for python 2 and all the next releases.
The script takes a path to a GTF file as input and creates ```validation.txt``` , a text file with the result of the validation process, in the directory of the script. 
