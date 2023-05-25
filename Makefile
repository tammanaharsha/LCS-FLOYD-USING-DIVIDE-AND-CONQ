override CC=gcc-11.3.0
override CXX=g++-11.3.0
all: lcs floyd

lcs: tammana_harsha_pa3_lcs.o
	g++ tammana_harsha_pa3_lcs.o -o lcs

floyd: tammana_harsha_pa3_floyd.o
	g++ tammana_harsha_pa3_floyd.o -o floyd

tammana_harsha_pa3_lcs.o: tammana_harsha_pa3_lcs.cpp
	g++ -c tammana_harsha_pa3_lcs.cpp

tammana_harsha_pa3_floyd.o: tammana_harsha_pa3_floyd.cpp
	g++ -c tammana_harsha_pa3_floyd.cpp

clean:
	rm -rf *o lcs floyd