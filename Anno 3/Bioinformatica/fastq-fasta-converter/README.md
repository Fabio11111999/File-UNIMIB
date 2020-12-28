
# FASTQ-FASTA-converter
Python script for the convertion of a FASTQ file into a FASTA file.
FASTAQ and FASTA are text-based formats for representing  nucleotide sequences. More info about [FASTA](https://en.wikipedia.org/wiki/FASTA_format) and [FASTQ](https://en.wikipedia.org/wiki/FASTQ_format#:~:text=FASTQ%20format%20is%20a%20text,single%20ASCII%20character%20for%20brevity.).

### How it works:
 ```converter.py``` is a script that takes a path to a FASTQ file as input and creates ```converted.fa``` , a FASTA file with the result of the conversion process. The script takes other 5 values in input and uses them to select the reads that need to be converted. 

### Requirements 
For being able to run the script Python need to be present on the computer. It's also needed a file with extension ```.fq``` that needs to be in the directory of the script.

### Documentation:
**Input:**
- The name of the ```.fq``` file.
- ```L1, L2, Q1, Q2, P``` and will convert only the reads that satisfy the following conditions:
   - The read is longer than ```L1```.
   - The read isn't longer than ```L2```.
   - The minimun quality of a base of the read must be greater or equal to ```Q1```.
   - The longest subregion with quality greater or equal than Q2 is at lest p% of the total length.
   
   
**Output:**
- ```converted.fa``` a FASTA file which contains the conversion of the reads that satisfy the conditions written before, with some information about each record:
   - Length.
   - Minimum quality. 
   - Average quality.
   - Start and end indexes of the longest subregion with quality \ge ```Q2```.
