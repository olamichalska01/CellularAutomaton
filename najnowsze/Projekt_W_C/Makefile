game: 
	
	$(CC) -g Moduly/main.c Moduly/modes.c Moduly/saveImage.c Moduly/manageGenerations.c Moduly/createNew.c Moduly/helpCreate.c Moduly/neighbor.c -Wall -pedantic -o game
	
changeIN: 
	$(CC) -g Moduly/main.c Moduly/modes.c Moduly/saveImage.c Moduly/manageGenerations.c Moduly/createNew.c Moduly/helpCreate.c Moduly/neighbor.c -Wall -pedantic -o change -DIN='"./generacjeWyjsciowe/"'


runsbs: game
	./game --in smile.txt --out blabla.txt -s o15 -n 20 --how Ms -m sbs
	rm -f game
runfast: game
	./game --in starship.txt --out wunik.txt -s f5 -n 200 --how Ms -m fast
	rm -f game
nosave: game
	./game --in simkinGun.txt --out sofa.txt -n 2 --how Nf -m fast
	rm -f game

afterchange: changeIN
	./change --in blabla.txt --out newblabla.txt -n 40 --how Ms -m sbs
	rm -f change

usunWyjscie:
	rm generacjeWyjsciowe/*.txt 
usunObraz:
	rm obrazy/generation*
