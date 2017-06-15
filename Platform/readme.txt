1. Come eseguire la compilazione per le varie piattaforme

Considerare che il Visual Studio 2010 non accetta file con estensione ".c", allo stesso modo
l'ambiente MPLab X con compilatore XC8 non accetta la compilazione di file con estensione ".cpp".

Quindi prima di aprire il progetto nei rispettivi ambienti di sviluppo accertarsi che l'estensione
dei file sia corretta, a tal proposito sono predisposti due file batch (nel caso di ambiente windows)
che in auotomatico rinominano i file con estensione ".c" a file con estensione ".cpp" e viceversa

La seconda operazione necessaria per una corretta compilazione è quella di selezionare il compilatore
in uso nel file "msPlatform.h" presente nella directory "../emphiOS/Include/Driver"