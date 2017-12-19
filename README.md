# RNAchain_reconstruction

<p align="left">The genetic information is stored by DNA and RNA chains. AN RNA chain is a sequence of bases whose length varies with the species. Each base can be one of the four: A = adenine, U = uracil, C = cytosine and G = guanine.
The problem of knowing the composition of RNA chain is still quite open as the sequences are extremely long.</p>

This program implements an algorithm that reconstructs the RNA chain out of two sets of fragments. 
 
[Full project description](https://github.com/olgakent/RNAchain_reconstruction/blob/master/rnachain.pdf)

### Example

Input:
```
    Enter G-enzyme fragments:AUCG,AUG,G,CU,ACUAUACG
    AU C G
    AU G
    G
    C U
    AC U AU AC G
    Enter UC-enzyme fragments:GGAC,U,AU,GAU,C,U,AC,GC,AU
    G G AC
    U
    AU
    G AU
    C
    U
    AC
    G C
    AU
```
Output:

```
    Possible chains:
    AUCGGACUAUACGAUGCU
    AUCGAUGGACUAUACGCU
    AUGGACUAUACGAUCGCU
    AUGAUCGGACUAUACGCU
```
<p align="left">Multigraph for the given fragments where each fragment becomes an arc from a vertex labeled with the beginning of the fragment to a vertex labeled with the end of the fragment:</p>
<p align="center"><img src="./multigraph.png" alt="multigraph" width=50%></p>

### Example
Input:
```
    Enter G-enzyme fragments:AG,UCAG,UG,AG,CA
    AG
    U C AG
    U G
    AG
    C A
    Enter UC-enzyme fragments:AGU,C,AGU,GAGC,A
    AG U
    C
    AG U
    G AG C
    A
```
Output:
```
Possible chains:
AGUCAGUGAGCA
```
