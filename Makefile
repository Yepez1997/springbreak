
all: submission.c test-submission.py
	gcc -O2 submission.c -lm -std=c99 -o submission.out
	python3 test-submission.py submission.out


cases: make-cases.py
	python make-cases.py