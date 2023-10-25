I chose to do this the way I did for memory constraint and processing time reasons.
For example: making a 2d array would consume 5,931,610*sizeof(double) bytes. My approach uses 
at it's maximum 20,668*sizeof(double) bytes by utilizing 1d arrays. 
Additionally, my approach will be faster because it is caching the averages for the movies and users
for O(1) lookup speeds. It does not have to recalculate the averages each time a request is made. 
