musicalLL: createPlayList.o addNewSong.o playPlayList.o playSongGivenId.o playSongGivenName.o countNotesInASong.o deleteASongGivenId.o deletePlayList.o mainA3.o helper.o
	gcc createPlayList.o addNewSong.o playPlayList.o playSongGivenId.o playSongGivenName.o countNotesInASong.o deleteASongGivenId.o deletePlayList.o mainA3.o helper.o -o bin/musicalLL
createPlayList.o: src/createPlayList.c include/givenA3.h include/helper.h
	gcc -std=c99 -Wall -c src/createPlayList.c
addNewSong.o: src/addNewSong.c include/givenA3.h include/helper.h
	gcc -std=c99 -Wall -c src/addNewSong.c
playPlayList.o: src/playPlayList.c include/givenA3.h
	gcc -std=c99 -Wall -c src/playPlayList.c
playSongGivenId.o: src/playSongGivenId.c include/givenA3.h
	gcc -std=c99 -Wall -c src/playSongGivenId.c
playSongGivenName.o: src/playSongGivenName.c include/givenA3.h
	gcc -std=c99 -Wall -c src/playSongGivenName.c
countNotesInASong.o: src/countNotesInASong.c include/givenA3.h
	gcc -std=c99 -Wall -c src/countNotesInASong.c
deleteASongGivenId.o: src/deleteASongGivenId.c include/givenA3.h
	gcc -std=c99 -Wall -c src/deleteASongGivenId.c
deletePlayList.o: src/deletePlayList.c include/givenA3.h
	gcc -std=c99 -Wall -c src/deletePlayList.c
mainA3.o: src/mainA3.c include/givenA3.h
	gcc -std=c99 -Wall -c src/mainA3.c
helper.o: src/helper.c include/givenA3.h include/helper.h
	gcc -std=c99 -Wall -c src/helper.c
clean:
	rm *.o bin/musicalLL