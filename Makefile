# Name: Kenenth Chen
# UW Net ID: kennec7
# CSE 374 Homework 5 - Makefile
# 5/17/23
# Copyright [2023] <Kenneth Chen>
# Makefile -> the compilation insturction file that is required to run this file.

CC = gcc
CFLAGS = -g -Wall

all: t9

t9: tnine.o trie.o
	$(CC) $(CFLAGS) -o t9 tnine.o trie.o

tnine.o: tnine.c trienode.h
	$(CC) $(CFLAGS) -c tnine.c

trie.o: trie.c trienode.h
	$(CC) $(CFLAGS) -c trie.c

clean:
	rm -f t9 tnine.o trie.o

