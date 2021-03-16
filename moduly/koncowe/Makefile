game: 
	$(CC) -ggdb main.c modes.c saveImage.c manageGenerations.c createNew.c helpCreate.c neighbor.c -Wall -pedantic -o game

runsbs: game
	./game --in simkinGun.txt --out output.txt -s f1 -n 20 --how Ms -m sbs
	rm -f game	
runfast: game
	./game --in plik.txt --out wunik.txt -s f2 -n 10 --how Ms -m fast
	rm -f game
