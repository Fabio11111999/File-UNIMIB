# GTF-VALIDATOR
Python script for the validation of GTF file
GTF is a file-format fot genomic sequences. More info [here](https://mblab.wustl.edu/GTF22.html#intro)
Types of errors detected:
 - For each row:
   - [x] Wrong number of fields
   - [x] Feature isn't one of: ```['CDS', 'start_codon', 'stop_codon', '5UTR', '3UTR', 'inter', 'inter_CNS', 'intron_CNS', 'exon']```
   - [x] Strand is different from ```-``` and ```+```
   - [x] Frame is not correct. Frame is correct when  it's equal to one of: ```[0, 1, 2]``` when the feature is equal to one of ``` ['CDS', 'start_codon', 'stop_codon']```, otherwise frame must be equal to ```'.'```
   - [x] The attributes aren't formatted correctly, or gene_id/transcript_id are missing.
   - [x] ```gene_id``` or ```transcript_id``` are different from ```''``` with feature equal to ```inter``` or ```inter_CNS```.
 - For all the rows grouped by gene_id:
   - [x] Different strands.    
- For each group of entries with the same ```gene_id``` and the same ```transcript_id```:
  - [X] ```start_codon``` or``` stop_codon``` appears but CDS doesn't or viceversa
  - [X] lenght of ```start_codon``` isn't 3
  - [X] lenght of ```stop_codon``` isn't 3
  - [X] Overlapping ranges for ```start_codon```/```stop_codon```/```CDS```

 
Comments in `validator.py` contain more info about each error. `validator.py` works for python 2 and all the next releases.
The script takes a path to a GTF file as input and creates ```validation.txt``` , a text file with the result of the validation process, in the directory of the script. 
