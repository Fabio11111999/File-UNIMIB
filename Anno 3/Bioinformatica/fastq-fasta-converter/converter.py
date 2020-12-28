# @Author: Fabio Marchesi mtr: 844941
# FASTQ - FASTA converter

from Bio import SeqIO
import sys, re, math
# Function longest_subregion(read, Q2)
# Function that returns (i, j), where i and j are the limits of the longest subregion 
# 	with minimum quality greater or equal than Q2
def longest_subregion(read, Q2):
	sequence = str(read.seq)
	i, best_start, best_end = 0, -1, -2 
	while i < len(sequence):
		if read.letter_annotations['phred_quality'][i] < Q2:
			i = i + 1
			continue
		j = i
		while j < len(sequence) and read.letter_annotations['phred_quality'][j] >= Q2:
			j = j + 1
		if j - i > best_end - best_start:
			best_start, best_end = i, j
		i = j
	return (best_start, best_end)


# Function check_read(read, L1, L2, Q1, Q2, P)
# Boolean function that checks whether the following conditions are satisfied:
# 	read is longer than L1
#	read isn't longer than L2
# 	read's minimum quality is greater or equal than Q1
# 	The longest subregion with quality greater or equal than Q2 is at lest p% of the total length .
def check_read(read, L1, L2, Q1, Q2, P):
	sequence = str(read.seq)
	if len(sequence) < L1 or len(sequence) >L2:
		return False
	if min(read.letter_annotations['phred_quality']) < Q1:
		return False
	subregion = longest_subregion(read, Q2)
	best_start, best_end = subregion[0], subregion[1]
	min_length = math.ceil(float(len(sequence)) / 100 * P)
	if min_length > best_end - best_start:
		return False
	return True


# Main Function:
print('Starting FASTQ-FASTA converter')
try:
	# Reading input
	print('Path to the file FASTQ:')
	FASTQ_file_name = input()
	fastq_records = SeqIO.parse(FASTQ_file_name, 'fastq')
	print('Type the minimum read length L1')
	L1 = int(input())
	print('Type the maximum read length L2')
	L2 = int(input())
	if L1 >= L2:
		print('Execution failed, L1 must be < L2')
		sys.exit(0)
	print('Type the minimum base quality Q1')
	Q1 = int(input())
	print('Type Q2 and P, only the reads that contain at least one substring which its length is >= P\% of the total read and its minimum quality is >= Q2 will be keeped')
	Q2 = int(input())
	if Q1 >= Q2:
		print('Execution failed, Q1 must be < Q2')
		sys.exit(0)
	P = float(input())
	if 0 > P or 100 < P:
		print('Execution failed, P must be >= 0 and <= 100')
except Exception as e:
	print(e)
	print('Execution failed, impossibile to read the input')
	sys.exit(0)

# Processing reads

output = []
fastq_record_list = list(fastq_records)
for read in fastq_record_list:
	correct = check_read(read, L1, L2, Q1, Q2, P)
	if correct:
		read.description = 'Length: ' + str(len(read.seq)) + ', '
		read.description += 'Minimum quality: ' + str(min(read.letter_annotations['phred_quality'])) + ", "
		subregion = longest_subregion(read, Q2)
		best_start, best_end = subregion[0], subregion[1]
		read.description += 'Subregion\'s start: ' + str(best_start) + ', '
		read.description += 'Subregion\'s end: ' + str(best_end - 1) + ', '
		sequence_subregion = read.letter_annotations['phred_quality'][best_start : best_end]
		avg = sum(sequence_subregion) / len(sequence_subregion)
		read.description += 'Average quality: ' + str(avg)
		output.append(read)
SeqIO.write(output, 'converted.fa', 'fasta')
print('Execution completed successfully')
