package com.xander.UNIT_5_File_Handling;

import java.io.*;
import java.util.HashSet;

public class UNIT_5_FileHandling {

   String reverseWord(String word) {
      StringBuilder revWord = new StringBuilder();
      for (int i = word.length() - 1; i >= 0; i--) {
         revWord.append(word.charAt(i));
      }
      return revWord.toString();
   } 

   Boolean isSpecialChar(String word) {
      for (int i = 0; i < word.length(); i++) {
         if (word.charAt(i) < 65 || word.charAt(i) > 122) {
            return true;
         }
      }
      return false;
   }

   public void display() {
      File f = new File("D://myfile.txt");
      System.out.println(f.exists());
      FileReader fr = null;
      FileWriter fw = null;

      try {
         fr = new FileReader(f);

         /* // read entire file
          *
          *    int i; 
          *    while(i = fr.read() != -1) {
          *       System.out.print((char) i);
          *    }
          */

         /* // count number of characters in the file
         *   
         *   int charCount = 0;
         *   while (fr.read() != -1) {
         *      charCount++;
         *   }
         *   System.out.println("Number of characters in the file: " + charCount);
         */

         /* //read number of lines
         *   int lineCount = 1;
         *   int i;
         *   while ((i = fr.read()) != -1) {
         *      if (i == '\n') {
         *         lineCount++;
         *      }
         *   }
         *
         *   System.out.println("Number of lines in the file: " + lineCount);
         */

         /* // read number of words
         *
         *   int i;
         *   int wordCount = 0;
         *
         *   while((i = fr.read() != 1  )) {
         *      if (i == ' ' || i == '\n') {
         *         wordCount++;
         *      }
         *   }
         *
         *   System.out.println("Number of words in the file: " + wordCount);
         */

         /* // read only numbers from the file
         *
         *  int i = 0;
         *  while((i = fr.read()) != -1) {
         *     if (i >= 48 && i <= 57) {
         *        System.out.print((char) i);
         *     }
         *  }
         */

         /* // reverse a sentence
         *
         *   int i;
         *   StringBuilder sentence = new StringBuilder();
         *   while ((i = fr.read()) != -1) {
         *      sentence.append((char) i);
         *   }
         *
         *   System.out.println("Original sentence: " + sentence);
         *
         *   String[] words = sentence.toString().split(" ");
         *   StringBuilder revSentence = new StringBuilder();
         *   
         *   for (String word : words) {
         *      revSentence.append(reverseWord(word) + " ");
         *   }
         *
         *   System.out.println("Original sentence: " + sentence);
         *   System.out.println("Reversed sentence: " + revSentence);
         */

         /* // remove special characters from a sentence
         *
         *   int i;
         *  StringBuilder sentence = new StringBuilder();
         *  while((i = fr.read()) != -1) {
         *     sentence.append((char) i);
         *  }        
         *   
         *   String[] words = sentence.toString().split(" ");
         *   StringBuilder newSentence = new StringBuilder();
         *   
         *   for(String word : words) {
         *      if (!isSpecialChar(word)) {
         *         newSentence.append(word + " ");
         *      } 
         *   }
         *
         *   String [] newWords = newSentence.toString().split(" ");
         *   
         *   for (String word : newWords) {
         *      System.out.print(word + " ");
         *   }
         */

         /* // count number of unique words in a sentence
         *   
         *   HashSet <String> words = new HashSet <String> ();
         *   StringBuilder sentence = new StringBuilder();
         *   int i;
         *   while ((i = fr.read()) != -1) {
         *      sentence.append((char) i);
         *   }
         *
         *   String[] wordsArr = sentence.toString().split(" ");
         *   for (String word : wordsArr) {
         *      words.add(word);
         *   }
         *
         *   System.out.println("Total number of Unique words: " + words.size());
         */

         /* // find the shortest word in a sentence
         *   StringBuilder sentence = new StringBuilder();
         *   int i;
         *   while ((i = fr.read()) != -1) {
         *      sentence.append((char) i);
         *   }
         *
         *   String[] words = sentence.toString().split(" ");
         *   String shortestWord = words[0];
         *
         *   for (String word : words) {
         *      if (word.length() < shortestWord.length()) {
         *         shortestWord = word;
         *      }
         *   }
         *
         *   System.out.println("Shortest word in the sentence: " + shortestWord);
         *
         */

         //wrting inbto a file

         fw = new FileWriter("D://myfile.txt");

         fw.write("Hello World");
         fw.write("Hello World");

      } catch (FileNotFoundException e) {
         System.out.println("File not found");
      } catch (Exception e) {
         e.printStackTrace();
      } 
      finally {
         try {
            fr.close();
         } catch (IOException e) {
            e.printStackTrace();
         }
      }
   }
}