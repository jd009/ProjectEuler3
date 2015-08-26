//
//  main.cpp
//  projectEuler3
//
//  Created by John D on 8/25/15.
//  Copyright (c) 2015 John D. All rights reserved.
//

#include <iostream>
#include <vector>
#include "math.h"

void crossOffNonPrimes(std::vector<bool>& flags, long long int prime)
{
   for(long long int multipleOfPrime = prime * prime; multipleOfPrime < flags.size(); multipleOfPrime += prime)
   {
      flags[multipleOfPrime] = false;
   }
}

long long int getNextPrime(std::vector<bool>& flags, long long int previousPrime)
{
   long long int nextPrime = previousPrime + 1;
   while(nextPrime < flags.size() && !flags[nextPrime])
   {
      nextPrime++;
   }
   return nextPrime;
}

long long int sieveOfEratosthenes(long long int numberOfInterest, int maximumLimitForPrimeGeneration)
{
   std::vector<bool> flags(maximumLimitForPrimeGeneration + 1, true);
   flags[0] = false;
   flags[1] = false;

   long long int currentPrime = 2;
   long long int largestPrime = 2;

   while(currentPrime <= maximumLimitForPrimeGeneration)
   {
      crossOffNonPrimes(flags, currentPrime);

      currentPrime = getNextPrime(flags, currentPrime);

      if(currentPrime >= flags.size())
      {
         break;
      }
      else
      {
         if(numberOfInterest % currentPrime == 0)
         {
            largestPrime = currentPrime;
         }
      }
   }

   return largestPrime;
}

int main(int argc, const char * argv[]) {
   //std::cout << "Test Case - Largest prime: " << sieveOfEratosthenes(13195, 10000) << std::endl;

   int sqroot = sqrt(600851475143);
   //std::cout << "sqr: " << sqroot << std::endl;
   std::cout << "Largest prime: " << sieveOfEratosthenes(600851475143, sqroot) << std::endl;
   return 0;
}

