____________________________

LIFE SIMULATOR, versione 1.3
2010
____________________________

Autori:

Aliaj Denajda
Camoriano Raffaello
Cerruti Giulio

____________________________

Descrizione:

Il programma è un simulatore semplificato del Conway's Game of Life,
scritto in linguaggio C++.
Vi sono alcuni scenari già pronti all'interno (un flying kite e un
oscillatore), nonchè un generatore casuale della matrice iniziale.

Il programma è anche in grado di acquisire uno stato iniziale da
un opportuno file .csv ([0..29][0..29]), vi consigliamo di provare
quelli già presenti nella cartella "csv".

Come acquisire un .csv? Da linea di comando, dopo 'Life.exe' digitare
la diractory del .csv desiderato e premere invio. Il programma partirà
in "modalità parsing".

ESEMPIO:  "Life.exe csv\kite.csv"

Se non si specifica un file .csv, il programma partirà in "modalità semplice"
permettendo di utilizzare le funzionalità precedentemente descritte.

Le matrici inserite devono essere 30 X 30 per ottenere una visualizzazione
corretta, perciò è necessario prestare attenzione nella costruzione di
un nuovo file .csv.

N.B. La visualizzazione è basata sulla semplice interfaccia a caratteri
(il refresh è piuttosto lento purtroppo),ed è preferibile lanciare il
programma in modalitè a schermo intero per vedere bene l'intera matrice.
