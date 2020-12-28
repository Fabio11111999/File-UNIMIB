# @Author: Fabio Marchesi mtr: 844941
# FASTQ - FASTA converter

from Bio import SeqIO
import sys, re

# Main Function:
print('Starting FASTQ-FASTA converter')
try:
	# Reading input
	print('Path to the file FASTQ:')
	FASTQ_file_name = input()
	print('Type the minimum read length L1')
	L1 = int(input())
	print('Type the maximum read length L2')
	L2 = int(input())
	if L1 >= L2:
		print('Execution failed, L1 must be < L2')
		sys.exit(0)
	print('Type the minimum base quality Q1')
	Q1 = int(input())
	print('Type Q2 and P, only the reads that contains at least one substring which its length is >= P\% of the total read and its minimum quality is >= Q2 will be keeped')
	Q2 = int(input())
	if Q1 >= Q2:
		print('Execution failed, Q1 must be < Q2')
		sys.exit(0)
	P = int(input())
	if 0 > P or 100 < P:
		print('Execution failed, P must be >= and <= 100')
except:
	print('Execution failed, impossibile to read the input')
