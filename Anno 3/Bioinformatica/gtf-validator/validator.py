# @Author: Fabio Marchesi 
# GTF-validator 
# GTF syntax: <seqname> <source> <feature> <start> <end> <score> <strand> <frame> [attributes] [comments]

import re

# Validation part:
# Files and functions for the output of validation's results
correct_validation = True
validation = open("validation.txt", "w+")
def print_error(row, message):
	correct = False
	validation.write('Validation failed.\n')
	validation.write('Row ' + str(row) + ' : ' + message + '\n')


# Function check_source(rows)
# Boolean function that checks whether all the sources of a file are equal
def check_source(rows):
	correct = True
	for i in range(len(rows)):
		for j in range(len(rows)):
			if rows[i].split('\t')[1] != rows[j].split('\t')[1]:
				correct = False;
				print_error(j, 'Source does not match Source in ' + str(i) + '-th row')
	return correct


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


# Function check_attributes(s, i)
# Boolean function that checks whether the attributes are correct
# gene_id and transcript_id must be present
def check_attributes(s, i):
	elements = list_attributes(s)
	if elements[0][0] != 'gene_id':
		print_error(i, 'The first attribute (' + str(elements[0][0]) + ') must be "gene_id"')
		return False
	if elements[1][0] != 'transcript_id':
		print_error(i, 'The second attribute (' + str(elements[1][0]) + ') must be "Transcript_it"')
		return False
	return True


# Function check_row(row, i)
# Boolean function that checks whether the ros is correct
# All the elements of a gtf's file row are checked 
def check_row(row, i):
	elements = row.split('\t')

	# Checking the number of values 
	correct_number_of_values = len(elements) >= 9
	if correct_number_of_values == False:
		print_error(i, "Not enough arguments")
		return False

	# Checking the feature
	correct_feature = check_feature(elements[2], i) 

	# Checking start and end
	correct_start_end = check_start_end(elements[3], elements[4], i)

	# Checking the strand 
	correct_strand = check_strand(elements[6], i)

	# Checking the frame
	correct_frame = check_frame(elements[2], elements[7], i)

	# Checking the attributes
	correct_attributes = check_attributes(elements[8], i)

	

# Reading file's name and its lines
gtf_file_name = input()
with open(gtf_file_name, 'r') as gtf_input_file:
	gtf_file_rows = gtf_input_file.readlines()

# Checking if all sources are equal 
correct_sources = check_source(gtf_file_rows)

# Checking if all the strands are equal 
correct_strands = check_strands(gtf_file_rows) 

if correct_strands and correct_sources:
	for i in range(len(gtf_file_rows)):
		check_row(gtf_file_rows[i], i)
else:
	print_error(0, 'The given errors do not permit the validation of each row')

# Validation Veredict:
if correct_validation == True:
	validation.write("VALIDATION COMPLETED SUCCESSFULLY\n")

# py validator.py ./tests/first_test.gtf