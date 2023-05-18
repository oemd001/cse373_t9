/* 
   Name: Kenneth Chen
   UW Net ID: kennec7
   CSE 374 Homework 5 - trie
   5/17/23
   Copyright [2023] <Kenneth Chen>
   tnine (t9) -> Defines functions for managing a trie data structure that represents a T9 predictive text dictionary. 
   It provides functionality to create trie nodes, convert words to T9 key sequences, insert words into the trie, 
   search for words based on T9 sequences, and free the memory allocated to the trie.
*/

#include "trienode.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function *createNode()
// This function creates a new trie node, initializing its word and children pointers to NULL.
TrieNode *createNode() {
  TrieNode *node = (TrieNode *)malloc(sizeof(TrieNode));
  node->word = NULL;
  for (int i = 0; i < SIZE; i++) {
    node->children[i] = NULL;
  }
  return node;
}

/* function *wordToT9(char *word)
/ args: *word (char)
/ Takes a word as input and converts it to T9 representation. 
/ It maps each character in the word to its corresponding T9 digit and returns the 
/ T9 representation as a string. */
char *wordToT9(char *word) {
  static char t9[27] = "22233344455566677778889999";
  static char buffer[MAX_WORD_SIZE + 1];
  int i, len = strlen(word);

  for (i = 0; i < len; i++) {
    if (word[i] >= 'a' && word[i] <= 'z') {
      buffer[i] = t9[word[i] - 'a'];
    }
  }
  buffer[i] = '\0';

  return buffer;
}

/* function insert(TrieNode *root, const char *key, const char *word)
/ args: *root (TrieNode), *key (char), *word (char)
/ used to insert a word into a Trie data structure. It takes the root of the Trie, a key, 
/ and the word to be inserted. It traverses the Trie, creating new nodes 
/ if necessary, and finally assigns the word to the last node of the key. */
void insert(TrieNode *root, const char *key, const char *word) {
  TrieNode *curr = root;
  for (int i = 0; key[i] != '\0'; i++) {
    int index = key[i] - ASCII_NUM_START;
    if (!curr->children[index]) {
      curr->children[index] = createNode();
    }
    curr = curr->children[index];
  }

  if (curr->word) {
    TrieNode *temp = curr;
    while (temp->children[10]) {
      temp = temp->children[10];
    }
    temp->children[10] = createNode();
    temp = temp->children[10];
    temp->word = strdup(word);
  } else {
    curr->word = strdup(word);
  }
}

/* function *search(TrieNode *root, const char *key)
/ args: *root (TrieNode), *key (char)
/ Used to search for a word in the Trie based on a given key. 
/ It takes the root of the Trie and the key to search. 
/ It traverses the Trie according to the characters in the 
/ key and returns the node that matches the key. If a word is 
/ found, it prints the word; otherwise, it displays a "Not found" message.
*/
TrieNode *search(TrieNode *root, const char *key) {
  TrieNode *curr = root;
  for (int i = 0; key[i] != '\0'; i++) {
    if (key[i] == '#') {
      if (!curr->children[10]) {
        printf("There are no more T9onyms\n");
        return NULL;
      }
      curr = curr->children[10];
    } else {
      int index = key[i] - ASCII_NUM_START;
      if (!curr->children[index]) {
        printf("Not found in current dictionary.\n");
        return NULL;
      }
      curr = curr->children[index];
    }
  }

  if (curr->word) {
    printf("'%s'\n", curr->word);
  } else {
    printf("Not found in current dictionary.\n");
  }

  return curr;
}

/* function *freeTrie(TrieNode *root)
/ args: *root (TrieNode)
/ Frees the TrieNode datastructure. 
*/
void freeTrie(TrieNode *root) {
  if (!root)
    return;
  for (int i = 0; i < SIZE; i++) {
    if (root->children[i]) {
      freeTrie(root->children[i]);
    }
  }
  if (root->word) {
    free(root->word);
  }
  free(root);
}

