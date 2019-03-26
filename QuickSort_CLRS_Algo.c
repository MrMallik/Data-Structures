
----------------------PARTITION PROCEDURE - THE HEART OF THE QUICKSORT ALGORITHM------------------------------------
                                                                                                                   |
  PARTITON(A[], int lo, int hi)
{
  x = A[hi]
  minLoc = -1
  
  for idx = lo to hi-1
      if A[idx]<=x
          minLoc++                                                                                                 |
          swap(&A[minLoc], &minLoc[idx])                                                                           |
    swap(&A[minLoc], &A[hi])                                                                                       |
    return (minLoc + 1)                                                                                            |
}                                                                                                                  |
                                                                                                                   |
                                                                                                                   |
                                                                                                                   |
                                                                                                                   |
                                                                                                                   |
                                                                                                                   |
                                                                                                                   |
                                                                                                                   |
                                                                                                                   |
                                                                                                                   |
---------------------------------------------------------------------------------------------------------------------


