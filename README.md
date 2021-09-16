# CPP

# Sparse Tables 
sparse tables are the best for the min/max/gcd query problem ( because we do not care if the intervals overlap ) 
but we cannot compute sum -> overlapping part will be double counted. 
also there must not be any updates/changes on the sequence to be able to use sparse table 
if there is an update/change in sequence, then we can use segment tree.



# Segment Trees

cout<< __builtin_popcount (4);  // this code gives 1 as output
