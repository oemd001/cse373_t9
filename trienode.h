/* 
   Name: Kenneth Chen
   UW Net ID: kennec7
   CSE 374 Homework 5 - trienode
   5/17/23
   Copyright [2023] <Kenneth Chen>
   trienode -> header file that will be used by trie.c and tnine.c
*/


#ifndef TRIENODE_H
#define TRIENODE_H

#include <stdio.h>

#define SIZE 11
#define MAX_WORD_SIZE 50
#define ASCII_NUM_START 48

// trieNode is one node in an 11-tree
typedef struct TrieNode {
  char *word;
  struct TrieNode *children[SIZE];
} TrieNode;

// Function declarations
TrieNode *createNode();
char *wordToT9(char *word);
void insert(TrieNode *root, const char *key, const char *word);
TrieNode *search(TrieNode *root, const char *key);
void freeTrie(TrieNode *root);

#endif

