//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.io.*;
import java.lang.*;

class Geeks
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        while(t-- > 0)
        {
            int n =sc.nextInt();
            int arr[] = new int[n];
            
            for(int i = 0; i < n; i++)
             arr[i] = sc.nextInt();
             
           System.out.println(new Solution().majorityElement(arr, n)); 
        }
    }
}
// } Driver Code Ends

//User function Template for Java

class Solution
{
    static int majorityElement(int a[], int size)
    {
        // your code here
        if(size == 0){return -1;}
        if(size == 1){return a[0];}
         if(size == 2 && a[0] != a[1])
        {
            return -1;
        }
        if(size ==3 && a[0] != a[1] && a[1]  != a[2])
        {
            return -1;
        }
        
        Map<Integer, Integer> freq = new HashMap<>();
        int half = size/2;
        for(int inx = 0; inx < size; inx++)
        {
            freq.put(a[inx], freq.getOrDefault(a[inx], 0)+1);
        }
        
      if(freq.size() == 2)
      {
          MajorElem maj = new MajorElem(0, 0);
          int maxSoFar = 0;
            for(Integer key: freq.keySet())
           {
               if(freq.get(key) > maj.maxSoFar)
               {
                   maj = new MajorElem(freq.get(key), key);
               }
            
           } 
           if(maj.maxSoFar == half){return -1;}
           else{
               return maj.key;
           }

        }
  
           for(Integer key: freq.keySet())
           {
               if(freq.get(key) > half)
                {
                    return key;
                }
           }
        return -1;
        
        
    }
}

class MajorElem
{
    int maxSoFar;
    int key;
    MajorElem(int m, int k)
    {
        this.maxSoFar = m;
        this.key =k;
    }
    
}
