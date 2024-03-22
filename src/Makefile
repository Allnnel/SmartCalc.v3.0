windows:
	gcc -c -fPIC model/*.c
	rm -rf view/src/main/resources/libs/libfunctions.dll
	cd view/src/main/resources/libs
	touch libfunctions.dll
	cd ../../../../../
	gcc -shared -o view/src/main/resources/libs/libfunctions.dll *.o
	rm *.o
	cd view/ && mvn clean install
	java -jar view/target/view-1.0-SNAPSHOT.jar
		
linux:
	gcc -c -fPIC model/*.c
	rm -rf view/src/main/resources/libs/libfunctions.so
	cd view/src/main/resources/libs
	touch libfunctions.so
	cd ../../../../../
	gcc -shared -o view/src/main/resources/libs/libfunctions.so *.o
	rm *.o
	cd view/ && mvn clean install
	java -jar view/target/view-1.0-SNAPSHOT.jar
		
mac:
	gcc -c -fPIC model/*.c
	rm -rf view/src/main/resources/libs/libfunctions.dylib
	cd view/src/main/resources/libs
	touch libfunctions.dylib
	cd ../../../../../
	gcc -shared -o view/src/main/resources/libs/libfunctions.dylib *.o
	rm *.o
	cd view/ && mvn clean install
	java -jar view/target/view-1.0-SNAPSHOT.jar

open:
	java -jar view/target/view-1.0-SNAPSHOT.jar

clean:
	cd view/ && mvn clean
	rm data.ser libfunctions.dylib libfunctions.so libfunctions.dll

test:
	cd model/ && make test
	cd model/ && make clean
