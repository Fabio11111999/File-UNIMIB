# @Author: Fabio Marchesi 
# GTF-validator 
# GTF syntax: <seqname> <source> <feature> <start> <end> <score> <strand> <frame> [attributes] [comments]

import re, sys

# Validation part:
# Files and functions for the output of validation's results
validation = open("validation.txt", "w+")
def print_error(row, message):
	validation.write('Validation failed.\n')
	if row != ' ':
		validation.write('Row ' + str(row) + ' : ' + message + '\n')
	else:
		validation.write(message + '\n')

# Function check_strands(rows)
# Boolean function that checks whether all the strands of a file are equal
def check_strands(rows):
	correct = True
	for i in range(len(rows)):
		if rows[i].split('\t')[6] != rows[0].split('\t')[6]:
			correct = False
			print_error(i, 'Strand does not match strand at row 0')
	return correct 


# Function check_start_end(start, end, i)
# Boolean function that checks whether all these conditions are respected:
# start is an intger
# end is an integer
# end >= start
# start >= 1
def check_start_end(start, end, i):
	correct = True;
	try:
		int(start)
	except:
		print_error(i, 'Start value is not an integer')
		correct = False;
	try:
		int(end)
	except:
		print_error(i, 'End value is not an integer')
		correct = False;
	if correct == True and int(end) < int(start):
		print_error(i, 'Start value is greater than end value')
		correct = False
	if correct == True and int(start) < 1:
		print_error(i, 'Start value is not greater than 0')
		correct = False
	return correct


# Function check_feature(feature, i)
# Boolean function that checks whether the feature's value is correct
# Feature must be equal to one of:
# ['CDS', 'start_codon', 'stop_codon', '5UTR', '3UTR', 'inter', 'inter_CNS', 'intron_CNS', 'exon']
def check_feature(feature, i):
	if feature not in ['CDS', 'start_codon', 'stop_codon', '5UTR', '3UTR', 'inter', 'inter_CNS', 'intron_CNS', 'exon']:
		print_error(i, 'Feature value is not valid')
		return False
	return True


# Function check_strand(strand, i):
# Boolean function that checks whether the strand's value is correct on a single line
# Strand's value must be equal to '-' or '+'
def check_strand(strand, i):
	if strand not in ['-', '+']:
		print_error(i, 'Strand value is not correct')
		return False
	return True


# Function check_frame(feature, frame, i):
# Boolean function that checks whether the frame's value is correct
# If the feature is equal to one of: ['CDS', 'start_codon', 'stop_codon']
#	The frame must be equal to one of: ['0', '1', '2']
# Otherwise the frame must be equal to '.'
def check_frame(feature, frame, i):
	if feature in ['CDS', 'start_codon', 'stop_codon']:
		if frame not in ['0', '1', '2']:
			print_error(i, 'Frame value is not correct')
			return False
	else:
		if frame != ".":
			print_error(i, 'Frame value is not correct')
			return False
	return True
	

# Function list_attributes(s)
# Given a string return a list of pairs
# Every element is a pair(attribute, value)
def list_attributes(s):
	attributes = []
	while len(s) > 0:
		re_att = re.search('[^"]+', s) # Prefix before "
		if re_att == None:
			return []
		attribute = s[re_att.span()[0] : (re_att.span()[1] - 1)]
		s = s[len(attribute) + 2 : ] # Removing the space and "
		if len(s) > 0 and s[0] == '"': # Checking if value is empty
			s = s[1 : ]
			value = ""
		else:
			re_value = re.search('[^"]+', s) # Taking the value
			if re_value == None:
				return False
			value = s[ : re_value.span()[1]] 
			s = s[len(value) + 1 : ]
		attributes.append((attribute, value))
		if len(s) == 0 or s[0] != ';': # Wrong syntax
			return []
		if len(s) == 1:
			return attributes
		if s[1] != ' ' and s[1] != '\n':
			return []
		s = s[2 : ] # Remove '; '
	return attributes		


# Function check_attributes(feature, att, i)
# Boolean function that checks whether the attributes are correct
# gene_id and transcript_id must be present
# gene_id and transcript_id must be empty for gene = inter or gene = inter_CNS
def check_attributes(feature, att, i):
	elements = list_attributes(att)
	if elements[0][0] != 'gene_id':
		print_error(i, 'The first attribute (' + str(elements[0][0]) + ') must be "gene_id"')
		return False
	if elements[1][0] != 'transcript_id':
		print_error(i, 'The second attribute (' + str(elements[1][0]) + ') must be "Transcript_it"')
		return False
	if(feature in ['inter', 'inter_CNS'] and (elements[0][1] != '' or elements[1][1] != '')):
		print_error(i, 'gene_id and transcript_id must be equal to '' for features: inter and inter_CNS')
		return False
	return True


# Function check_row(row, i)
# Boolean function that checks whether the row is correct
# All the elements of a gtf's file row are checked 
def check_row(row, i):
	elements = row.split('\t')
	correct_row = True
	# Checking the number of values 
	correct_number_of_values = len(elements) >= 9
	if correct_number_of_values == False:
		print_error(i, "Not enough arguments")
		return False
	# Checking the feature
	correct_feature = check_feature(elements[2], i) 
	correct_row = correct_row and correct_feature
	# Checking start and end
	correct_start_end = check_start_end(elements[3], elements[4], i)
	correct_row = correct_row and correct_start_end
	# Checking the strand 
	correct_strand = check_strand(elements[6], i)
	correct_row = correct_row and correct_strand
	# Checking the frame
	correct_frame = check_frame(elements[2], elements[7], i)
	correct_row = correct_row and correct_frame
	# Checking the attributes
	correct_attributes = check_attributes(elements[2], elements[8], i)
	correct_row = correct_row and correct_attributes
	return correct_row


# Function check_gene_strand(gtf_file_rows)
# Boolean function which checks if all the strands in the same gene are equal 
def check_gene_strand(gtf_file_rows):
	gene_dict = {}
	for i in range(len(gtf_file_rows)):
		row = gtf_file_rows[i]
		if check_row(gtf_file_rows[i], i) == True:
			elements = row.split('\t')
			current_strand = elements[6]
			current_attributes = list_attributes(elements[8])
			current_gene = current_attributes[0][1]
			if current_gene in gene_dict.keys():
				if(gene_dict[current_gene] != current_strand):
					print_error(i, 'Found a strand that does not match its gene strand')
					return False
			else:
				gene_dict[current_gene] = current_strand
	return True


# Function check_overlap(v)
# Boolean function that checks wheter or not a list of sorted intervals contains elements that overlap
def check_overlap(v): 
	if len(v) == 1:
		return True
	for i in range(len(v) - 1):
		if v[i][1] >= v[i + 1][0]:
			return False
	return True


# Function check_transcript(transcript)
# transcript is a sequence of row of the same transcript 
# for those row we have already checked that the strand is ok
def check_transcript(transcript):
	current_attributes = list_attributes(transcript[0].split('\t')[8])
	current_gene = current_attributes[0][1]
	current_transcript = current_attributes[1][1]
	strand = transcript[0].split('\t')[6]
	print(current_gene)
	print(current_transcript)


	start_codons = []
	stop_codons = []
	ranges = []
	for row in transcript:
		elements = row.split('\t')
		start = elements[3]
		end = elements[4]
		feature = elements[2]
		if feature == 'start_codon':
			start_codons.append((int(start), int(end)))
		if feature == 'stop_codon':
			stop_codons.append((int(start), int(end)))
		if feature == 'CDS':
			ranges.append((int(start), int(end))) 
	print(start_codons)
	print(stop_codons)
	print(ranges)

	# If there is not a CDS do not controll anything else
	if len(start_codons) + len(stop_codons) + len(ranges) == 0:
		return True
	# If there is a start_codon or stop_codon there must be a CDS and viceversa
	if len(start_codons) + len(stop_codons) + len(ranges) != 0 and len(start_codons) * len(stop_codons) * len(ranges) == 0:
		print_error(' ', 'If there is a start_codon or end_codon there must be a CDS and viceversa in transcript ' + current_transcript)
		return False
	# Checking if the lenght of start_codon is 3
	lenght_start_codon = 0
	for range in start_codons:
		lenght_start_codon = lenght_start_codon + range[1] - range[0] + 1
	if lenght_start_codon % 3 != 0:
		print_error(' ', 'Lenght of start_codon must be a multiple of 3 in transcript ' + current_transcript)
		return False
	# Checking if the length of stop_codon is 3
	lenght_stop_codon = 0
	for range in stop_codons:
		lenght_stop_codon = lenght_stop_codon + range[1] - range[0] + 1
	if lenght_stop_codon % 3 != 0:
		print_error(' ', 'Lenght of stop_codon must be a multiple of 3 in transcript ' + current_transcript)
		return False
	start_codons = sorted(start_codons)
	stop_codons = sorted(stop_codons)
	ranges = sorted(ranges)
	# Checking that ranges do not overlap for start_codons 
	if check_overlap(start_codons) == False:
		print_error(' ', 'Start_codons overlap in transcript ' + current_transcript)
		return False
	# Checking that ranges do not overlap for stop_codons 
	if check_overlap(stop_codons) == False:
		print_error(' ', 'Stop_codons overlap in transcript ' + current_transcript)
		return False
	# Checking that ranges do not overlap for CDS ranges 
	if check_overlap(ranges) == False:
		print_error(' ', 'CDS ranges overlap in transcript ' + current_transcript)
		return False
	# Checking if start_codon is in a correct position 

	print("\n\n")


# Reading file's name and its lines
gtf_file_name = input()
with open(gtf_file_name, 'r') as gtf_input_file:
	gtf_file_rows = gtf_input_file.readlines()
# Checking strands for the same gene
if check_gene_strand(gtf_file_rows) == False:
	print_error('-', 'Impossibile to continue the validation bacause of this error')
	sys.exit(0)
# Group all the rows by gene and transcript
gene_transcript_dict = {}
different_transcripts = []
for i in range(len(gtf_file_rows)):
	row = gtf_file_rows[i]
	elements = row.split('\t')
	current_attributes = list_attributes(elements[8])
	current_gene = current_attributes[0][1]
	current_transcript = current_attributes[1][1]
	if (current_gene, current_transcript) in gene_transcript_dict.keys():
		current_index = gene_transcript_dict[(current_gene, current_transcript)]
		different_transcripts[current_index].append(row)
	else:
		gene_transcript_dict[(current_gene, current_transcript)] = len(different_transcripts)
		different_transcripts.append([row])

for transcript in different_transcripts:
	check_transcript(transcript)

# py validator.py ./tests/first_test.gtf