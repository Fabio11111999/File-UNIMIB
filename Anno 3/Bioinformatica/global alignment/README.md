## Documentation 
C Program that, given 2 strings, computes their best global alignments using [BLOSUM62](https://en.wikipedia.org/wiki/BLOSUM) as score substitution matrix. The algorithm has time complexity equal to **O(NK)** where *N* is the length of the shortest string in input and *K* is the number of indel in the best alignment.
### Input Format 
Four arguments: ```n```, ```s```, ```m``` and ```t``` separated by a space:
- ```n``` is the length of the first string.
- ```s``` is the first string, its characters must in ```{A,R,N,D,C,Q,E,G,H,I,L,K,M,F,P,S,T,W,Y,V,B,Z,X}```.
- ```m``` is the length of the second string.
- ```t``` is the second string, its characters must in ```{A,R,N,D,C,Q,E,G,H,I,L,K,M,F,P,S,T,W,Y,V,B,Z,X}```.

### Output Format
The score of the best global alignment and the 2 strings that produce it. **INDEL** charcater is represented using '_'. 

Check ```documentation.pdf``` for infos about the implementation.
